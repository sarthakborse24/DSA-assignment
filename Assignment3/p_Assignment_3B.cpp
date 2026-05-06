#include <iostream>
#include <cctype>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Stack{
public:
    Node *top = NULL;
    void push(int val){
        Node *newnode = new Node(val);

        if (top->next == NULL)
        {
            top = newnode;
            return;
        }
        
        
    }
};