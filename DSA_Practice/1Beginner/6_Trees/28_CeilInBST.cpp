#include<iostream>
using namespace std;
// Striver Tree Series : L41. Ceil in a Binary Search Tree
// Ceil of a no. is smallest num just equal to or greater than the given no.

struct Node{
    int data;
    Node * left;
    Node * right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// smallest value of ceil >= key
int ceilBST(Node * root, int key){
    int ceil = -1;
    if(root == NULL)
        return ceil;

    while (root){
        if(root->data == key){
            ceil = root->data;
            return ceil;
        }
        else if(root->data < key)
            root = root->right;
        else{   //root->data > key
            ceil = root->data;
            root = root->left;  // we're moving left becoz we require smallest value just greater than key
        }
    }
    
    return ceil;
}

int main(){
    Node * root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right->left = new Node(13);

    int key = 12;
    cout << "Ceil of " << key << " is " << ceilBST(root, key);

    return 0;
}