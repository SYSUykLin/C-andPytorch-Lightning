import torch
from pytorch_lightning import LightningModule
from torchvision.datasets import MNIST
from opts import get_opts
from torch.nn import functional as F
from torch.utils.data import random_split, DataLoader
from torch.optim.lr_scheduler import CosineAnnealingLR


class MINISTSystem(LightningModule):
    def __init__(self, hparams):
        super().__init__()
        self.save_hyperparameters(hparams)
        
        self.net = torch.nn.Sequential(
            torch.nn.Linear(28 * 28, self.hparams.hidden_dim),
            torch.nn.ReLU(True),
            torch.nn.Linear(self.hparams.hidden_dim, 10)
            )
        
    def forward(self, x):
        '''
        x: (B, 28, 28) batch of images
        '''
        x = x.flatten()  # (B, 28 * 28)
        return self.net(x)
    
    def prepare_data(self):
        '''
        通常是指下载数据，只执行一次
        '''
        MNIST(self.hparams.root_dir, train=True, download=True)
        MNIST(self.hparams.root_dir, train=False, download=True)

    def setup(self, stage=None):
        '''split the train and valid'''
        dataset = MNIST(self.hparams.data_dir, train=True, download=False)
        # train: 6w, val: 5k
        train_length = len(dataset)
        self.train_dataset, self.val_train = random_split(dataset, [train_length - self.hparams.val_size, self.hparams.val_size])
        
    def train_dataloader(self):
        # 一般num_worker就是设置成4xGPU的数量
        return DataLoader(self.train_dataset, shuffle=True, num_workers=4, batch_size=self.hparams.batch_size, pin_memory=True)
    
    def val_dataloader(self):
        return DataLoader(self.val_dataset, shuffle=False, num_workers=4, batch_size=1, pin_memory=True)
    
    def training_step(self, batch, batch_idx):
        images, labels = batch
        labels_predicted = self(images)
        loss = F.cross_entropy(labels_predicted, labels)
        self.log('train/loss', loss, prog_bar=True)
        return loss
    
    def validation_step(self, batch, batch_idx):
        images, labels = batch
        logits_predicted = self(images)        
        loss = F.cross_entropy(logits_predicted, labels)
        
        log = {'val_loss': loss}
        return log
    
    def on_validation_epoch_end(self, outputs):
        mean_loss = torch.stack([x['val_loss'] for x in outputs]).mean()

        self.log('val/loss', mean_loss, prog_bar=True)

    def configure_optimizers(self):
        optimizer = torch.optim.Adam(self.parameters(), lr=self.hparams.learning_rate)
        schedular = CosineAnnealingLR(optimizer=optimizer, 
                                      T_max=self.hparams.num_epochs, 
                                      eta_min = self.hparams.learning_rate/1e2)
        return [optimizer], [schedular]

if __name__ == '__main__':
    hparams = get_opts()
    ministSystem = MINISTSystem(hparams=hparams)
    