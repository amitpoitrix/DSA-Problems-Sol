#include<iostream>
#include<queue>
using namespace std;
// striver Tree Series : Leetcode 662. Maximum Width of Binary Tree
// Max width of a BT is the max distance btw two nodes at the same level

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

int maxWidthBT(Node * root){
    if(root == NULL)
        return 0;

    int width = 0;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()){
        int size = q.size();
        int min = q.front().second;
        int first, last;
        for (int i = 0; i < size; i++){
            int curr_idx = q.front().second - min;
            Node * temp = q.front().first;
            q.pop();

            if(i == 0)
                first = curr_idx;
            if(i == size-1)
                last = curr_idx;

            if(temp->left)
                q.push({temp->left, curr_idx * 2 + 1});
            
            if(temp->right)
                q.push({temp->right, curr_idx * 2 + 2});
        }

        width = max(width, last - first + 1);
    }

    return width;
}

int main(){
    Node * root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->left->left = new Node(5);
    root->right->right = new Node(9);
    root->left->left->left = new Node(6);
    root->right->right->right = new Node(7);

    int width = maxWidthBT(root);

    cout << "Maximum width of Binary Tree : " << width;

    return 0;
}
