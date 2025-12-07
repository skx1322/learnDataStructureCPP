#include <iostream>
#include <string>

using namespace std;

// TODO: Write your code here
// Begin Question
void balancedBraces(const string &input)
{
    const char* ptr1 = input.c_str();

    while (*ptr1 != 0)
    {
        cout<<*ptr1<<endl;
        ptr1++;
    }
    
}
// End Question

int main()
{
    string input;
    // bool balancedSoFar = false;

    cout << "Input a string: ";
    cin >> input;

    balancedBraces(input);
    system("PAUSE");
    return 0;
}
