#include<bits/stdc++.h>
using namespace std;
// striver Tree series : Vertical Order Traversal of a Binary Tree
// Leetcode 987: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
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

// Using BFS
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

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// Using DFS
class Solution {
private:
    void dfs(TreeNode * root, int vertical, int level, map<int, map<int, multiset<int>>> &nodes){
        if(root){
            // inserting nodes into multiset map
            nodes[vertical][level].insert(root->val);
            
            dfs(root->left, vertical-1, level+1, nodes);
            dfs(root->right, vertical+1, level+1, nodes);
        }
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // vertical -> level -> multinodes
        map<int, map<int, multiset<int>>> nodes;
        // dfs recursive call
        dfs(root, 0, 0, nodes);
        vector<vector<int>> res;
        // for each vertical x
        for(auto x: nodes){
            vector<int> col;
            // for each level y of vertical x
            for(auto y: x.second){
                col.insert(col.end(), y.second.begin(), y.second.end());
            }
            // Inserting col nodes into res after getting all nodes value in particular vertical
            res.push_back(col);
        }
        
        return res;
    }
};

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