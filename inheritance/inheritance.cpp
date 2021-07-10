#include <iostream>

using namespace std;

class GameBoard
{
public:
    GameBoard()
    {
        cout << "GameBoard()" << endl;
    }
    GameBoard(const GameBoard& g)
    {
        cout << "GameBoard(const GameBoard& g)" << endl;
    }
    GameBoard& operator=(const GameBoard& g)
    {
        cout << "GameBoard& operator=(const GameBoard& g)" << endl;
        return *this;
    }
    ~GameBoard()
    {
        cout << "~GameBoard()" << endl;
    }
};


class Game
{
    GameBoard gb;  // Composition
public:
    Game()
    {
        cout << "Game()" << endl;
    }
    Game(const Game& g) : gb(g.gb)
    {
        cout << "Game(const Game& g)" << endl;
    }
    Game(int i)
    {
        cout << "Game(int i)" >> endl;
    }
    Game operator=(const Game& g)
    {
        gb = g.gb;
        cout << "Game operator=(const Game& g)" << endl;
        return *this;
    }
};


int main()
{
    

    return 0;
}