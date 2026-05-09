#include <iostream>
#include <cctype>
#include <cstring>
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

        for (int i = 0; postfix[i] != '\0'; i++)
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

    // Recursive

    void preorder(Node *temp)
    {
        if (temp == NULL)
            return;
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
    void inorder(Node *temp)
    {
        if (temp == NULL)
            return;
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
    void postorder(Node *temp)
    {
        if (temp == NULL)
            return;
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }

    // non Recursive

    void nonRecursivepreorder(Node *temp)
    {
        Node *stack[100];
        int Top = -1;
        while (temp != NULL || Top >= 0)
        {
            while (temp != NULL)
            {
                cout << temp->data << " ";
                stack[++Top] = temp;
                temp = temp->left;
            }

            temp = stack[Top--];
            temp = temp->right;
        }
    }

    void nonrecursiveinorder(Node *temp)
    {
        Node *stack[100];
        int Top = -1;

        while (temp != NULL || Top >= 0)
        {
            while (temp != NULL)
            {
                stack[++Top] = temp;
                temp = temp->left;
            }
            temp = stack[Top--];
            cout << temp->data << " ";
            temp = temp->right;
        }
    }

    void nonrecursivepostorder(Node *temp)
    {
        char rev[100];
        int i = 0;

        Node *stack[100];
        int Top = -1;

        while (temp != NULL || Top >= 0)
        {
            while (temp != NULL)
            {
                stack[++Top] = temp;
                rev[i++] = temp->data;
                temp = temp->right;
            }
            temp = stack[Top--];
            temp = temp->left;
        }

        // for(int i = strlen(rev) ; i >= 0 ; i--){
        //     cout << rev[i]<<" ";
        // }

        rev[i] = '\0'; // add this after the while loop
        for (int j = i - 1; j >= 0; j--)
            cout << rev[j] << " ";
    }
};

int main()
{
    expressiontree obj;
    char postfix[100];

    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    Node *root = obj.createpostfix(postfix);

    cout << "\nRecursive Traversals\n";

    cout << "\nPreorder : ";
    obj.preorder(root);

    cout << "\nInorder : ";
    obj.inorder(root);

    cout << "\nPostorder : ";
    obj.postorder(root);

    cout << "\n\nNon Recursive Traversals\n";

    cout << "\nPreorder : ";
    obj.nonRecursivepreorder(root);

    cout << "\nInorder : ";
    obj.nonrecursiveinorder(root);

    cout << "\nPostorder : ";
    obj.nonrecursivepostorder(root);

    return 0;
}