#include <iostream>

using namespace std;

/*********************************************/
/*
*   C++ 的代理类思想，参考博客更加容易理解https://www.cnblogs.com/zhangkele/p/9236612.html
*   2021-7-2: 学习C++ 沉思录中的代理思想
*/

class Vehicle
{
public:
    virtual double weight() const = 0;
    virtual void start() = 0;
    virtual Vehicle * copy() const = 0;
    virtual ~Vehicle();

};


class AirVehicle : public Vehicle
{
public:
    AirVehicle();
    Vehicle* copy() const;
    double weight() const; 
    void start();
    ~AirVehicle();

};


Vehicle* AirVehicle::copy() const
{
    return new AirVehicle(*this);
}

// 定义代理类
class VehicleSurrogate
{
public:
    VehicleSurrogate();
    VehicleSurrogate(const VehicleSurrogate& vs);
    ~VehicleSurrogate();
    VehicleSurrogate(const Vehicle &v);
    VehicleSurrogate& operator=(const VehicleSurrogate& vs);
    double weight() const ;
    void start();

private:
    Vehicle* vp;

};


VehicleSurrogate::VehicleSurrogate() : vp(NULL)
{

}

VehicleSurrogate::VehicleSurrogate(const Vehicle& v) : vp(v.copy())
{

}

VehicleSurrogate::~VehicleSurrogate()
{
    delete vp;
}

VehicleSurrogate::VehicleSurrogate(const VehicleSurrogate & vs) : vp(vs.vp ? vs.vp->copy() : NULL)
{

} 

VehicleSurrogate& VehicleSurrogate::operator=(const VehicleSurrogate& vs)
{
    // 判断自赋值
    if( &vs != this )
    {
        delete this->vp;
        // 对vp进行非0检测
        this->vp = (vs.vp ? vs.vp->copy() : NULL);
    }

    return *this;
}


double VehicleSurrogate::weight() const
{
    if( vp == 0 )
    {
        throw "empty VehicleSurrogate::weight() const";
    }
    return vp->weight();
}


void VehicleSurrogate::start()
{
    if( vp == 0 )
    {
        throw "empty VehicleSurrogate::start()";
    }
    vp->start();
}

int main()
{

    return 0;
}