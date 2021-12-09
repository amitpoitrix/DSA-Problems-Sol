#include<iostream>
using namespace std;
// Striver Tree Series : L42. Floor in a Binary Search Tree
// Floor of a no. is largest num just equal to or smaller than the given no. key

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
        if(root->data == key){
            floor = root->data;
            return floor;
        }
        else if(root->data < key){
            floor = root->data;
            root = root->right;      // we're moving right becoz we require largest value just smaller than key
        }
        else{   //root->data > Key
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