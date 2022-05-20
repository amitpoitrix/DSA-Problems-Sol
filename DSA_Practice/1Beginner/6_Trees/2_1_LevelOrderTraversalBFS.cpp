#include<iostream>
#include<queue>
using namespace std;
// Striver Tree series : 102. Binary Tree Level Order Traversal
// L8 Level Order Traversal - BFS(Breadth First search)

// Algo:
// BFS - Breadth First Search or Level Order Traversal using QUEUE
// 1. Take a queue of type Node* & insert root into it and run outer loop till queue is empty
// 2. Calculate size of queue in each iteration as at each iteration no. of element inside queue will determine no. of element
// present at each row
// 3. So inside Outer loop, run inner loop till queue size(calculate in each outer loop iteration) times and add each elements 
// correspomding left & right root element into queue if exist & also add current element val in 1D array that will store 
// elements of each row

// Application :
// 1. To find the max width of BT i.e., max no. of nodes in a particular level

// TC - O(n)
// SC - O(n) - for queue
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