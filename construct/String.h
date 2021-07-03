#include <iostream>
class String
{
public:
    String();
    String(const String&);
    String& operator=(const String& s);
private:
    char* data;

};

