#include <iostream>
using namespace std;

class Person
{
public:
    virtual bool is_allowed() const = 0;
};

class Member : public Person
{
public:
    virtual bool is_allowed() const override { return true; }
};

class Guest : public Person
{
public:
    virtual bool is_allowed() const override { return false; }
};

class Proxy
{
    Person *m_person;

public:
    Proxy(Person *person) : m_person(person) {}
    bool get_access() { return m_person->is_allowed(); }
};

int main()
{
    Proxy proxy1(new Guest);
    cout << "is permitted: " << boolalpha << proxy1.get_access() << endl;
    Proxy proxy2(new Member);
    cout << "is permitted: " << boolalpha << proxy2.get_access() << endl;
    return 0;
}
