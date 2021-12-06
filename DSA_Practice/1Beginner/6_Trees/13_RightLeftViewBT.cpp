#include<iostream>
#include<vector>
using namespace std;
// striver Tree series : Leetcode 199. Binary Tree Right Side View

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

void rightViewTraversal(Node * root, int level, vector<int> &result){
    if(root == NULL)
        return;
    
    // Smart Move : Checking if DS size is same as level No. starting from 0
    if(level == result.size())
        result.push_back(root->data);
    
    // for Right View first we'll go right and than left
    rightViewTraversal(root->right, level+1, result);
    rightViewTraversal(root->left, level+1, result);
}

vector<int> rightViewBT(Node * root){
    vector<int> result;
    rightViewTraversal(root, 0, result);    // Passing Initial level as 0
    return result;
}

int main(){
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> res = rightViewBT(root);

    for (auto x : res){
        cout << x << " ";
    }
    
    return 0;
}