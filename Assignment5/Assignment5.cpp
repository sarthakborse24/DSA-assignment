#include <iostream>
#include <stack>
using namespace std;

struct node
{
    char data;
    node *left;
    node *right;
};

node *createNode(char x)
{
    node *temp = new node;
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' ||
            c == '/' || c == '^');
}

node *buildTree(string postfix)
{
    stack<node *> st;

    for (int i = 0; i < postfix.length(); i++)
    {
        char c = postfix[i];

        if (!isOperator(c))
        {
            st.push(createNode(c));
        }
        else
        {
            node *right = st.top();
            st.pop();

            node *left = st.top();
            st.pop();

            node *temp = createNode(c);

            temp->left = left;
            temp->right = right;

            st.push(temp);
        }
    }

    return st.top();
}

// Recursive Inorder
void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

// Recursive Preorder
void preorder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

// Recursive Postorder
void postorder(node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

// Iterative Inorder
void inorder_iter(node *root)
{
    stack<node *> st;
    node *curr = root;

    while (curr != NULL || !st.empty())
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        cout << curr->data;
        curr = curr->right;
    }
}

// Iterative Preorder
void preorder_iter(node *root)
{
    if (root == NULL)
        return;

    stack<node *> st;
    st.push(root);

    while (!st.empty())
    {
        node *temp = st.top();
        st.pop();

        cout << temp->data;

        if (temp->right)
            st.push(temp->right);

        if (temp->left)
            st.push(temp->left);
    }
}

// Iterative Postorder
void postorder_iter(node *root)
{
    if (root == NULL)
        return;

    stack<node *> st1, st2;

    st1.push(root);

    while (!st1.empty())
    {
        node *temp = st1.top();
        st1.pop();

        st2.push(temp);

        if (temp->left)
            st1.push(temp->left);

        if (temp->right)
            st1.push(temp->right);
    }

    while (!st2.empty())
    {
        cout << st2.top()->data;
        st2.pop();
    }
}

int main()
{
    string postfix;
    node *root;

    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    root = buildTree(postfix);

    cout << "\nRecursive Traversals\n";

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\n\nNon-Recursive Traversals\n";

    cout << "Inorder: ";
    inorder_iter(root);

    cout << "\nPreorder: ";
    preorder_iter(root);

    cout << "\nPostorder: ";
    postorder_iter(root);

    return 0;
}