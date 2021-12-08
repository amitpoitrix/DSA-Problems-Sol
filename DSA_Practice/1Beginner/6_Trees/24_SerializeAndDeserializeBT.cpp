#include<bits/stdc++.h>
using namespace std;
// Striver Tree Series : Leetcode 297. Serialize and Deserialize Binary Tree
// TC - O(N), SC - O(N)

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

// Serialization of a Binary Tree -> means convert a BT into string
string serializeBT(Node * root){
    if(root == NULL)
        return "";
    
    string str = "";
    queue<Node*> q;
    q.push(root);

    while (!q.empty()){
        Node * currNode = q.front();
        q.pop();

        // Now appending the BT nodes->data to the string
        if(currNode == NULL)
            str.append("#,");
        else
            str.append(to_string(currNode->data) + ",");

        // Now pushing the left & right child of current node and we'll also push if any child is NULL 
        if(currNode != NULL){
            q.push(currNode->left);
            q.push(currNode->right);
        }
    }

    return str;
}

// Deserialize a Binary Tree -> means convert a string back to BT
Node * deserializeBT(string data){
    if(data.size() == 0)
        return NULL;
    
    // Basically stringstream is being used in order to separate the string and we want its substring part
    stringstream s(data);   // s << data   --> means data is being added to stringstream object 's'
    string str;
    getline(s, str, ',');   // here s act as cin and here we are getting the first string value before ',' for root node

    Node * root = new Node(stoi(str));

    queue<Node*> q;     // Becoz we are using BFS Traversal
    q.push(root);

    while (!q.empty()){
        Node * currNode = q.front();
        q.pop();

        // Getting another substring before ',' for left node
        getline(s, str, ',');
        if(str == "#")
            currNode->left = NULL;
        else{
            Node * leftNode = new Node(stoi(str));
            currNode->left = leftNode;
            q.push(currNode->left);
        }

        // Getting another substring before ',' for right node
        getline(s, str, ',');
        if(str == "#")
            currNode->right = NULL;
        else{
            Node * rightNode = new Node(stoi(str));
            currNode->right = rightNode;
            q.push(currNode->right);
        }
    }
    
    return root;
}

// InOrder Display of Binary Tree
void displayBT(Node * root){
    if(root == NULL)
        return;
    
    displayBT(root->left);
    cout << root->data << " ";
    displayBT(root->right);
}

int main(){
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    displayBT(root);
    cout << endl;

    string rootString = serializeBT(root);
    cout << rootString << endl;     // Just for Debugging Purpose
    Node * result = deserializeBT(rootString);

    displayBT(result);

    cout << endl;
    return 0;
}