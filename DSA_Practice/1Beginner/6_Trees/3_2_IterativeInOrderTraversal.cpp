#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// Striver Tree Series : Iterative InOrder Traversal - Left -> Root -> Right
// TC - O(n) , SC - O(n)
// InOrder Sol - 70 40 80 20 50 10 60 30

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

vector<int> iterativeInOrder(Node * root){
    vector<int> inorder;
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
            inorder.push_back(temp->data);
            temp = temp->right;
        }   
    }
    
    return inorder;
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

    vector<int> res = iterativeInOrder(root);

    for (auto x : res){
        cout << x << " ";
    }

    return 0;
}

