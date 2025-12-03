#include <iostream>
using namespace std;

#define MAX_SIZE 6 // for array size max

int printEmpty()
{
    cout << "Queue is empty." << endl;
    return -1;
}

class Queue
{
public:
    int front;         // this is the start of queue size
    int rear;          // this is the end of queue size
    int arr[MAX_SIZE]; // setup array size

    Queue() : front(-1), rear(-1) {} // constructor for front and back, default value -1 which is no value, start should be 0-1 for instance

    bool isEmpty() // if front is default value or front is bigger than rear (e.g: 2 > -1), then it's empty
    {
        return front == -1 || front > rear;
    }

    bool isFull() // if the rear/end is at the max size of array, then it's full
    {
        return rear == MAX_SIZE - 1;
    }

    int getFront() // get the 1st queue value
    {
        if (isEmpty())
        {
            actuallyEmpty();
        }
        return arr[front];
    }

    int getRear() // get the last queue value, simple
    {
        if (isEmpty())
        {
            actuallyEmpty();
        }
        return arr[rear];
    }

    void addQueue(int val)
    {
        if (isFull()) // if queue aka size is full, then abort
        {
            cout << "Queue is full." << endl;
            return;
        }

        if (isEmpty()) // set front to 0 if it's new
        {
            front = 0;
        }

        rear++; // increase the rear/end by 1
        arr[rear] = val; 
    }

    int removeQueue() 
    {
        if (isEmpty())
        {
            actuallyEmpty();
        }
        int ans = arr[front]; // replace first queue with new value
        front++; // then increment front

        if (isEmpty()) // if fully empty, we just reset the whole queue back to default value aka -1
        {
            front = rear = -1; 
        }

        return ans;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};