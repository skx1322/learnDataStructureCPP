#include <iostream>
using namespace std;

const int MAX_SIZE = 6;

class stack
{
private:
    int top;
    int data[MAX_SIZE];

public:
    stack() : top(0) {};

    bool isEmpty()
    {
        if (top == 0)
            return true;
        else
            return false;
    };

    bool isFull()
    {
        if (top == MAX_SIZE)
            return true;
        else
            return false;
    }

    void push(int target)
    {
        if (isFull())
        {
            cout << "Stack is full." << endl;
            return;
        }

        data[top] = target;
        top++;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return -1;
        }

        return data[top--];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack:";
        for (int i = 0; i < top; i++)
            cout << " " << data[i];
        cout << endl;
    }
};

int main()
{
    stack ItemTower;

    ItemTower.push(1);
    ItemTower.push(2);
    ItemTower.push(3);
    ItemTower.push(4);
    ItemTower.push(5);
    ItemTower.push(6);
    ItemTower.push(7);

    ItemTower.display();

    ItemTower.pop();
    ItemTower.pop();
    ItemTower.pop();

    ItemTower.display();

    return 0;
}