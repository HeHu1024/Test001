#include <iostream>

using namespace std;


class Pointer
{
public:
    Pointer();
    Pointer(int xv,int yv);
    int getX() const;
    int getY() const;

    Pointer& setX(int xv);
    Pointer& setY(int yv);

private:
    int x_value,y_value;
};

Pointer::Pointer()
{

}
Pointer::Pointer(int xv,int yv) : x_value(xv),y_value(yv)
{

}

int Pointer::getX() const
{
    return this->x_value;
}

int Pointer::getY() const
{
    return this->y_value;
}

Pointer& Pointer::setX(int xv)
{
    this->x_value = xv;
    return *this;
}

Pointer& Pointer::setY(int yv)
{
    this->y_value = yv;
    return *this;
}

// 通过handle 类来保存Pinter类
class Handle
{
public:
    Handle();
    Handle(int x,int y);
    Handle(const Handle& h);
    Handle(const Pointer& p);
    Handle& operator=(const Handle& h);
    Handle& x(int x);
    ~Handle();
private:
    Pointer *m_p;
    int *u; // 指向引用计数的内存

};

// 待定。。。。。。。

int main()
{


    return 0;
}