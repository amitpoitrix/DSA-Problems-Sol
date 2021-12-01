#include<iostream>
using namespace std;
// Striver Tree Series : Diameter of Binary Tree - Max distance btw any two nodes of BT

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

// Here we modified the height() with extra diameter as parameter which is passed as reference
int heightOfBT(Node * root, int &diameter){
    if(root == NULL)
        return 0;

    int leftHeight = heightOfBT(root->left, diameter);
    int rightHeight = heightOfBT(root->right, diameter);

    diameter = max(diameter, leftHeight+rightHeight);

    return 1 + max(leftHeight, rightHeight);
}

// Diameter() - TC - O(n), SC - O(n)
int diameterOfBT(Node * root){
    int diameter = 0;
    int height = heightOfBT(root, diameter);
    return diameter;
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

    cout << "Diameter of Binary Tree : " << diameterOfBT(root);

    cout << endl;
    return 0;
}