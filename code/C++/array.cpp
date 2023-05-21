#include <iostream>

template<typename T, size_t S>
class Array
{   
    public:
        constexpr int Size() const
        {
            return 5;
        }

    T& operator[](int index)
    {
        return m_Data[index];
    }
    

    private:
        T m_Data[S];
};

int main()
{
    int size = 5;
    Array<int, 5> data;
}