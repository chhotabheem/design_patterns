#include <iostream>
using namespace std;

class Vehicle
{
public:
    virtual void print() const = 0;
    virtual ~Vehicle() {}
};

class Bus : public Vehicle
{
public:
    virtual void print() const override { cout << "im driving bus" << endl; }
};

class Tractor : public Vehicle
{
public:
    virtual void print() const override { cout << "im driving tractor" << endl; }
};

class Car : public Vehicle
{
public:
    virtual void print() const override { cout << "im driving car" << endl; }
};

class VehicleFactory
{
public:
    virtual Vehicle *create() = 0;
    virtual ~VehicleFactory() {}
};

class CarFactory : public VehicleFactory
{
public:
    virtual Vehicle *create() override { return new Car; }
};

class TractorFactory : public VehicleFactory
{
public:
    virtual Vehicle *create() override { return new Tractor; }
};

class BusFactory : public VehicleFactory
{
public:
    virtual Vehicle *create() override { return new Bus; }
};

int main()
{
    VehicleFactory *factory = new BusFactory;
    Vehicle *vehicle = factory->create();
    vehicle->print();
    delete vehicle;
    delete factory;

    factory = new CarFactory;
    vehicle = factory->create();
    vehicle->print();
    delete vehicle;
    delete factory;

    factory = new TractorFactory;
    vehicle = factory->create();
    vehicle->print();
    delete vehicle;
    delete factory;


    return 0;
}
