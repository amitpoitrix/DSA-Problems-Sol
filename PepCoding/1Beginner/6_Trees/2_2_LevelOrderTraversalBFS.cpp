#include<iostream>
#include<queue>
using namespace std;
// Striver Tree series : 102. Binary Tree Level Order Traversal
// Level Order Traversal - BFS(Breadth First search)

struct Node{
public:
    int data;
    Node * left;
    Node * right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<vector<int>> levelOrderTraversal(Node * root){
    vector<vector<int>> result;
    if(root == NULL)
        return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()){
        int size = q.size();
        vector<int> row;

        for (int i = 0; i < size; i++){
            Node * temp = q.front();
            q.pop();

            row.push_back(temp->data);

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }

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

    vector<vector<int>> res = levelOrderTraversal(root);

    for (auto x : res){
        for (auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }
    

    return 0;
}