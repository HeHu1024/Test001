#include <iostream>
using namespace std;

class Vehicle
{
    virtual double weight() const = 0;
    virtual void start() = 0;
};


class RoadVehicle : public Vehicle
{
    double weight()
    {
        cout << "RoadVehicle::weight()" << endl;
        return 1.0;
    }
    
};

class AutoVehicle : public Vehicle
{
    double weight()
    {
        cout << "AutoVehicle::weight()" << endl;
        return 1.0;
    }
};

class AirVehicle : public Vehicle
{
    double weight()
    {
        cout << "AirVehicle::weight()" << endl;
        return 1.0;
    }
};

class Helicopter : public Vehicle
{
    double weight()
    {
        cout << "Helicopter::weight()" << endl;
        return 1.0;
    }
};


int main()
{
    Vehicle *parking_lot[100];
    return 0;
}