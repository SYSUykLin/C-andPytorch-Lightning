// 命令行使用g++ 文件名.cpp编译
// 然后命令行文件名.exe运行

// 第一句是预处理，#之后的语句都是预处理
// 之所以叫做预编译，是因为他们在编译之前就已经被处理了
// include是意思是找到一个文件，这里是找到iostream这个文件，然后将这个文件的所有内容拷贝到现在的文件里面
// 这些文件也称为头文件
#include <iostream>
#include "my.h"

// 如果找不到这个函数在其他文件的位置，就会出现链接报错
// int Log(const char* message);

void newtest();

int Multiply(int a, int b)
{
    return a * b;
}

// 任何一个C++的程序都需要main函数，是程序的入口
// 注意到mian函数返回了一个整数，当你什么也不写的时候默认返回0
// 但这只对main函数适用，对于其他函数是一定要有对应的返回值
int main()
{
    // <<是一个重载运算符
    // 将hello world推送到cout，然后打印到控制台上，endl是输出回车
    
    Log("test");
    newtest();
    test();
    
    // 4 bytes和编译器相关，大小是限制是，所以变量的数值是被限制的。-2b -> 2b
    // 4字节，每个字节8位，所以我们有一共有32位。如果是有符号数，我们只能存储-2^31 -> 2^31，因为有一位需要拿出来做符号。
    int variable = 8;
    // 无符号数就可以表示0 -> 2^32
    unsigned int variable_unsigned = 17;

    // char(1字节), short(2字节), int(4字节)，long(4字节)，long long(8字节)，long int(8字节)
    std::cout << variable << std::endl;

    char a = 'A';
    char b = 65;
    std::cout << a << "," << b << std::endl;
    std::cout << sizeof a << std::endl;

    std::cout << "Condition" << std::endl;

    int x = 5;
    bool comparisonResult = x == 5;
    if (comparisonResult)
    {
        std::cout << "true" << std::endl;
    }

    const char * s = "Neural Radiance Field";
    char arr[] = "Neural Radiance Field";
    std::cout << s << std::endl;
    std::cout << arr << std::endl;

    char * p = arr;
    std::cout << static_cast<void *>(p) << static_cast<void *>(&arr[0]) << std::endl;
    


    // get函数是等待我们输入，也是一个暂停函数 
    std::cin.get();
}

// 1.将头文件复制到当前文件中
// 2.编译，将所有的C++代码变成机器代码
// 3.编译完成后就出现了.o文件   
// 4.链接就是将所有的o文件拼接起来变成一个可执行exe文件