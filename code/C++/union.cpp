#include <iostream>

struct Vector
{
    float x, y;
};

struct test
{
   union
   {
     struct
     {
        float a, b, c, d;
     };

     struct 
     {
        Vector v1, v2;
     };
     
     
   };
   
};

class Base
{
    public:
        Base() {std::cout << "Base" << std::endl;}
        virtual ~Base() {std::cout << "Delete Base" << std::endl;}
        virtual void print() {}
};

class Derived : public Base
{
    public:
        Derived() {std::cout << "Derived" << std::endl;}
        ~Derived() {std::cout << "Delete Derived" << std::endl;}
};

class Derived2 : public Base
{
    public:
        ~Derived2() {std::cout << "Delete Derived2" << std::endl;}
}; 

int main()
{

      Base* B = new Derived();
      Base* C = new Derived2();

      Base* D = new Base();
      Derived2* E = dynamic_cast<Derived2*>(D);

      std::cout << E << std::endl;
      
      if (dynamic_cast<Derived*>(D))
      {

      }

      delete B;
      delete C;

    
}