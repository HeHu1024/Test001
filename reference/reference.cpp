#include <iostream>
#include <string>

using namespace std;

// 引用必须在定义的时候就初始化
// 一旦一个引用被初始化指向一个对象的时候，它就不能改变另一个对象的引用
// 不可能有NULL引用，必须确保引用是一块合法的存储单元关联
int x = 10;
int& y = x;
// Error
//int &r = 12;

const int& r = 12;


class HowMany
{
public:
    HowMany();
    static void print(const string& msg);
    ~HowMany();
private:
    static int objectCount;

};

HowMany::HowMany()
{
    objectCount ++;
}

void HowMany::print(const string& msg)
{
    if( msg.size() != 0 )
    {
        cout << msg << ":";
        cout << "ObjectCout = " << objectCount << endl;

    }
}

int HowMany::objectCount = 0;
HowMany::~HowMany()
{
    objectCount--;
    print("~HowMany()");
}

// 这里参数按值的形式传递，函数结束后，临时的参数会释放
HowMany f(HowMany x)
{
    x.print("x argument inside f()");
    return x;
}

class HowMany2
{
public:
    HowMany2(const string& id);
    ~HowMany2();
    HowMany2(const HowMany2& h);
    void print(const string& msg);
private:
    string m_name;
    static int objectCount;

};

int HowMany2::objectCount = 0;

HowMany2::HowMany2(const string& id) : m_name(id)
{
    objectCount++;
    print("HowMany2()");
}

HowMany2::~HowMany2()
{
    objectCount--;
    print("~HowMany2()");
}

void HowMany2::print(const string& msg)
{
    if( msg.size() != 0 )
    {
        cout << "msg:" << msg << endl;
    }
    cout << "objectCount = " << objectCount << endl;
}

/*******************************************************************
 * 学习的时候，纠结一个问题，拷贝构造函数什么时候会被调用？
 * 一个解释得很好的博客link：https://www.cnblogs.com/ay-a/p/10415808.html
 * 
 * 
 * 
 * 
 * 
 * ****************************************************************/

HowMany2::HowMany2(const HowMany2& h) : m_name(h.m_name)
{
    m_name += "copy";
    objectCount++;
    print("HowMany2(const HowMany2& h)");
}
// 会调用拷贝构造函数对形参初始化
HowMany2 f(HowMany2 x)
{
    x.print("x argument inside f()");
    cout << "returning from f()" << endl;
    return x;
}

int main()
{
    HowMany h;  // 调用构造函数objectcount  =1;
    HowMany::print("after construction of h");  // objectcount =1;
    HowMany h2 = f(h);  // 调用后会调用析构函数
    HowMany::print("after call the f()");

    cout << endl;


    HowMany2 hm("hm");      // 调用构造函数，                  objectCount =1;
    // f(hm) ===>调用拷贝构造函数                              objectCount =2;
    // HowMany2 hm2 ===> 又会调用拷贝构造函数                  objectCount =3;
    // f(HowMany2 x) ===> 函数返回后会调用形参的析构函数        objectCount =2;     
    HowMany2 hm2 = f(hm);



    cout << "wiil return" << endl;
    // return 后会调用hm 和hm2的析构函数

    return 0;
}