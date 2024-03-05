#include <iostream>
using namespace std;

class A {
public:
    void func1() {}
    void func2() {}
    int num;
};

class B1 : virtual public A {
    void func1() {}
};

class B2 : virtual public A {
    void func2() {}
};

class C : public B1, public B2 {

};

int main()
{
    C c;
    c.B1::num = 1;
    c.B2::num = 2;
    cout << "c.B1::num " << c.B1::num << " c.B2::num " << c.B2::num << endl;
    return 0;
}