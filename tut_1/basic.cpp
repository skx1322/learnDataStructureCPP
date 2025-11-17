#include <iostream>
using namespace std;

string name;
int age;

int main()
{
    cout << "What's your name:";
    getline(cin, name);

    cout << endl;

    cout << "What's your age:";
    cin >> age;

    if (age > 100)
    {
        cout << name << ", you are so old holy crap..." << age << "???" << endl;
    }
    else
    {
        cout << name << ", you are " << age << "?" << endl;
    }

    return 0;
};
