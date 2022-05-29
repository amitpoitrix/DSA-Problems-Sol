#include<iostream>
#include<stack>
using namespace std;
// Striver Tree Series : Leetcode 653. Two Sum IV - Input as a BST
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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
    stack<Node*> st;
    // If reverse = true -- before() - right pointer(right most node)
    // If reverse = false -- next() - left pointer(left most node)
    bool reverse = true;   

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
        
        // Creating left object(pointer) - next()
        BSTIterator * l = new BSTIterator(root, false);
        // Creating right object(pointer) - before()
        BSTIterator * r = new BSTIterator(root, true); 

        int i = l->next();  // next() points by left pointer
        int j = r->next();  // before() points by right pointer

        while (i < j){
            if(i+j == k)
                return true;

            // If sum is greater than reduce(move) right pointer(j): before()
            else if(i+j > k)
                j = r->next();
            // else if sum is smaller than increase(move) left pointer(i): next()
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