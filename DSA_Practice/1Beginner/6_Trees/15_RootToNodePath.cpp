#include<iostream>
#include<vector>
using namespace std;
// striver Tree series : Print Root To Node(i.e., Leaf Node) Path

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

bool rootNodePath(Node * root, vector<int> &result, int node){
    // If root is NULL than there is no path to node
    if(root == NULL)
        return false;

    // else just insert the node data in the resultant vector
    result.push_back(root->data);

    // check if the node data is the destination node
    if(root->data == node)
        return true;

    // check either on the left or right is dest. node is there
    if(rootNodePath(root->left, result, node) || rootNodePath(root->right, result, node))
        return true;

    // if dest. node is not there either on left or right than remove that node and return false
    result.pop_back();
    return false;
}

vector<int> rootToNodePath(Node * root, int node){
    vector<int> result;
    if(root == NULL)
        return result;
    
    bool path = rootNodePath(root, result, node);

    return result;
}

int main(){
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    vector<int> res = rootToNodePath(root, 7);

    for (auto x : res){
        cout << x << " ";
    }
    
    return 0;
}