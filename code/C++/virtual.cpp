#include <iostream>
#include <string>
#define LOG(x) std::cout << x << std::endl
class Entity{
public:
    virtual void printName(){
        LOG("Entity");
    }
};

class player : public Entity{
    public:
     void printName() override {
        LOG("Player");
     }
};

void testName(Entity* entity){
    entity->printName();
}

int main()
{
    Entity* entity = new Entity();
    Entity* ply = new player();
    testName(entity);
    testName(ply);
}