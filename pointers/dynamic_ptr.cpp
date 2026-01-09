#include <iostream>
using namespace std;

struct Node
{
    int nums;
    Node *next;
};

class linkedList
{
private:
    Node *head;

public:
    linkedList() : head(nullptr) {}

    void addFirst(int data)
    {
        Node *temp = new Node;
        temp->nums = data;
        temp->next = nullptr;
        
        temp->next = head;
        head = temp;
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

    return 0;
}
