#include <iostream>

using namespace std;

enum note
{
    middleC,
    Csharp,
    cFlat
};  // ETC

class Instrument
{
public:
    virtual void play(note)
    {
        cout << "Instrument::play" << endl;
    }
    virtual char* what() const
    {
        return "Instrument";
    }
    virtual void adjust(int)
    {
        cout << "Instrument::adjust" << endl;
    }
};

class Wind : public  Instrument
{
public:
    void play(note)
    {
        cout << "Wind::play" << endl;
    }
    char* what() const
    {
        return "Wind";
    }
    void adjust(int)
    {
        cout << "Wind::adjust" << endl;
    }
};

class Percussion : public Instrument
{
    void play(note)
    {
        cout << "Percussion::play" << endl;
    }
    char*what() const
    {
        return "Percussion";
    }
    void adjust(int)
    {
        cout << "Percussion::adjust" << endl;
    }
};

class Stringed : public Instrument
{
public:
    void play(note)
    {
        cout << "Stringed::play" << endl;
    }
    char* what()const
    {
        return "Stringed";
    }
    void adjust(int)
    {
        cout << "Stringed::adjust" << endl;
    }
};

class Bress : public Wind
{
    void play(note)
    {
        cout << "Bress::play" << endl;
    }
    char* what()const
    {
        return "Bress";
    }
};

class Woodwind : public Wind
{
public:
    void play(note)
    {
        cout << "Woodwind::play" << endl;
    }
    char* what() const 
    {
        return "Woodwind";
    }
};

// New function
void func(Instrument& i)
{
    i.adjust(1);
}

void tune(Instrument& i)
{
    i.play(middleC);
}

Instrument *A[] = {
        new Wind,
        new Percussion,
        new Stringed,
        new Bress,
};


class Novirtual
{
public:
    //int a;
public:
    void x()const{};
    int i() const
    {
        return 1;
    }
};

class Onevirtual
{
public:
    //int a;
public:
    virtual void x() const{}
    int i() const {return 1;}
};

class Twovirtual
{
public:
    //int a;
public:
    virtual void x() const {}
    virtual int i()const {return 1;}
};


int main()
{
    
    Wind flute;
    Percussion drum;
    Stringed voilin;
    Bress flugelhorn;
    Woodwind recorder;
    tune(flute);
    tune(drum);
    tune(voilin);
    tune(flugelhorn);
    tune(recorder);
    func(flugelhorn);

    cout << endl;

    cout << "int: " << sizeof(int) << endl;
    cout << "Novirtual: " << sizeof(Novirtual) << endl;
    cout << "void*: " << sizeof(void*) << endl;
    cout << "Onevirtual: " << sizeof(Onevirtual) << endl;
    cout << "Twovirtual: " << sizeof(Twovirtual) << endl; 

    return 0;
}