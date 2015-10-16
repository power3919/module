#include <iostream>
using namespace std;
static const double PI = 3.14;
class Shape
{
public:
	virtual double Area() = 0;
	virtual ~Shape(){}
};


class Rectangle : public Shape
{
public:
    Rectangle( int width, int height );
public:
	double Area();
private:
	int _width;
	int _height;
};
Rectangle::Rectangle( int width, int height ) 
{
	_width = width;
	_height = height;
}
double Rectangle::Area()
{
	return _width*_height;
}


class Circle : public Shape
{
public:
	Circle( int radius );
public:
	double Area();
private:
	int _radius;
};


class Creator
{
public:
	virtual Shape* CreateShape() = 0;
	virtual ~Creator() {}
};


class RectCreator : public Creator
{
public:
	Shape* CreateShape()
	{
		Rectangle* rect = new Rectangle( 10, 20 );
		return rect;
	}
};


class CircleCreator : public Creator 
{
public:
	Shape* CreateShape()
	{
		Circle* circle = new Circle( 10 );
		return circle;
	}
};

void Create( Creator* pCreator )
{
	Shape* pShape = pCreator->CreateShape();
	pShape->Area();
	delete pShape;
	pShape = NULL;
}

int main()
{
	CircleCreator cs;
	RectCreator   rs;
	Create( &cs );
	Create( &rs );
	
    return 0;	
}


