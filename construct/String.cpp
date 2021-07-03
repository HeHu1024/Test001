#include "String.h"
#include "string.h"


String& String::operator=(const String& s)
{
    if( &s != this )
    {   
        delete[] data;
        data = new char[strlen(s.data) + 1];
        strcpy(data,s.data);

    } 
    
    return *this;
}


String::String()
{

}




int main()
{
    String s1;
    s1 = s1;
    return 0;
}
