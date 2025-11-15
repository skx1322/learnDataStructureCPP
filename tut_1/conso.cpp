#include <cctype>
#include <iostream>
#include <string>

using namespace std;

string text;
string resultText;
char result[20];

char isConsonant(char ch)
{
    if (!isalpha(ch)) // check whether if provided data are A to Z then lowercase vise versa
    {
        return 0;
    }

    char lower_ch = tolower(ch);   // lowering case
    const string vowels = "aeiou"; // static vowels var used for checking

    if (vowels.find(lower_ch) != string::npos)
    {
        return ch;
    }
    return 0;
}

int main()
{
    cout << "Insert word of wisdom: " << endl;
    cin >> text;

    for (int i = 0; i < text.length(); i++)
    {
        result[i] = isConsonant(text[i]);
    }

    for (int i = 0; i < text.length(); i++)
    {
        resultText+= result[i];
    }
    cout<<resultText<<endl;

    return 0;
};
