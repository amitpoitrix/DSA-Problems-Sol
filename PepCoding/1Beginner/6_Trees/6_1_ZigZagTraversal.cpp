#include<iostream>
#include<queue>
using namespace std;
// Striver Tree series : Leetcode 103. Binary Tree Zigzag Level Order Traversal

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

vector<vector<int>> zigZag(Node * root){
    vector<vector<int>> result;
    if(root == NULL)
        return result;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty()){
        int size = q.size();
        vector<int> row(size);  // here we mention the size of vector because we're assigning the value based on index

        for (int i = 0; i < size; i++){
            Node * temp = q.front();
            q.pop();

            // Finding pos for Node value
            int idx = (leftToRight)? i : size-i-1;
            row[idx] = temp->data;

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }

        leftToRight = !leftToRight;
        result.push_back(row);
    }
    
    return result;
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

    vector<vector<int>> res = zigZag(root);

    for (auto x : res){
        for (auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }
    

    return 0;
}