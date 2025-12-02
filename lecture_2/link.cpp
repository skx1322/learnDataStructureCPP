#include <iostream>>
using namespace std;

struct Node
{
    int item
    Node *next;
};


int main()
{

    Node *head;
    head = new Node;

    head->item = 1;
    head->next = NULL;
    return 0;
}
