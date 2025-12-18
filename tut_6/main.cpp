#include <iostream>
#include "QueueA.cpp"
using namespace std;

int main()
{
    Queue myQueue;

    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);
    myQueue.enqueue(6);
    myQueue.enqueue(7);

    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();

    myQueue.enqueue(8);

    const int test = myQueue.getFront();

    cout << test << endl;
    return 0;
}