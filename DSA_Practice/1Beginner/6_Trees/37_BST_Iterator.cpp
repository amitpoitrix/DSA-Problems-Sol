#include<iostream>
#include<stack>
using namespace std;
// Striver Tree Series : Leetcode 173. Binary Search Tree Iterator
// TC - O(1) - As On Average there might be n elements in the stack and there might be n such next() calls so n/n ~ 1
// SC - O(H) - H - Height of Tree - O(logN) (base 2)

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

// Inorder BST - Left Root Right
// Logic - We're going to extreme left as well as pushing element in the stack & than printing it and than move right and going 
// to extreme along with pushing the element in stack
class BSTIterator{
    // creating a stack containg nodes in Private
    stack<Node*> st;
    // Function to push all left side nodes on stack
    void pushAll(Node * root){
        while (root != NULL){
            st.push(root);
            root = root->left;
        }
    }

public:
    // Constructor
    BSTIterator(Node * root){
        pushAll(root);
    }

    // next() function  
    int next(){
        Node * temp = st.top();
        st.pop();
        if(temp->right)
            pushAll(temp->right);

        return temp->data;
    }

    // hasNext() function
    bool hasNext(){
        return !st.empty();
    }
};


int main(){
    Node * root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->right->left = new Node(9);
    root->right->right = new Node(20);

    BSTIterator * obj = new BSTIterator(root);
    cout << obj->next() << endl;
    cout << obj->next() << endl;
    cout << obj->hasNext() << endl;
    cout << obj->next() << endl;
    cout << obj->hasNext() << endl;
    cout << obj->next() << endl;
    cout << obj->hasNext() << endl;
    cout << obj->next() << endl;
    cout << obj->hasNext() << endl;

    return 0;
}