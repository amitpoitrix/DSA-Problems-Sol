#include<iostream>
using namespace std;
// Striver Tree Series : Leetcode 100. Same Tree

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

bool isIdentical(Node * p, Node * q){
    if(p == NULL || q == NULL)
        return p==q;

    return (p->data == q->data) && (isIdentical(p->left, q->left)) && (isIdentical(p->right, q->right)); 
}

int main(){
    Node* p = new Node(-10);
    p->left = new Node(9);
    p->right = new Node(20);
    p->right->left = new Node(15);
    p->right->right = new Node(7);

    Node* q = new Node(-10);
    q->left = new Node(9);
    q->right = new Node(20);
    q->right->left = new Node(15);
    q->right->right = new Node(7);

    if(isIdentical(p, q))
        cout << "Both Binary Tree is Same";
    else
        cout << "Both Binary Tree is Different";

    cout << endl;
    return 0;
}