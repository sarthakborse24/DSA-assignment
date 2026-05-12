#include <iostream>
using namespace std;
// Node structure for each order
class Node
{
public:
    int id;
    string name, food;
    float amount;
    Node *left, *right;
    // constructor
    Node(int i, string n, string f, float a)
    {
        id = i;
        name = n;
        food = f;
        amount = a;
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

    // Insert Order (simple iterative logic)
    Node *insert(Node *root, int id, string name, string food, float amount)
    {
        Node *newNode = new Node(id, name, food, amount);

        // If tree is empty
        if (root == NULL)
            return newNode;

        // Insert into left subtree
        if (id < root->id)
        {
            root->left = insert(root->left, id, name, food, amount);
        }
        // Insert into right subtree
        else if (id > root->id)
        {
            root->right = insert(root->right, id, name, food, amount);
        }

        // Return unchanged root pointer
        return root;
    }
    
    // Search Order
    void search(Node *root, int id)
    {
        Node *curr = root;
        while (curr != NULL)
        {
            if (id == curr->id)
            {
                cout << "\nOrder Found\n";
                cout << "ID: " << curr->id;

                cout << "\nName: " << curr->name;
                cout << "\nFood: " << curr->food;
                cout << "\nAmount: " << curr->amount << endl;
                return;
            }
            else if (id < curr->id)
                curr = curr->left;
            else
                curr = curr->right;
        }
        cout << "Order not found\n";
    }
    // Find minimum (used in delete)
    Node *findMin(Node *root)
    {
        while (root->left != NULL)
            root = root->left;
        return root;
    }
    // Delete Order
    Node *deleteNode(Node *root, int id)
    {
        if (root == NULL)
        {
            cout << "Order not found\n";
            return root;
        }
        if (id < root->id)
            root->left = deleteNode(root->left, id);
        else if (id > root->id)
            root->right = deleteNode(root->right, id);
        else
        {
            // case 1: no child
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }

            // case 2: one child
            if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            // case 3: two children
            Node *temp = findMin(root->right);
            root->id = temp->id;
            root->name = temp->name;
            root->food = temp->food;
            root->amount = temp->amount;
            root->right = deleteNode(root->right, temp->id);
        }
        return root;
    }
    // Display (Inorder - sorted)
    void display(Node *root)
    {
        if (root == NULL)
            return;
        display(root->left);
        cout << "\nID: " << root->id
             << " | Name: " << root->name
             << " | Food: " << root->food
             << " | Amount: " << root->amount;
        display(root->right);
    }
    // Count total orders

    int count(Node *root)
    {
        if (root == NULL)
            return 0;
        return 1 + count(root->left) + count(root->right);
    }
    
    // Find highest bill
    float maxBill(Node *root)
    {
        if (root == NULL)
            return 0;
        float left = maxBill(root->left);
        float right = maxBill(root->right);
        float maxVal = root->amount;
        if (left > maxVal)
            maxVal = left;
        if (right > maxVal)
            maxVal = right;
        return maxVal;
    }
};
int main()
{
    BST t;
    Node *root = NULL;
    int choice, id;
    string name, food;
    float amount;
    do
    {
        cout << "\n\n--- MENU ---";
        cout << "\n1. Insert";
        cout << "\n2. Search";
        cout << "\n3. Delete";
        cout << "\n4. Display";
        cout << "\n5. Count";
        cout << "\n6. Highest Bill";

        cout << "\n7. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Food: ";
            cin >> food;
            cout << "Enter Amount: ";
            cin >> amount;
            root = t.insert(root, id, name, food, amount);
            cout << "Order inserted\n";
            break;
        case 2:
            cout << "Enter ID to search: ";
            cin >> id;
            t.search(root, id);
            break;
        case 3:
            cout << "Enter ID to delete: ";
            cin >> id;
            root = t.deleteNode(root, id);
            break;
        case 4:
            cout << "\nAll Orders:";
            t.display(root);
            break;
        case 5:
            cout << "Total Orders: " << t.count(root);
            break;
        case 6:
            cout << "Highest Bill: " << t.maxBill(root);

            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice";
        }
    } while (choice != 7);
    return 0;
}