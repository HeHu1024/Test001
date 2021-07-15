#include <iostream>
#include <cstring>
using namespace std;

/***************************************************************************************
 *  在基类中，对纯虚函数提供定义是可能的。我们仍然告诉编译器不允许产生抽象基类
 *  的对象，而且如果要创建对象，则纯虚函数必须在派生类中定义。然而，我们可能希望一
 *  段公共代码，使一些或所有派生类定义都能调用，而不必在每个函数中重复这段代码
 * 
 * 
*/


class Pet
{
public:

    virtual string speak() const
    {
        return "";
    }
};

class Pet2
{
public:
    virtual void speak() const = 0;
    virtual void eat() const = 0;
    //! virtual void sleep() const = 0;
};


// OK,not define inline
void Pet2::speak() const
{
    cout << "Pet2::speak()" << endl;
}
void Pet2::eat() const
{
    cout << "Pet2::eat" << endl;
}


class Dog : public Pet
{
public:
    string speak() const
    {
        return "Dog::speak";
    }
};


class Dog2 : public Pet2
{
public:
    // use the common Pet2 code
    void speak() const
    {
        Pet2::speak();
    }
    void eat() const 
    {
        Pet2::eat();
    }
};


int main()
{


    Dog ralph;
    Pet& pet1 = ralph;
    Pet* pet2 = &ralph;
    Pet p3;

    // later bind 
    cout << "pet1.speak()" << pet1.speak() << endl;
    cout << "pet2->speak()" << pet2->speak() << endl;
    cout << "p3.speak()" << p3.speak() << endl;

    cout << endl;

    Dog2 dog2;
    dog2.eat();
    dog2.speak();

    return 0;
}