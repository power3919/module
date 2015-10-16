// singleton.cpp : Defines the entry point for the console application.
//
//单例模式：一个类只能初始化一个唯一的对象
#include <iostream>
using namespace std;
class CSystemControl 
{
public:
     static CSystemControl* Instance();
     static void destroy();
protected:
	 ~CSystemControl();
public:
	 void   Print();
private:
	CSystemControl();
private:
	static CSystemControl* _instance;
 };
CSystemControl* CSystemControl::_instance = NULL;
CSystemControl* CSystemControl::Instance () 
{
    if (_instance == NULL) 
	{
         _instance = new CSystemControl;
    }
	return _instance;
}
CSystemControl::~CSystemControl()
{
	//释放开辟空间的属性
}
void CSystemControl::destroy()
{
    if (_instance) {
        delete _instance;
        _instance=NULL;
    }
}
void CSystemControl::Print()
{
	cout<<"Call the print method!"<<endl;
}
CSystemControl::CSystemControl()
{
cout<<"Construct a SystemControl object"<<endl;
}
int main(int argc, char* argv[])
{
    CSystemControl* p1 = CSystemControl::Instance();
    CSystemControl* p2 = CSystemControl::Instance();
	p1->Print();
	return 0;
}

