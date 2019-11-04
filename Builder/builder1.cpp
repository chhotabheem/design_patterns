#include <iostream>
#include <string>
using namespace std;

class Bike
{
    string m_name;
    int m_milege;
    int m_price;
    int m_max_speed;

public:
    void set_max_speed(int speed) { m_max_speed = speed; }
    void set_price(int price) { m_price = price; }
    void set_milege(int milege) { m_milege = milege; }
    void set_name(string name) { m_name = name; }
    void showspecs() const
    {
        cout << "name: " << m_name << endl;
        cout << "price: " << m_price << endl;
        cout << "milege: " << m_milege << endl;
        cout << "max speed: " << m_max_speed << endl;
    }
};

class Builder
{
protected:
    Bike *m_bike = new Bike;

public:
    virtual void design_model() = 0;
    virtual void define_speed() = 0;
    virtual void define_price() = 0;
    virtual void define_milege() = 0;
    virtual Bike *get_bike() { return m_bike; }
};

class SuperBikeBuilder : public Builder
{
public:
    virtual void design_model() { m_bike->set_name("SuperBike"); }
    virtual void define_speed() { m_bike->set_max_speed(200); }
    virtual void define_price() { m_bike->set_price(10); }
    virtual void define_milege() { m_bike->set_milege(25); }
};

class DirtBikeBuilder : public Builder
{
public:
    virtual void design_model() { m_bike->set_name("DirtBike"); }
    virtual void define_speed() { m_bike->set_max_speed(70); }
    virtual void define_price() { m_bike->set_price(7); }
    virtual void define_milege() { m_bike->set_milege(15); }
};

class Director
{
public:
    Bike *create(Builder *builder)
    {
        Bike *bike = new Bike;
        builder->design_model();
        builder->define_speed();
        builder->define_price();
        builder->define_milege();
        return builder->get_bike();
    }
};

int main()
{
    Director dir;
    SuperBikeBuilder sbb;
    DirtBikeBuilder dbb;
    Bike *bike = dir.create(&sbb);
    bike->showspecs();
    delete bike;

    bike = dir.create(&dbb);
    bike->showspecs();
    delete bike;

    return 0;
}