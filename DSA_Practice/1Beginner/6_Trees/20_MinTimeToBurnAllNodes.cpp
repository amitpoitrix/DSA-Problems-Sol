#include<bits/stdc++.h>
using namespace std;
// Striver Tree series : L31. Minimum time taken to BURN the Binary Tree from a Node/ leaf(codestudio)
// Same as All nodes at distance k in BT
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

// to compute the parent node of all nodes as well as address of start(target) node
Node * mapParent(Node * root, int start, unordered_map<Node*, Node*> &mpp){
    Node * result;  // to store the address of node having data as start
    
    queue<Node*> q;
    q.push(root);

    while (!q.empty()){
        Node * current = q.front();
        q.pop();

        // Logic for finding the node address having data as start
        if(current->data == start)
            result = current;

        if(current->left){
            q.push(current->left);
            mpp[current->left] = current;
        }

        if(current->right){
            q.push(current->right);
            mpp[current->right] = current;
        }
    }
    
    return result;
}

int minTimeTaken(Node * root, Node * target, unordered_map<Node*, Node*> &mpp){
    int timeTaken = 0;
    // visited Hash Table to check whether node is already visited or not
    unordered_map<Node*, bool> visited;
    visited[target] = true;

    queue<Node*> q;     // As we're doing BFS traversal from target node
    q.push(target);

    bool flagBurn;

    while (!q.empty()){
        int size = q.size();
        flagBurn = false;
        for (int i = 0; i < size; i++){
            Node * current = q.front();
            q.pop();
            
            if(current->left && !visited[current->left]){
                flagBurn = true;
                q.push(current->left);
                visited[current->left] = true;
            }
            
            if(current->right && !visited[current->right]){
                flagBurn = true;
                q.push(current->right);
                visited[current->right] = true;
            }
            
            if(mpp[current] && !visited[mpp[current]]){
                flagBurn = true;
                q.push(mpp[current]);
                visited[mpp[current]] = true;
            }
        }

        // if any nodes burn whether on left, right or upward the flag will become true 
        if(flagBurn)
            timeTaken++;
    }

    return timeTaken;
}

// Function for min time to burn all the nodes from given node/leaf and here we're given 
// the Node data not directly the target node
int minTimeToBurn(Node * root, int start){
    int minTime = 0;
    if(root == NULL)
        return minTime;
    
    unordered_map<Node*, Node*> mpp;
    // to compute the parent node of all nodes as well as address of start(target) node
    Node * target = mapParent(root, start, mpp);
    minTime = minTimeTaken(root, target, mpp);

    return minTime;
}

int main(){
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->left->left->right = new Node(4);

    int startNode = 2;

    cout << "Min time to burn all nodes : "<< minTimeToBurn(root, startNode);
    
    return 0;
}