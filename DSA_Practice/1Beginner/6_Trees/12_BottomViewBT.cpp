#include<bits/stdc++.h>
using namespace std;
// striver Tree series : Bottom View of Binary Tree
// Goodnotes

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

// we are using Level Order Traversal instead of normal recursive InOrder, PreOrder or PostOrder approach
// Recursive will not work as we need to put some extra logic
vector<int> topViewBT(Node * root){
    vector<int> result;
    if(root == NULL)
        return result;

    map<int, int> mp;

    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()){
        auto it = q.front();
        q.pop();

        Node * node = it.first;
        int line = it.second;

        mp[line] = node->data;

        if(node->left)
            q.push({node->left, line-1});

        if(node->right)
            q.push({node->right, line+1});
    }
    
    // Now inserting the node->data into result vector
    for (auto x : mp){
        result.push_back(x.second);
    }
     
    return result;
}

int main(){
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->right->left->right = new Node(9);

    vector<int> res = topViewBT(root);

    for (auto x : res){
        cout << x << " ";
    }

    cout << endl;
    return 0;
}