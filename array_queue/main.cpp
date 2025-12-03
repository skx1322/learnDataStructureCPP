#include <iostream>
#include "array_queue.cpp"
using namespace std;

void displayData(Queue x)
{
    cout << "\nAfter Enqueueing:" << endl;

    cout << "Front element: " << x.getFront() << endl;
    cout << "Rear element: " << x.getRear() << endl;
}

int main()
{
    Queue q;

    q.addQueue(1);
    q.addQueue(2);
    q.addQueue(3);

    displayData(q);

    q.display();

    q.addQueue(4);
    q.addQueue(5);

    cout << "\nDequeueing elements:" << endl;
    cout << "Dequeued element: " << q.removeQueue() << endl;
    cout << "Dequeued element: " << q.removeQueue() << endl;

    cout << "\nAfter Dequeueing:" << endl;

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;

    q.display();
    return 0;
}