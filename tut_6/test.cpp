#include <iostream>
#include <cctype>
#include "QueueA.cpp"

using namespace std;
// using Practice2::Queue;

Queue input;

Queue smallChar;
Queue bigChar;
Queue num;
Queue symbol;

void asciiQueue(char x)
{
    if (isspace(x))
    {
        return;
    }

    if (isupper(x))
    {
        cout << "Big Char: " << x << endl;
        bigChar.enqueue(x);
        return;
    }
    else if (islower(x))
    {
        cout << "Small Char: " << x << endl;
        smallChar.enqueue(x);
        return;
    }
    else if (isdigit(x))
    {
        cout << "Num Char: " << x << endl;
        num.enqueue(x);
    }
    else
    {
        cout << "Symbol Char: " << x << endl;
        symbol.enqueue(x);
    };
}

void displayQueue(Queue x)
{
    cout << "Char: ";
    while (!x.isEmpty())
    {
        cout << x.getFront();
        x.dequeue();
    };
    cout << endl;
}

int main()
{
    char character = '\0';

    cout << "Input characters (Press ENTER to stop):" << endl;
    while (cin.peek() != '\n')
    {
        cin >> character;
        input.enqueue(character);
    }
    cout << endl;

    while (!input.isEmpty())
    {
        asciiQueue(input.getFront());
        input.dequeue();
    }

    displayQueue(bigChar);

    displayQueue(smallChar);
    displayQueue(num);

    displayQueue(symbol);
    return 0;
}
