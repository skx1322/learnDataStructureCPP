#include <iostream>
using namespace std;

struct Node
{
    string data;
    Node *next;

    Node(string value) : data(value), next(nullptr){}
};

string searchLink(Node *head, string search_value)
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->data == search_value)
        {
            return current->data;
        }
        current = current->next;
    };
    return "Not Item Found";
}

int main()
{

    Node *head = new Node("Senti");
    head->next = new Node("Fu Hua");
    head->next->next = new Node("Valk");
    head->next->next->next = new Node("Azure");
    head->next->next->next->next = new Node("Taixuan");

    cout<<searchLink(head, "")<<endl;

    Node *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
