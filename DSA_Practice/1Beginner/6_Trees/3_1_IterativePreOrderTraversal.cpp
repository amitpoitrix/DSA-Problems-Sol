#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// Striver Tree Series : L9 Iterative PreOrder Traversal (Leetcode ques 144)
// TC - O(n) , SC - O(n)
// Preorder Sol - 10 20 40 70 80 50 30 60

// Algo: 
// DFS - Depth First Search - PreOrder Traversal (Root Left Right) using STACK
// 1. For DFS PreOrder Traversal  we'll use Stack and first insert root into it & then run loop till stack is not empty
// 2. We'll take the top() element & store this  top() element in res to be return and find its corresponding left & right 
// elements if exist.
// 3. First we'll insert right elment and than left element onto stack becoz of its LIFO properties.

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

vector<int> iterativePreOrder(Node * root){
    vector<int> preorder;
    if(root == NULL)
        return preorder;
    
    // We use stack for implementing iterative approach of PreOrder Traversal
    stack<Node*> st;
    st.push(root);

    while (!st.empty()){
        Node * temp = st.top();
        st.pop();

        preorder.push_back(temp->data);

        // First will push right side of tree data
        if(temp->right)
            st.push(temp->right);
        // Now we'll push left side tree data
        if(temp->left)
            st.push(temp->left);
    }

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

    vector<int> res = iterativePreOrder(root);

    for (auto x : res){
        cout << x << " ";
    }

    return 0;
}

