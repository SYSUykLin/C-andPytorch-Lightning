#include <iostream>
#include <string>

void* operator new(size_t size)
{
    return malloc(size);
}

class Object
{
    int x, y, z;
};

class Singleton
{
    public:
        Singleton(const Singleton&) = delete;

        static Singleton& Get()
        {
            return s_Instance;
        }
    private:
        Singleton() {}
        static Singleton s_Instance;
};

Singleton Singleton::s_Instance;

int& GetValue(){
    static int value = 10;
    return value;
}

int main()
{
    auto& s = Singleton::Get();

    std::string name = "blue";

    Object* obj = new Object();
    
    // i是左值，10是右值    
    int i = 10;

    std::string a = "sjkdf";
    std::string b = "aksla";
    std::string c = a + b;
    a + b;
}