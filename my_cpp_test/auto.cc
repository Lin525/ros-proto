#include <iostream>
using namespace std;

int main()
{
    const int &i = 10;
    // 类型推导时，会丢失 引用 或 cv（const，volatile） 语义
    auto j = i; // j 属性 int
    // 用引用的方式，可以保留 引用 或 cv（const，volatile） 语义
    auto j = &i; //
    // 万能引用
    auto&& m = i;
    auto&& n = 10;
    return 0;
}