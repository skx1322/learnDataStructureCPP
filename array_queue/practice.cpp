#include <iostream>
using namespace std;

const int MAX_SIZE = 6;

class queue
{
private:
    int front;
    int rear;
    int count;
    int data_set[MAX_SIZE];

public:
    queue() : front(0), rear(-1), count(0) {};

    bool isEmpty()
    {
        if (front == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    };

    bool isFull(){
        if (rear == MAX_SIZE - 1)
        {
            return true;
        }
        else {
            return false;
        }
    }

    void enqueue(int value){
        if (isFull())
        {
            cout<<"Queue full."<<endl;
            return;
        }
        
        rear = (rear + 1) % MAX_SIZE;
        data_set[rear] = value;
        count++;
    };

    int dequeue(){
        int dequeue_value = data_set[front];
        front = (front + 1) % MAX_SIZE;
        count--;

        if (isEmpty())
        {
            front = rear = -1;
        }
        

        return dequeue_value;
    };

    ~queue(){
        cout<<"Class clear"<<endl;
    }
};

int main()
{
    queue currentQueue;

    currentQueue.enqueue(1);
    currentQueue.enqueue(2);
    currentQueue.enqueue(3);
    currentQueue.enqueue(4);
    currentQueue.enqueue(5);
    currentQueue.enqueue(6);
    currentQueue.enqueue(7);

    for (int i = 0; i < 6; i++)
    {
        cout<<" "<<currentQueue.dequeue();
    }
    cout<<endl;
    return 0;
};