#include <iostream>
#include <string>
#include <tuple>

static uint32_t s_AllocCount = 0;
void* operator new(size_t size)
{
    s_AllocCount ++;
    std::cout << "Alloc count: " << s_AllocCount << std::endl;
    return malloc(size);
}

std::tuple<std::string, int> CreatePerson()
{
    return {"LY", 24};
}

void printStr(const std::string& name)
{
    std::cout << name << std::endl;
}

int main()
{
    // auto person = CreatePerson();
    // std::string& name = std::get<0>(person);
    // int age = std::get<1>(person);

    // std::string name;
    // int age;
    // std::tie(name, age) = CreatePerson();

    // auto[name, age] = CreatePerson();

    // std::string name = "hajksdhjkkqwey";
    const char* name = "hajksdhjkkqwey"; 
    // std::string first = name.substr(0, 3);
    // std::string second = name.substr(4, 9);

    std::string_view first(name, 3);
    std::string_view second(name, 4);
    printStr(name);

}