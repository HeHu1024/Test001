#include <iostream>

using namespace std;


class One
{
public:
    One(){};
};

class Two
{
public:
    Two(const One& one);
};

class Two2
{
public:
    explicit Two2(const One& one){};        // 防止构造函数自动转换
};

/*
void Fuc(const One& one)
{
    cout << "Fuc(const One& one)" << endl;
}
*/

void Fuc(Two2)
{
    cout << "Fuc(Two&)" << endl;
}

int main()
{
    // 编译器进行编译的时候，发现Fuc()函数的参数需要一个Two,编译器检查是否有one到Two的方法
    // 发现Two(const One& two); 结果对象Two传递给了Fuc()
    One one;
    //Fuc(one);         Error
    Fuc(Two2(one)); 
    //Fuc(one);
    return 0;
}