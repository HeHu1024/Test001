#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

/********************use the malloc create the object memory*****************/

class Object
{
public:
    // can't ues the construct
    void Initialize()
    {
        cout << "Initialize Obj" << endl;
        i = j = k = 0;
        memset(buff,0,sz);
    }

    void Destroy()
    {
        cout << "Destroy Obj" << endl;
    }
public:
    enum size
    {
        sz = 100
    };
    char buff[sz];
    int i;
    int j;
    int k;
};

int main()
{
    Object* obj = (Object*)malloc(sizeof(Object));
    if( obj != NULL )
    {
        obj->Initialize();
    }

    obj->Destroy();
    free(obj);

    return 0;
}