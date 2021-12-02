#include<bits/stdc++.h>
using namespace std;
// striver Tree series : Leetcode 987. Vertical Order Traversal of a Binary Tree

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

vector<vector<int>> verticalTraversal(Node * root){
    vector<vector<int>> result;
    if(root == NULL)
        return result;

    map<int, map<int, multiset<int>>> nodes;

    queue<pair<Node*, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while (!q.empty()){
        auto p = q.front();
        q.pop();

        Node * node = p.first;
        int x = p.second.first; // verticals
        int y = p.second.second;    // Levels

        nodes[x][y].insert(node->data); // Print i.e., Inserting nodes data in multiset

        if(node->left)
            q.push({node->left, {x-1, y+1}});
        
        if(node->right)
            q.push({node->right, {x+1, y+1}});
    }

    // Finally inserting the Nodes data arrange in Vertical order into result vector
    for (auto p : nodes){
        vector<int> col;
        for (auto q : p.second){
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        result.push_back(col);
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

    vector<vector<int>> res = verticalTraversal(root);

    for (auto x : res){
        for (auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}