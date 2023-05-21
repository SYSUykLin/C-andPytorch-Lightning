#include <iostream>
#include <array>
void hello_world(int a)
{
    std::cout << "Hello world!" << a << std::endl;
}

template <typename T>
void print_array(const T& array, void (*prt_array)(int))
{
    for(int i = 0; i < array.size(); i++)
    {
        prt_array(array[i]);
    }
}

int main()
{
    typedef void (*fun_name) (int);
    fun_name fun = hello_world;
    std::array<int, 6> arr = {0, 1, 2, 3, 4, 5};
    print_array(arr, hello_world);
} 