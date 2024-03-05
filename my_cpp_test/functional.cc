#include <functional>
#include <iostream>
#include <algorithm>
using namespace std;

void hello(int count) {
    cout << "hello: " << count << endl;
}

class StaticFunc {
public:
    static void hello(int count) {
        cout << "StaticFunc::hello: " << count << endl;
    }
};

class CHello {
public:
    void hello(int count) {
        cout << "CHello::hello: " << count << endl;
    }
};

// 仿函数（函数对象）: 重载了 操作符() 的 类
class Hello {
public:
    void operator() (int count) {
        i += count;
        cout << "Hello::hello:" << i << endl;        
    }
    void operator() (int a, int b) {
        cout << "Hello: a+b=" << a+b << endl;
    }
    int i = 0; // 函数对象的状态
};



int main() {
    // 保存 普通函数，和 类的静态成员函数    
    function<void(int)> f_hello1 = hello; // 可以指向 具体函数
    f_hello1(1);    
    function<void(int)> f_hello2 = &hello; // 也可以指向 函数地址   
    f_hello2(2);
    function<void(int)> f_hello3 = &StaticFunc::hello;
    f_hello3(3);
    
    // 保存 仿函数
    function<void(int)> f_hello4 = Hello();
    f_hello4(4);
    f_hello4(4); 
    function<void(int, int)> f_hello5 = Hello();
    f_hello5(5, 6);

    // 保存 成员函数
    // 无论有多少个对象， static成员函数都只有一个， 但普通成员函数却是每个成员一个
    function<void(CHello *,int)> f_hello6 = &CHello::hello;
    CHello c;
    f_hello6(&c, 6);
    
    

    int i = 0;
    // lambda: 一种 方便创建匿名函数 语法糖
    // 构成： [] 捕获列表，i 值捕获，&i 引用捕获；   () 函数参数
    auto f_hello7 = [i] (int count) mutable -> void {
    // auto f_hello7 = [&i] (int count)-> void {
        i++;
        cout << "lambda i: " << i << " count:" << count << endl; 
    };
    f_hello7(8);
    f_hello7(8);
    cout << "i " << i << endl; // mutable 不改变外部变量


    // bind: 绑定 函数 和 函数参数，生成函数对象
    // 绑定普通函数
    auto f_hello9 = bind(hello, 9);
    f_hello9();
    // 绑定类成员函数
    auto f_hello10 = bind(&CHello::hello, &c, 10);
    f_hello10();
    // 提供占位符
    auto f_hello11 = bind(&CHello::hello, &c, placeholders::_1);
    f_hello11(1000);
    return 0;
}