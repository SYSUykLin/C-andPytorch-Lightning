#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <array>

#define LOG(x) std::cout << x << std::endl;

#define WAIT std::cin.get()

class Vector3
{
    public:
        float x, y, z;
};

template<typename T, int N>
class Array
{
    private:
        T m_Array[N];
    public:
        int GetSize() const
        {
            return N;
        }
};

class String
{
    private:
        char* m_Buffer;
        unsigned int m_Size;
    public:
        String(const char* p)
        {
           this->m_Size = strlen(p);
           this->m_Buffer = new char[this->m_Size + 1];
           memcpy(m_Buffer, p, this->m_Size + 1);
        }

        String(const String& other): m_Size(other.m_Size)
        {
           this->m_Size = strlen(other.m_Buffer);
           this->m_Buffer = new char[this->m_Size + 1];
           memcpy(m_Buffer, other.m_Buffer, this->m_Size + 1);
        }
        ~String()
        {
            delete[] m_Buffer;
        }
        
        // 声明为友元重载，可以访问私有变量
        friend std::ostream& operator<<(std::ostream& os, const String&);
};

std::ostream& operator<<(std::ostream& os, const String& string)
{ 
    os << string.m_Buffer;
    return os;
}

class Entity
{
    public:
        Entity()
        {
            std::cout << "Created Entity!" << std::endl;
        }
        ~Entity()
        {
            std::cout << "Destroyed Entity!" << std::endl;
        }
};

template<typename T> void print(T value)
{
    std::cout << value << std::endl;
}

template<typename T> void print_array(const T& value) 
{
    for(int i = 0; i < value.size(); i++)
    {
        LOG(value[i]);
    }
}

int main()
{
    {
        // std::unique_ptr<Entity> entity(new Entity());
        // 这种方式最安全
        std::unique_ptr<Entity> entity = std::make_unique<Entity>(); 
    }

    {   
        std::shared_ptr<Entity> entity0;
        {
            std::shared_ptr<Entity> entity1 = std::make_shared<Entity>();
        }
        
    }

    int a = 3;
    int b = a;

    String string = "new code";
    String second = string;
    std::cout << string << std::endl;

    int offset = (long long)(&(((Vector3*)nullptr)->z));
    std::cout << offset << std::endl;

    print(5);
    print("cahjks");

    std::array<int, 5> data_array = {0, 1, 2, 3, 4};
    print_array(data_array);
     
}
