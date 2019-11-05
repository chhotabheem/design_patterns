#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void print() = 0;
};

class Circle : public Shape
{
public:
    virtual void print() override { cout << "im drawing circle" << endl; }
};

class Square : public Shape
{
public:
    virtual void print() override { cout << "im drawing square" << endl; }
};

class Drawing
{
public:
    void draw(Shape *shape)
    {
        cout << "going to draw" << endl;
        shape->print();
    }
};

class Idrawing
{
    Drawing drawing;

public:
    void draw() { drawing.draw(new Circle); }
};

int main()
{
    Idrawing idrawing;
    idrawing.draw();
    return 0;
}
