#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class queue
{
private:
    Node *front;
    Node *back;

public:
    queue() : front(nullptr), back(nullptr) {};

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(int data)
    {
        Node *temp = new Node;

        temp->data = data;
        temp->next = nullptr;

        if (back == nullptr)
        {
            front = back = temp;
            return;
        };

        back->next = temp;
        back = temp;
    }
    int dequeue()
    {
        if (front == nullptr)
        {
            return -1;
        };

        Node *temp = front;
        int num = temp->data;
        front = front->next;

        if (front == nullptr)
        {
            back = nullptr;
        }

        delete temp;
        return num;
    }
};

int main()
{
    queue myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);
    myQueue.enqueue(6);
    myQueue.enqueue(7);
    myQueue.enqueue(8);

    for (int i = 0; i < 8; i++)
    {
        cout << " " << myQueue.dequeue();
    }
    cout << endl;

    return 0;
}
