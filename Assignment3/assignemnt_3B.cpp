#include<iostream>
#include<cctype>
#include<cmath>
#include<cstring>
using namespace std;

class Node
{public:

    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Stack
{public:

    Node* top;
    Stack()
    {
        top = NULL;
    }

    int push(int val)
    {
        Node* newnode = new Node(val);
        newnode->next = top;
        top = newnode;
    }

    int pop()
    {
        if(top == NULL)
        {
            cout<<"Stack underflow";
            return 1;
        }

        Node* temp = top;
        int x = temp->data;
        top = top->next;
        delete temp;
        return x;
    }

    int peek()
    {
        if(top == NULL)
        {
            cout<<"Stack underflow";
            return 1;
        }
        return top->data;
    }

    bool empty()
    {
        return top == NULL;
    }
};

int solve(int op1, int op2, char op)
{
    if (op == '+') return op1 + op2;
    if (op == '-') return op1 - op2;
    if (op == '*') return op1 * op2;
    if (op == '/') return op1 / op2;
    if (op == '^') return pow(op1, op2);
    return 0;
}


int priority(char op)
{
    if(op=='+' || op=='-') return 1;
    if(op=='*' || op=='/') return 2;
    if(op=='^') return 3;
    return 0;
}


// Postfix Evaluation
int postfix_Evaluation(char postfix[20])
{
    Stack s;

    for(int i=0; postfix[i]!='\0'; i++)
    {
        char token = postfix[i];

        if(isalpha(token))
        {
            int val;
            cout<<"Enter value of alphabet : ";
            cin>>val;
            s.push(val);
        }
        else if(isdigit(token))
        {
            s.push(token - '0');
        }
        else
        {
            int op2 = s.pop();
            int op1 = s.pop();
            int result = solve(op1,op2,token);
            s.push(result);
        }
    }
    return s.pop();
}


// Prefix Evaluation
int prefix_evaluation(char prefix[20])
{
    Stack s;
    for(int i=strlen(prefix) - 1; i>=0; i--)
    {
        char token = prefix[i];

        if(isalpha(token))
        {
            int val;
            cout<<"Enter value of alphabet : ";
            cin>>val;
            s.push(val);
        }
        else if(isdigit(token))
        {
            s.push(token - '0');
        }
        else
        {
            int op1 = s.pop();
            int op2 = s.pop();
            int result = solve(op1,op2,token);
            s.push(result);
        }
    }
    return s.pop();
}



// Infix to Postfix
void InfixToPost(char infix[20], char postfix[20])
{
    Stack s;
    int j = 0;

    for(int i=0; infix[i]!='\0'; i++)
    {
        char token = infix[i];

        if(isalnum(token))
        {
            postfix[j++] = token;
        }
        else if(token == '(')
        {
            s.push(token);
        }
        else if(token == ')')
        {
            while(!s.empty() && s.peek() != '(')
            {
                postfix[j++] = s.pop();
            }
            s.pop();  // remove '('
        }
        else
        {
            while(!s.empty() && priority(token) <= priority(s.peek()))
            {
                postfix[j++] = s.pop();
            }
            s.push(token);
        }
    }
    while(!s.empty())
    {
        postfix[j++] = s.pop();
    }
    postfix[j] = '\0';
} 

// Reverse String
void reverse(char str[])
{
    int n = strlen(str);
    for(int i=0; i<n/2; i++)
    {
        swap(str[i], str[n-i-1]);
    }
}

// Infix to Prefix
void InfixToPrefix(char infix[20], char prefix[20])
{
    reverse(infix);

    for(int i=0; infix[i]!='\0'; i++)
    {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    char temp[20];
    InfixToPost(infix, temp);

    reverse(temp);
    strcpy(prefix, temp);
}



//Main
int main()
{
    char infix[20], postfix[20], prefix[20];

    cout<<"Enter Infix expression : ";
    cin>>infix;

    InfixToPost(infix, postfix);
    cout<<"Postfix Expression : "<<postfix<<endl;
    cout<<"Result : "<<postfix_Evaluation(postfix)<<endl;

    InfixToPrefix(infix, prefix);
    cout<<"Prefix Expression : "<<prefix<<endl;
    cout<<"Result : "<<prefix_evaluation(prefix)<<endl;

    return 0;
}