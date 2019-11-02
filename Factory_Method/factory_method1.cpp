#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void whoami() = 0;
    virtual ~Animal(){};
};

class Dog : public Animal
{
public:
    virtual void whoami()
    {
        cout << "Im angry dog" << endl;
    }
};

class Elephant : public Animal
{
public:
    virtual void whoami()
    {
        cout << "Im mighty elephant" << endl;
    }
};

class Lion : public Animal
{
public:
    virtual void whoami()
    {
        cout << "Im king of forest" << endl;
    }
};

enum class AnimalType
{
    Lion,
    Elephant,
    Dog
};

class AnimalFactory
{
public:
    static Animal *create_animal(AnimalType type)
    {
        switch (type)
        {
        case AnimalType::Dog:
            return new Dog;
        case AnimalType::Elephant:
            return new Elephant;
        case AnimalType::Lion:
            return new Lion;
        default:
            return nullptr;
        }
        return nullptr;
    }
};

int main()
{
    Animal *animal_ptr = AnimalFactory::create_animal(AnimalType::Lion);
    animal_ptr->whoami();
    delete animal_ptr;
    animal_ptr = AnimalFactory::create_animal(AnimalType::Elephant);
    animal_ptr->whoami();
    delete animal_ptr;
    animal_ptr = AnimalFactory::create_animal(AnimalType::Dog);
    animal_ptr->whoami();
    delete animal_ptr;
}
