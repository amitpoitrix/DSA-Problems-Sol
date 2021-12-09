#include<iostream>
#include<stack>
using namespace std;
// Striver Tree Series : Leetcode 114. Flatten Binary Tree to Linked List 

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

// Approach 1 : Recursive Approach; TC - O(N) & SC - O(N)
void recursiveFlattenBT(Node * root, Node * &prev){
    if(root == NULL)
        return;

    // First we'll go to right part of subtree
    recursiveFlattenBT(root->right, prev);
    recursiveFlattenBT(root->left, prev);

    root->right = prev;     // Assigning prev node to current node right part 
    root->left = NULL;      // And its left part as always NULL
    prev = root;    // Assigning current node to prev
}

Node * flattenBT(Node * root){
    Node * prev = NULL;
    recursiveFlattenBT(root, prev);
    return root;
}


// Approach 2 : Iterative Approach; TC - O(N) & SC - O(N)
void iterativeFlattenBT(Node * root){
    if(root == NULL)
        return;
    // For Iterative Approach we'll use the stack - LIFO
    stack<Node*> st;
    st.push(root);

    while (!st.empty()){
        Node * cur = st.top();
        st.pop();

        // First we'll push the right child node and than the left child node
        if(cur->right)
            st.push(cur->right);

        if(cur->left)
            st.push(cur->left);

        if(!st.empty())
            cur->right = st.top();
        
        cur->left = NULL;   // Left side of current node always points to NULL
    }

    return;
}


// Approach 3 : Using Morris Traversal; TC - O(N) & SC - O(1)
void morrisFlattenBT(Node * root){
    Node * cur = root;
    while (cur != NULL){
        // Checking if left exist
        if(cur->left){
            Node * prev = cur->left;
            // Go to extreme right of left subtree
            while (prev->right){
                prev = prev->right;
            }

            prev->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;   // Always making left part of current node to NULL
        }
        // Move current node to right always
        cur = cur->right;
    }
    return;
}

// InOrder Display of Binary Tree
void displayInorder(Node * root){
    if(root == NULL)
        return;
    
    displayInorder(root->left);
    cout << root->data << " ";
    displayInorder(root->right);
}

int main(){
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    // displayInorder(root);
    // cout << endl;
    // Node * result1 = flattenBT(root);
    // displayInorder(result1);
    // cout << endl;

    // displayInorder(root);
    // cout << endl;
    // iterativeFlattenBT(root);
    // displayInorder(root);
    // cout << endl;

    displayInorder(root);
    cout << endl;
    morrisFlattenBT(root);
    displayInorder(root);
    cout << endl;

    return 0;
}