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
    
};