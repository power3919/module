#include <iostream>
using namespace std;

static const double PI = 3.14;

class Shape
{
public:
	virtual double Area() = 0;
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

Circle::Circle( int radius )
{
	_radius = radius;
}

double Circle::Area()
{
	return PI*_radius*_radius;
}

class Window
{
public:
	Window( Shape* pShape );

public:
	void   SetShape( Shape* pShape );
	double Area();
    
private:
	Shape* _pShape;
};

Window::Window( Shape* pShape )
{
	_pShape = pShape;
}

double Window::Area()
{
	return _pShape->Area();
}

void Window::SetShape( Shape* pShape )
{
	_pShape = pShape;
}

int main(int argc, char* argv[])
{
        Rectangle rec( 10, 20 );
	Circle    cir( 10 );

	Window aWindow( &rec );
	double area = aWindow.Area();
	cout<<"Area = "<<area<<endl;

	aWindow.SetShape( &cir );
	area = aWindow.Area();
	cout<<"Area = "<<area<<endl;

	return 0;
}