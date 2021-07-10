#include <iostream>

using namespace std;

/***************************************************protect******************************
 * 使用protect 的继承方式可以使用子类调用父类的方法，使用户对父类的方法不可见
 * 相当于父类对用户而言是private.但是它可以被从继承来的任何类使用
 * 继承还有一个称呼:向上类型转换
*/

class Base
{
private:
    int m_i;
protected:
    int read() const
    {
        return m_i;
    }
    void set(const int i)
    {
        m_i = i;
        cout << "set(const int i)" << " m_i:" << m_i << endl;
    }
public:
    Base(int i = 0) : m_i(i)
    {

    }
    int value(int m) const
    {
        return m * m_i;
    }
};

class Derived : protected Base
{
    int m_j;
public:
    Derived(int j = 0)
    {
        m_j = j;
    }    
    void change(int x)
    {
        set(x);
    }
};

int main()
{
    Derived d;
    d.change(20);
    return 0;
}