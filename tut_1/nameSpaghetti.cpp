#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    char name[20]; // declare char, essentially a string
    char *ptr1, *ptr2; // char pointer  declartion

    cout << "Enter a name -> ";
    cin >> name;

    for (ptr1 = name; *ptr1 != 0; ptr1++) // point toward array and assign value/address, when memory address is null or 0, it'll halt cycle, when we increase the ptr1 index, it'll abstract 1 less index
    { // for example cycle 1{input: 'fuhua', process: ptr2 = 'fuhua', output: 'fuhua'
        for (ptr2 = ptr1; *ptr2 != 0; ptr2++) // assign pointer 2 with pointer 1 current issue and print all of it char based on the memory address until there's no more memory address.
            cout << *ptr2 << ""; 
        cout << ' ';
    }
    cout << endl;

    return 0;
}
