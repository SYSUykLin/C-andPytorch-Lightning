#include <iostream>
#include <cstring>

#define LOG(x) std::cout << x << std::endl

enum levels{
    A, B, C, D, E, F, G, H, I, J, K
};

void Increment(int* value)
{
    (*value) ++;
}

extern int b;

int main()
{   
    
    LOG(A);
    levels::A;

    int var = 8;
    // 定义一个无效指针
    void* ptr = nullptr;
    // 得到变量的地址
    ptr = &var;

    char* buffer = new char[8];
    memset(buffer, 0, 8);
    delete[] buffer;

    int a = 5;
    int& ref = a;
    ref = 90;
    LOG(a);
    
    Increment(&a);
    LOG(++b);

}