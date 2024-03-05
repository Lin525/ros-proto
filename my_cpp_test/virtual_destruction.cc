#include <iostream>
using namespace std;

class Base {
public:
    // virtual void Func() {} // 有这个就有vptr，但是没用，因为p对象的析构函数还是~Base()


    // 这里有virtual，则构造时子类的虚构函数地址会覆盖 p对象的vptr，
    // 也就是说p对象的析构函数是~Drive()，也会继续去执行基类的虚构函数~Base()
    virtual ~Base() { 
        cout << "Base::~Base" << endl;
    }
};

class Drive : public Base {
public:
    ~Drive() {
        cout << "Drive::~Drive" << endl;
    }
};

int main()
{
    // 正常输出
    // Drive d;

    Base *p = new Drive();
    delete p;

    return 0;
}