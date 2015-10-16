#include <iostream>
using namespace std;
class Delegate {
public:
    virtual int Area()=0;
};
class Rectangle:public Delegate
{
public:
	Rectangle( int height, int width ) : _height( height ), _width( width ){}
public:
	int Area()
	{
		return _height*_width;
	}
private:
	int _height;
	int _width;
};
class Window 
{
public:
	Window( int height, int width ) : del( height, width ){}
public:
	int Area()
	{
		return del.Area();
	}
private:
	Rectangle del;
};
int main()
{
	Window win( 100, 200 );
	win.Area();
	return 0;
}