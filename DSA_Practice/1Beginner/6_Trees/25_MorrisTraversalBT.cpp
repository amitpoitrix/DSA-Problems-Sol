#include<iostream>
#include<vector>
using namespace std;
// Striver Tree Series : Morris Traversal - Inorder
// TC - O(N) & SC - O(1)

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

// Inorder Morris Traversal - Here we'll use the concept of threaded Binary Trees
vector<int> inorderMorrisTraversal(Node * root){
    vector<int> inorder;
    if(root == NULL)
        return inorder;
    
    Node * cur = root;  // storing the root to some variable node so that root won't get affect

    while (cur != NULL){
        if(cur->left == NULL){
            inorder.push_back(cur->data);   // Print
            cur = cur->right;
        }
        else{
            Node * next = cur->left;
            // Here we'll move to the rightmost node of subtree that will make thread connection to Root(current) Node
            while (next->right && next->right != cur){
                next = next->right;
            }
            // edge case
            if(next->right == NULL){
                next->right = cur;  // Making thread connection to Root(Current) Node
                cur = cur->left;
            }
            else{   // this is the case when next->right points to current node itself so we'll break that thread over here
                next->right = NULL; // Breaking the thread connection
                //here you're on the Left most side of the subtree
                inorder.push_back(cur->data);   // for InOrder Traversal - Left Root Right 
                cur = cur->right;
            }
        }
    }

    return inorder;
}


// PreOrder Morris Traversal - Here we'll use the concept of threaded Binary Trees
vector<int> preorderMorrisTraversal(Node * root){
    vector<int> preorder;
    if(root == NULL)
        return preorder;
    
    Node * cur = root;  

    while (cur != NULL){
        if(cur->left == NULL){
            preorder.push_back(cur->data);   // Print
            cur = cur->right;
        }
        else{
            Node * next = cur->left;

            while (next->right && next->right != cur){
                next = next->right;
            }
            // edge case
            if(next->right == NULL){
                next->right = cur;
                preorder.push_back(cur->data);  // for PreOrder Traversal - Root Left Right 
                cur = cur->left;
            }
            else{   
                next->right = NULL;
                cur = cur->right;
            }
        }
    }

    return preorder;
}


// InOrder Display of Binary Tree
void displayInorder(Node * root){
    if(root == NULL)
        return;
    
    displayInorder(root->left);
    cout << root->data << " ";
    displayInorder(root->right);
}

// PreOrder Display of Binary Tree
void displayPreOrder(Node * root){
    if(root == NULL)
        return;
    
    cout << root->data << " ";
    displayPreOrder(root->left);
    displayPreOrder(root->right);
}

int main(){
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    // Inorder Traversal
    displayInorder(root);
    cout << endl;
    vector<int> resultInOrder = inorderMorrisTraversal(root);
    for (auto x : resultInOrder)
        cout << x << " ";
    cout << endl;


    // PreOrder Traversal
    displayPreOrder(root);
    cout << endl;
    vector<int> resultPreOrder = preorderMorrisTraversal(root);
    for (auto x : resultPreOrder)
        cout << x << " ";
    cout << endl;

    return 0;
}