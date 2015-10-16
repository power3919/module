#include <iostream>
using namespace std;
class Observer
{
public:
	virtual void Update() = 0;
	virtual ~Observer() {}
};
class Engine 
{
public:
	Engine( Observer& aObserver ) : _observer( aObserver ){}
public:
 	void Dowdload()
 	{
        //漫长的下载。。。。。。
 		cout<<"Subject finished!"<<endl;
 		_observer.Update();
 	}
private:
    Observer& _observer;
};
class AppUI : public Observer
{
public:
        AppUI()
        {
        	_engine = new Engine( *this );}
	~AppUI()
	{
		delete _engine;
	}
public:
	void Start()
	{
		cout<<"The subject is called!"<<endl;
		_engine->Dowdload();
	}
public:
	void Update()
	{
		cout<<"the observer is called!"<<endl;
	}
private:
	Engine* _engine;
};
int main()
{
	AppUI* pUI = new AppUI;
	pUI->Start();	
	delete pUI;
	
	return 0;	
}


