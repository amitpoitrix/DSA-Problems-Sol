#include<iostream>
#include<queue>
using namespace std;
// CM - Binary Tree - Level Order Print
// Here the Input is given in PreOrder Manner
// Input - 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
// Output 
// 1
// 2 3
// 4 5 6
// 7

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

// Level Order Printing
void levelOrderPrint(Node * root){
    // we'll use Queue data structure specially because of it FIFO Properties
    queue<Node*> q; // here queue is of type Node * (Pointer) as it will use to store address of child node
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        Node * temp = q.front();
        if(temp == NULL){
            cout << endl;   // New Line
            q.pop();
            // Edge Case - If stack goes empty after poping last NULL node
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            // If temp is not NULL than poping & printing the element
            q.pop();
            cout << temp->data << " ";
            // If Left child exist in temp than push it into the stack
            if(temp->left)
                q.push(temp->left);

            // If right child exist in temp than push it into the stack
            if(temp->right)
                q.push(temp->right);
        }
    }
    
    return;
}

int main(){
    Node * root = buildTree();
    levelOrderPrint(root);

    return 0;
}