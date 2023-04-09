import argparse


def get_opts():
    parser = argparse.  ArgumentParser()
    parser.add_argument('--root_dir', type=str, required=True, help='Root directory')
    parser.add_argument('--hidden_dim', type=int, default=128, help="number of hidden dimensions")
    parser.add_argument("--val_size", type=int, default=5000, help='size of the validation set')
    parser.add_argument("--batch_size", type=int, default=256, help="size of the batchsize")
    parser.add_argument("--learning_rate", type=float, default=1e-4, help='learning rate')
    parser.add_argument('--num_epochs', type=int, default=10, help='number of epochs')
    return parser.parse_args()