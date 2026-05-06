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
    Node *top ;
    Stack(){
        top = NULL;
    }
    void push(int val){
        Node *newnode = new Node(val);
        newnode->next = top;
        top = newnode;
    }
    int pop(){
        if(top == NULL){
            return -1;
        }
        Node *todelete = top;
        int val = top->data;
        top = top->next;
        delete todelete;
        return val;
    }

    bool isempty(){
        return top == NULL;
    }

    char Top(){
        return top->data;
    }
};

