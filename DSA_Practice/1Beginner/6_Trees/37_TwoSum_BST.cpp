#include<iostream>
#include<stack>
using namespace std;
// Striver Tree Series : Leetcode 653. Two Sum IV - Input as a BST
// Return true if is there any two different nodes whose sum is equal to given k
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

// BST Iterator for both next() & before()
class BSTIterator{
    // Private data members
    stack<Node*> st;

    void pushAll(Node * root){
        while (root != NULL){
            if(!reverse){   // next() - so we'll push all left
                st.push(root);
                root = root->left;  // left left left
            }
            else{   // before() - so we'll push all right
                st.push(root);
                root = root->right; // right right right
            }
        }
    }
    // If reverse = true -- before() - last node(right most node)
    // If reverse = false -- next() - start node(left most node)
    bool reverse = true;     

public:
    // Constructor
    BSTIterator(Node * root, bool reverse){
        this->reverse = reverse;
        pushAll(root);
    }

    // next() function will perform both next() & before() functionality
    int next(){
        Node * temp = st.top();
        st.pop();
        if(!reverse)    // next()
            pushAll(temp->right);
        else            // before()
            pushAll(temp->left);

        return temp->data;
    }

    // hasNext() function will perform both hasNext() & hasBefore() functionality
    bool hasNext(){
        return !st.empty();
    }
};

class Solution{
public:
    bool findTarget(Node * root, int k){
        if(root == NULL)
            return false;
        
        BSTIterator * l = new BSTIterator(root, false);   // next()
        BSTIterator * r = new BSTIterator(root, true);  // before()

        int i = l->next();
        int j = r->next();  // before()

        while (i < j){
            if(i+j == k)
                return true;
            else if(i+j > k)
                j = r->next();
            else
                i = l->next();
        }

        return false; 
    }
};


int main(){
    Node * root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(2);
    root->right->right = new Node(7);

    int k = 9;

    Solution * sol = new Solution();

    if(sol->findTarget(root, k))
        cout << "True";
    else
        cout << "false";

    return 0;
}