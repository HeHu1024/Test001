#include <iostream>
#include <cstring>
using namespace std;
/**************************************************************
 *  如果不适应指针或者引用，而是使用值传递的方式会发生什么情况？
 *  会出现对象切片
*/

class Pet
{
    string Pname;
public:
    Pet(const string& name) : Pname(name){}
    virtual string name() const
    {
        return Pname;
    }
    virtual string description() const
    {
        return "this is" + Pname;
    }
};


class Dog : public Pet
{
string favoriateActivity;
public:
    Dog(const string& name,const string& activity) : Pet(name), favoriateActivity(activity) {}

    string description() const
    {
        return Pet::name() + "likes to" + favoriateActivity;
    }
};
// object slicing
void descibe(Pet p)
{
    cout << p.description() << endl;
}

int main()
{
    Pet p("Alfred");
    Dog dog("fluffy","sleep");
    descibe(p);
    descibe(dog);

    return 0;
}