#include<iostream>
#include<cstring>
#include<cctype>

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

class ExpressionTree
{
    Node* root;

public:

    ExpressionTree()
    {
        root = NULL;
    }

    // Create tree from postfix
    Node* createPostfix(char postfix[])
    {
        Node* stack[100];
        int top = -1;

        for(int i = 0; postfix[i] != '\0'; i++)
        {
            char token = postfix[i];

            Node* newnode = new Node(token);

            // Operand
            if(isalnum(token))
            {
                stack[++top] = newnode;
            }
            else
            {
                // Operator
                newnode->right = stack[top--];
                newnode->left  = stack[top--];

                stack[++top] = newnode;
            }
        }

        root = stack[top];
        return root;
    }

    // Recursive Preorder
    void preorder(Node* temp)
    {
        if(temp != NULL)
        {
            cout << temp->data << " ";
            preorder(temp->left);
            preorder(temp->right);
        }
    }

    // Recursive Inorder
    void inorder(Node* temp)
    {
        if(temp != NULL)
        {
            inorder(temp->left);
            cout << temp->data << " ";
            inorder(temp->right);
        }
    }

    // Recursive Postorder
    void postorder(Node* temp)
    {
        if(temp != NULL)
        {
            postorder(temp->left);
            postorder(temp->right);
            cout << temp->data << " ";
        }
    }

    // Non Recursive Preorder
    void nonRecursivePreorder(Node* temp)
    {
        Node* stack[100];
        int top = -1;

        while(temp != NULL || top >= 0)
        {
            while(temp != NULL)
            {
                cout << temp->data << " ";
                stack[++top] = temp;
                temp = temp->left;
            }

            temp = stack[top--];
            temp = temp->right;
        }
    }

    // Non Recursive Inorder
    void nonRecursiveInorder(Node* temp)
    {
        Node* stack[100];
        int top = -1;

        while(temp != NULL || top >= 0)
        {
            while(temp != NULL)
            {
                stack[++top] = temp;
                temp = temp->left;
            }

            temp = stack[top--];

            cout << temp->data << " ";

            temp = temp->right;
        }
    }

    // Non Recursive Postorder
    void nonRecursivePostorder(Node* temp)
    {
        char post[100];
        int i = 0;

        Node* stack[100];
        int top = -1;

        while(temp != NULL || top >= 0)
        {
            while(temp != NULL)
            {
                stack[++top] = temp;

                post[i++] = temp->data;

                temp = temp->right;
            }

            temp = stack[top--];
            temp = temp->left;
        }

        for(i = strlen(post)-1; i >= 0; i--)
        {
            cout << post[i] << " ";
        }
    }

    Node* getRoot()
    {
        return root;
    }
};

int main()
{
    ExpressionTree obj;

    char postfix[100];

    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    Node* root = obj.createPostfix(postfix);

    cout << "\nRecursive Traversals\n";

    cout << "\nPreorder : ";
    obj.preorder(root);

    cout << "\nInorder : ";
    obj.inorder(root);

    cout << "\nPostorder : ";
    obj.postorder(root);

    cout << "\n\nNon Recursive Traversals\n";

    cout << "\nPreorder : ";
    obj.nonRecursivePreorder(root);

    cout << "\nInorder : ";
    obj.nonRecursiveInorder(root);

    cout << "\nPostorder : ";
    obj.nonRecursivePostorder(root);

    return 0;
}