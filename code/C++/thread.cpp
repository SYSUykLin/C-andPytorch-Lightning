#include <iostream>
#include <thread>
#include <algorithm>
#include <functional>

static bool is_finishing = false;

void DoWork()
{
    while(!is_finishing)
    {
        std::cout << "working" << std::endl;
    }
}

int main()
{   
    // 开发一个新线程执行DoWork函数
    std::thread worker(DoWork);

    std::cin.get();
    is_finishing = true;

    // 等待线程完成，主线程会等待这个worker线程完成
    worker.join();
    
    // 一维数组
    int* array = new int[50];
    // 二维数组
    int** a2d = new int*[50];
    for(int i = 0; i < 50; i++)
    {
        a2d[i] = new int[50];
    }
    
    std::vector<int> values = {3, 5, 4, 2, 1};
    std::sort(values.begin(), values.end(), std::greater<int>());
    for(int value : values)
    {
        std::cout << value << std::endl;
    }
}