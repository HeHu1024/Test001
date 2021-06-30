class Pointer
{
public:
    Pointer(int p,int q);

private:
    int m_x;
    int m_y;
};


class BaseTest
{
public:
    BaseTest();
    virtual ~BaseTest();
private:
    char* m_data;
};

class Test : public BaseTest
{
public:
    Test();
    ~Test();
};