#include <iostream>
#include <cctype>
using namespace std;

class Node
{
public:
    char data;
    Node *next;

    Node(char val)
    {
        data = val;
        next = NULL;
    }
};

class Stack
{
public:
    Node *top;
    Stack()
    {
        top = NULL;
    }
    void push(int val)
    {
        Node *newnode = new Node(val);
        newnode->next = top;
        top = newnode;
    }
    int pop()
    {
        if (top == NULL)
        {
            return -1;
        }
        Node *todelete = top;
        int val = top->data;
        top = top->next;
        delete todelete;
        return val;
    }

    bool isempty()
    {
        return top == NULL;
    }

    char Top()
    {
        return top->data;
    }
};

int priority(char token)
{
    if (token == '(')
    {
        return 0;
    }
    else if (token == '+' || token == '-')
    {
        return 1;
    }
    else if (token == '*' || token == '/')
    {
        return 2;
    }
    else if (token == '^')
    {
        return 3;
    }

    return -1;
}

void infixtopostfix(char infix[20])
{
    int i, j = 0;
    Stack s;
    char token, op;
    char post[20];

    for (i = 0; infix[i] != '\0'; i++)
    {
        token = infix[i];
        if (isalnum(token))
        {
            post[j++] = token;
        }
        else if (token == '(')
        {
            s.push(token);
        }
        else if (token == ')')
        {
            while ((op = s.pop()) != '(')
            {
                post[j++] = op;
            }
        }
        else
        {
            while (!s.isempty() && priority(token) <= priority(s.Top()))
            {
                post[j++] = s.pop();
            }
            s.push(token);
        }
    }
    while (!s.isempty())
    {
        post[j++] = s.pop();
    }
    post[j] = '\0';
    cout <<"postfix expresion: "<< post;
}

int main(){
    char infix[20];

    cout<<"enter your infix expration: ";
    cin>>infix;

    infixtopostfix(infix);
    return 0;
}
