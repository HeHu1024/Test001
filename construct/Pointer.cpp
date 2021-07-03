#include <iostream>
#include "Pointer.h"

using namespace std;

Pointer::Pointer(int p,int q) : m_x(p),m_y(q)
{
    cout << "Pointer" << endl;
}

BaseTest::BaseTest()
{
    cout << "BaseTest()" << endl;
    m_data = new char[10];
}
BaseTest::~BaseTest()
{
    cout << "~BaseTest()" << endl;
    delete [] m_data;
}


Test::Test()
{
    cout << "Test()" << endl;
}
Test::~Test()
{
     cout << "~Test()" << endl;
}

int main()
{
    //Pointer q;
    //Pointer p(1,2);
    //Pointer pa[100];

    //BaseTest* base = new Test;
    //delete base;
    BaseTest ba1;
    //BaseTest ba2 = ba1; 会crash
    return 0;
}