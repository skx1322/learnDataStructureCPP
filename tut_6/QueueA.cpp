#include <iostream>
#include "QueueA.hpp"
using namespace std;
using namespace Practice1;

Queue::Queue() : front(-1), back(-1), count(0)
{
}

Queue::~Queue()
{
}

bool Queue::isEmpty()
{
    return front == -1 || front > back;
}

void Queue::enqueue(QueueItemType newItem)
{
    // HINT:
    // (a) Check whether the queue is full
    back = (back + 1) % MAX_QUEUE;

    if (count == MAX_QUEUE)
    {
        cout << "Queue is full." << endl;
        return;
    }

    // (b) Add the new item into the queue if it's not full

    count++;
    if (isEmpty())
    {
        items[back] = newItem;
        front++;
        return;
    }

    items[back] = newItem;
    return;
}

void Queue::dequeue()
{
    // HINT:
    // (a) Check whether the queue is empty
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }

    // (b) Remove the front item of the queue if it's not empty
    front = (front + 1) % MAX_QUEUE;
    // (c) Reduce the count by 1
    count--;
    // TODO: Fill in your code here
}

QueueItemType Queue::getFront()
{
    return items[front];
}
