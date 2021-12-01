#include<iostream>
using namespace std;
// Striver Tree Series : Check Balanced Binary Tree
// Condition : If Height of any tree or subtree is > 1 than that tree is not balanced

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

// Height of Binary Tree
int heightOfTree(Node * root){
    if(root == NULL)
        return 0;

    int leftHeight = heightOfTree(root->left);
    if(leftHeight == -1)
        return -1;
    
    int rightHeight = heightOfTree(root->right);
    if(rightHeight == -1)
        return -1;

    if(abs(leftHeight - rightHeight) > 1)
        return -1;

    return 1 + max(leftHeight, rightHeight);
}

// checking if Binary tree is balanced or not
bool balancedBT(Node * root){
    return heightOfTree(root) != -1; 
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->left->left->left = new Node(70);
    root->left->left->right = new Node(80);

    if(balancedBT(root))
        cout << "Its a Balanced Binary Tree";
    else
        cout << "Its not a Balanced Binary Tree";

    cout << endl;
    return 0;
}