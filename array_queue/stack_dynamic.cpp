#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class stack_dynamic{
    private:
        Node* top;
    public: 
        stack_dynamic() : top(nullptr) {}

        bool isEmpty(){
            return top == nullptr;
        };

        void push(int data){
            Node* new_node = new Node();
            
            new_node->data = data; // set node data with data
            new_node->next = top; // link node as current top
            top = new_node; // update top pointer to the new node
        }

        int pop(){
            if (isEmpty())
            {
                cout<<"Stack is empty."<<endl;
                return;
            }
            Node* temp = top; // point to current top
            top = top->next; // move top pointer to next node
            delete temp; // delete temp aka WAS current top
        }

        void display(){
            
        }
};

int main(){
    return 0;
}