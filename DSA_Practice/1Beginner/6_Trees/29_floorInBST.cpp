#include<iostream>
using namespace std;
// Striver Tree Series : L42. Floor in a Binary Search Tree
// Floor of a no. is largest num which is smaller than or equal to given no. key

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

// largest value of floor <= key
int floorBST(Node * root, int key){
    int floor = -1;
    if(root == NULL)
        return floor;

    while (root){
        if(key == root->data){
            floor = root->data;
            return floor;
        }
        // Move right if key is greater than current node & store it in variable
        // as we want value to be as large as possible
        else if(key > root->data){
            floor = root->data;
            root = root->right;      
        }
        // Move left if key is smaller than current node
        else{
            root = root->left;
        }
    }
    
    return floor;
}

int main(){
    Node * root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(6);

    int key = 7;
    cout << "Floor of " << key << " is " << floorBST(root, key);

    return 0;
}