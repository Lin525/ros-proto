#include <iostream>
using namespace std;

class A {
public:
    virtual void Func() {}
};

class B : public A{
public:
    // 会报错
    // virtual int fUnc() override {}  
    // virtual int Func() override {}
    // virtual void Func(int) override {}
    // virtual void Func() const override {}

    virtual void Func() final override{}
};

// class C final: public B{
// public:
// 会报错
//     void Func() {}
// };

// 会报错
// class D : public C {

// }

int main()
{

    return 0;
}