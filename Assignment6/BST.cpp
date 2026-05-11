#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class BST
{
public:
    Node *root;

    BST()
    {
        root = NULL;
    }

    Node *insert(Node *root, int val)
    {
        if (root == NULL)
        {
            return new Node(val);
        }

        if (root->data > val)
        {
            root->left = insert(root->left, val);
        }
        else if (root->data < val)
        {
            root->right = insert(root->right, val);
        }
        return root;
    }

    void searchkey(Node *root, int key)
    {
        if (root == NULL)
            cout << "not found";

        if (root->data == key)
        {
            cout << "element found!!";
        }
        else if (root->data > key)
        {
            searchkey(root->left, key);
        }
        else
        {
            searchkey(root->right, key);
        }
    }

    Node *minivalue(Node *root)
    {
        Node *current = root;

        while (current && current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    Node *deletenode(Node *root, int key)
    {
        if (root == NULL)
        {
            return root;
        }
        if (key < root->data)
        {
            root->left = deletenode(root->left, key);
        }
        else if (key < root->data)
        {
            root->right = deletenode(root->right, key);
        }
        // found the element
        else
        {
            // one child
            if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            // two child

            Node *temp = minivalue(root->right);
            root->data = temp->data;

            root->right = deletenode(root->right, temp->data);
        }
    }

    void Display(Node *root)
    {
        if (root != NULL)
        {
            Display(root->left);
            cout << root->data << " ";
            Display(root->right);
        }
    }
};

int main()
{
}