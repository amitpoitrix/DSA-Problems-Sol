#include<iostream>
using namespace std;
// Striver Tree Series : L53. Largest BST in Binary Tree
// Here we have to result largest size of BST in given BT 

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

// Container of each node
class NodeValue{
public:
    int minValue;
    int maxValue;
    int maxSize;

    NodeValue(int minValue, int maxValue, int maxSize){
        this->minValue = minValue;
        this->maxValue = maxValue;
        this->maxSize = maxSize;
    }
};

class Solution{
private:
    NodeValue largestBSThelper(Node * root){
        if(root == NULL)
            return NodeValue(INT8_MAX, INT8_MIN, 0);
        
        // Here we're using Postorder Traversal - Left Right Root
        auto left = largestBSThelper(root->left);
        auto right = largestBSThelper(root->right);

        // Root
        // Here we'll check whether a subtree is a valid BST or not
        if(left.maxValue < root->data && root->data < right.minValue){
            // Its a valid BST
            return NodeValue(min(root->data, left.minValue), max(root->data, right.maxValue), left.maxSize + right.maxSize + 1);
        }

        // If its not a valid BST than return {-Infinite, +Infinite} so that it'll always be invalid
        return NodeValue(INT8_MIN, INT8_MAX, max(left.maxSize, right.maxSize));
    }
public:
    int largestBST(Node * root){
        return largestBSThelper(root).maxSize;
    }
};

int main(){
    Node * root = new Node(20);
    root->left = new Node(15);
    root->right = new Node(40);
    root->left->left = new Node(14);
    root->left->right = new Node(18);
    root->right->left = new Node(30);
    root->right->right = new Node(60);
    root->left->left->right = new Node(17);
    root->left->right->left = new Node(16);
    root->left->right->right = new Node(19);
    root->right->right->left = new Node(50);

    Solution * sol = new Solution();

    cout <<"Size of Largest BST is " << sol->largestBST(root);

    return 0;
}