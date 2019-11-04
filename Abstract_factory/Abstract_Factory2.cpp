#include <iostream>
using namespace std;

class Product
{
public:
    virtual void print() const = 0;
    virtual ~Product() {}
};

class Cake : public Product
{
public:
    virtual void print() const override { cout << "this is cake" << endl; }
};

class Ice : public Product
{
public:
    virtual void print() const override { cout << "this is Ice" << endl; }
};

class AbstractFactory
{
public:
    virtual Product *create_product() = 0;
    virtual ~AbstractFactory() {}
};

class CakeFactory : public AbstractFactory
{
public:
    virtual Product *create_product() override { return new Cake; }
};

class IceFactory : public AbstractFactory
{
public:
    virtual Product *create_product() override { return new Ice; }
};

int main()
{
    AbstractFactory *factory = new IceFactory;
    Product *prod = factory->create_product();
    prod->print();
    delete prod;
    delete factory;

    factory = new CakeFactory;
    prod = factory->create_product();
    prod->print();
    delete prod;
    delete factory;
}