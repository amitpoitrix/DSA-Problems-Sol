#include<iostream>
#include<stack>
using namespace std;
// Striver Tree Series : Leetcode 230. Kth Smallest Element in a BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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

// Approach 1: Iterative Inorder Traversal
// TC = SC = O(n)
int kthSmallestInBST(Node * root, int k){
    if(root == NULL)
        return 0;
    
    // Here we'll use iterative approach of Inorder Traversal
    stack<Node*> st;
    Node * temp = root;

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
            k--;
            if(k == 0)
                return temp->data;
            
            temp = temp->right;
        }
    }
    
    return 0;
}

// Approach 2: Recursive Inorder Approach
// TC = SC = O(n)
class Solution1 {
public:
    int kthSmallest(Node* root, int k) {
        // Recursive Approach
        if(root == NULL)
            return 0;
        
        // Left
        int left = kthSmallest(root->left, k);
        if(left)
            return left;
        
        // Root - Print Inorder
        k--;
        if(k==0)
            return root->data;
        
        // Right
        int right = kthSmallest(root->right, k);
        if(right)
            return right;
        
        return 0;
    }
};

// Approach 3: Using Morris Traversal(Inorder)
// TC = O(n)
// SC = O(1)
class Solution2 {
public:
    int kthSmallest(Node* root, int k) {
        if(root == NULL)
            return 0;
        
        int ans = 0;
        Node * curr = root;
        while(curr){
            if(curr->left == NULL){
                k--;
                if(k == 0)
                    ans = curr->data;
                
                curr = curr->right;
            }
            
            else{
                Node * prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                
                else{
                    prev->right = NULL;
                    k--;
                    if(k == 0)
                        ans = curr->data;
                    
                    curr = curr->right;
                }
            }
        }
        
        return ans;
    }
};

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