#include<iostream>
#include<stack>
using namespace std;
// Striver Tree Series : Leetcode 230. Kth Smallest Element in a BST
// Inorder Traversal of BST is always in sorted order

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

int kthSmallestInBST(Node * root, int k){
    if(root == NULL)
        return -1;
    
    // Here we'll use iterative approach of Inorder Traversal
    stack<Node*> st;
    Node * temp = root;
    int cnt = 0;

    while (true){
        if(temp != NULL){
            st.push(temp);
            temp = temp->left;
        }
        else{
            if(st.empty())
                break;

            temp = st.top();
            st.pop();
            
            // Inorder Print
            cnt++;
            if(cnt == k)
                return temp->data;
            
            temp = temp->right;
        }
    }
    
    return -1;
}

int main(){
    Node * root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);

    int k = 3;
    cout << "3rd Smallest element in BST : " << kthSmallestInBST(root, k);

    return 0;
}