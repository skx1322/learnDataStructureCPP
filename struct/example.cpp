#include <iostream>
using namespace std;

struct Stat
{
    int hp;
    int def;
    int dmg;
    int dice;
};

void
displayStat(Stat s)
{
    cout << s.hp << endl;
    cout << s.def << endl;
    cout << s.dmg << endl;
    cout << s.dice << endl;
}

int main()
{
    Stat myPlayer;

    myPlayer = {100, 30, 15, 20};
    displayStat(myPlayer);

    return 0;
}