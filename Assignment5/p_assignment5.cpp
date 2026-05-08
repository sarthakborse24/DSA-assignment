#include <iostream>
#include <cctype>
using namespace std;

class Node
{
public:
    char data;
    Node *left, *right;

    Node(char val)
    {
        data = val;
        left = right = NULL;
    }
};

class expressiontree
{
public:
    Node *root;

    expressiontree()
    {
        root = NULL;
    }

    Node *createpostfix(char postfix[])
    {

        Node *stack[100];
        int Top = -1;

        for (int i = 0; postfix != '\0'; i++)
        {

            char token = postfix[i];
            Node *newnode = new Node(token);

            if (isalnum(token))
            {
                stack[++Top] = newnode;
            }
            else
            {
                newnode->right = stack[Top--];
                newnode->left = stack[Top--];

                stack[++Top] = newnode;
            }
        }
        root = stack[Top];
        return root;
    }

    void preorder(Node *temp){
        cout<<temp->data<<" ";
        preorder(temp->left);
        preorder(temp->right);
    }
    void inorder(Node *temp){
        preorder(temp->left);
        cout<<temp->data<<" ";
        preorder(temp->right);
    }
    void postorder(Node *temp){
        preorder(temp->left);
        preorder(temp->right);
        cout<<temp->data<<" ";
    }
    
};

int main()
{
    expressiontree obj ;
    char postfix[100];


}