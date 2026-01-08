#include <iostream>
using namespace std;

struct Node
{
    int nums;
    Node *next;

    Node(int val) : nums(val), next(nullptr) {}
};

class linkedList
{
private:
    Node *head;

public:
    linkedList() : head(nullptr) {}

    void addFirst(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void printAll()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->nums << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~linkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main()
{
    linkedList dynamicPTR;

    dynamicPTR.addFirst(2);
    dynamicPTR.addFirst(3);
    dynamicPTR.addFirst(4);
    dynamicPTR.addFirst(5);
    dynamicPTR.addFirst(6);

    dynamicPTR.printAll();

    dynamicPTR.~linkedList();
    return 0;
}
