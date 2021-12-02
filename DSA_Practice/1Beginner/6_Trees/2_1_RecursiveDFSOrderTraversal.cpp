#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// Striver Tree Series : Recursive PreOrder, InOrder & PostOrder Traversal (Root -> Left -> Right) (Leetcode ques 144)
// TC - O(n) , SC - O(n)
// Preorder Sol - 10 20 40 70 80 50 30 60 

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

// Passing preorder vector as reference so that changes made here will reflect in the calling function
void dfs(Node * root, vector<int> &preorder){
    if(root == NULL)
        return;
    
    // For InOrder and PostOrder everything is same as PreOrder just change the print order
    preorder.push_back(root->data); // Print Root
    dfs(root->left, preorder);  // Move Left
    dfs(root->right, preorder); // Move Right
}

vector<int> recOrderTraversal(Node * root){
    vector<int> preorder;
    dfs(root, preorder);
    return preorder;
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

    vector<int> res = recOrderTraversal(root);

    for (auto x : res){
        cout << x << " ";
    }

    return 0;
}

