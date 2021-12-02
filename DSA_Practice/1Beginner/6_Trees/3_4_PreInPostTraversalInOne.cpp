#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// Striver Tree Series : Iterative PreOrder, InOrder & PostOrder Traversal in One Traversal

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

// Printing Tree Order
void printTree(vector<int> res){
    for (auto x : res){
        cout << x << " ";
    }
    cout << endl;
}

// Iterative Tree Traversal in One Traversal
void iterativePreInPostOrder(Node * root){
    vector<int> preorder, inorder, postorder;
    if(root == NULL)
        return;
    
    stack<pair<Node*, int>> st;     // stack having elements in pairs i.e., {node, num}
    st.push({root, 1});

    while (!st.empty()){
        auto temp = st.top();   // here temp is of type pair<Node*, int>
        st.pop();
        // PreOrder & check if left exist
        if(temp.second == 1){
            preorder.push_back(temp.first->data);
            temp.second++;
            st.push(temp);  // Pushing back into the stack after incrementing the num(second) value
            // If temp left exist
            if(temp.first->left != NULL){
                st.push({temp.first->left, 1});
            }
        }
        // InOrder & check if right exist
        else if(temp.second == 2){
            inorder.push_back(temp.first->data);
            temp.second++;
            st.push(temp);
            // If temp right exist
            if(temp.first->right != NULL){
                st.push({temp.first->right, 1});
            }
        }
        // PostOrder
        else{
            postorder.push_back(temp.first->data);
        }
    }

    printTree(preorder);
    printTree(inorder);
    printTree(postorder);
    
    return;
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

    iterativePreInPostOrder(root);

    return 0;
}

