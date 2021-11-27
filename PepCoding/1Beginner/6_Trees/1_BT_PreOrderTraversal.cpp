#include<iostream>
using namespace std;
// CM - Binary Tree - Pre Order Traversal -> Root -> Left -> right
// DFS - Depth First Search Technique
// Input - 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
// PreOrder - 1 2 4 5 7 3 6 
// InOrder - 4 2 7 5 1 3 6
// PostOrder - 4 7 5 2 6 3 1

// Node/Element Structure of Binary Tree
class Node{
public:
    int data;
    Node * left;    // stores the address of Left Subtree
    Node * right;   // stores the address of right Subtree

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

// PreOrder build of Tree - Root -> Left -> Right
Node * buildTree(){
    int d;
    cin >> d;

    if(d == -1)
        return NULL;
    
    Node * n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

// Printing PreOrder Traversal
void printPreorder(Node * root){
    if(root == NULL)
        return;
    
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// Printing InOrder Traversal
void printInorder(Node * root){
    if(root == NULL)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// Printing PostOrder Traversal (Imp : As its been use a lot as its a Bottom Up Approach)
void printPostorder(Node * root){
    if(root == NULL)
        return;
    
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

int main(){
    Node * root = buildTree();
    printPreorder(root);
    cout << endl;

    printInorder(root);
    cout << endl;

    printPostorder(root);
    cout << endl;

    return 0;
}