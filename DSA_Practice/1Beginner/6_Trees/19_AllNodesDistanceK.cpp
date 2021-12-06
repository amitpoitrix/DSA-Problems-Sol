#include<bits/stdc++.h>
using namespace std;
// Striver Tree series : Leetcode 863. All Nodes Distance K in Binary Tree 

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

// Creating a Hash Map where Childr Node being pointed by Parent Node and unordered_map should be pass as reference
// Child_Node -> Parent_Node and this hash map is being done in order to move upward
void markParent(Node * root, Node * target, unordered_map<Node*, Node*> &parent_mark){
    // Here we're using the BFS traversal for creating child->parent hash map
    if(root == NULL)
        return;
    
    queue<Node*> q;
    q.push(root);

    while (!q.empty()){
        Node * current = q.front();
        q.pop();

        if(current->left){
            q.push(current->left);
            parent_mark[current->left] = current;
        }

        if(current->right){
            q.push(current->right);
            parent_mark[current->right] = current;
        }
    }
    
    return;
}

vector<int> nodesAtDistanceK(Node * root, Node * target, int k){
    vector<int> result;
    if(root == NULL)
        return result;

    unordered_map<Node*, Node*> parent_mark;    // child -> parent
    markParent(root, target, parent_mark);

    unordered_map<Node*, bool> visited;     // visited Hash Table to check whether node is already visited or not
    visited[target] = true;

    queue<Node*> q;     // As we're doing BFS traversal from target node
    q.push(target);

    int dist = 0;

    while (!q.empty()){
        if(dist == k)
            break;
        dist++;

        int size = q.size();
        for (int i = 0; i < size; i++){
            Node * current = q.front();
            q.pop();
            // Here we are traversing 1 step in left, right & upward Direction
            // Checking if left child node exist if yes than is it already visited if not than 
            if(current->left && !visited[current->left]){
                q.push(current->left);
                visited[current->left] = true;
            }
            
            // checking for right child node
            if(current->right && !visited[current->right]){
                q.push(current->right);
                visited[current->right] = true;
            }
            
            // checking for upward node i.e., parent node
            if(parent_mark[current] && !visited[parent_mark[current]]){
                q.push(parent_mark[current]);
                visited[parent_mark[current]] = true;
            }
        }
    }

    // Inserting resultant ouput in result vector
    while (!q.empty()){
        result.push_back(q.front()->data);
        q.pop();
    }
    
    return result;
}

int main(){
    Node * root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    int k = 2;
    vector<int> res = nodesAtDistanceK(root, root->left, k);

    for (auto x : res){
        cout << x << " ";
    }
    
    return 0;
}