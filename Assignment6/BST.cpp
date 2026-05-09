#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left,*right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

class BST{
public:
    Node *root;

    BST(){
        root = NULL;
    }

    Node *insert(Node *root , int val){
        if (root == NULL)
        {
            return new Node(val);
        }

        if(root->data > val){
            root->left = insert(root->left , val);
        }
        else if(root->data < val){
            root->right = insert(root->right , val);
        }
        return root;
    }

    void searchkey(Node *root , int key){
        if(root == NULL)
            cout<<"not found";

        if(root->data == key){
            cout<<"element found!!";
        }    
        else if(root->data > key){
            searchkey(root->left , key);
        }
        else{
            searchkey(root->right , key);
        }
    }
};

int main(){

}