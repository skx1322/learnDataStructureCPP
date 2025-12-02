#include <iostream>
using namespace std;

class Valkyrie
{
public:
    void Walk()
    {
        cout << "Walking..." << endl;
    };
};

class BRank : public Valkyrie
{
public:
    void Walk()
    {
        cout << "B-Rank Valkyrie Walking..." << endl;
    };
};

int main()
{   
    BRank Kiana;
    Kiana.Walk();

    return 0;
}
