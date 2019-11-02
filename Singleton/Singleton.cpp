#include <iostream>
using namespace std;
class Singleton
{
    Singleton() {}
    Singleton(const Singleton& obj) {}
    Singleton &operator=(const Singleton& obj) { return *this; }
    static Singleton *instance;

public:
    static Singleton *get_instance()
    {
        if (!instance)
        {
            instance = new Singleton;
        }
        return instance;
    }
    void print() { cout << "printing inside Singleton." << endl; }
};
Singleton *Singleton::instance = nullptr;

int main()
{
    auto singleton_ptr = Singleton::get_instance();
    singleton_ptr->print();
    return 0;
}