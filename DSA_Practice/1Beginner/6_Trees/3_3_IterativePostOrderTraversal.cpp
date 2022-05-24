#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// Striver Tree Series : L11 & L12 Iterative PostOrder Traversal - Left -> Right -> Root
// 3rd DFS Technique : Postorder Traversal
// TC - O(n) , SC - O(2n)
// PostOrder Sol - 70 80 40 50 20 60 30 10

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

// Approach 1 : L11 - Using 2 stacks
// Algo:
// 1. Push root in stack1.
// 2. Pop top of the stack1, push it in stack2 and then push its left & right in stack1.
// 3. Repeat step2 until stack1 is not empty.
// 4. Postorder will be available in stack2.

vector<int> iterativePostOrder(Node * root){
    vector<int> postorder;
    if(root == NULL)
        return postorder;

    stack<Node*> st1, st2;
    st1.push(root);

    while (!st1.empty()){
        Node * temp = st1.top();
        st1.pop();
        st2.push(temp);

        if(temp->left != NULL)
            st1.push(temp->left);

        if(temp->right != NULL)
            st1.push(temp->right);
    }

    while (!st2.empty()){
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
    
    return postorder;
}

// Approach 2 : L12 - Using 1 stack
// Algo: Recursive idea
// 1. Go left untill NULL
// 2. Go one time right
// 3. Go again left untill NULL
vector<int> iterativePostOrder2(Node * root){
    vector<int> postorder;
    if(root == NULL)
        return postorder;

    stack<Node*> st;
    Node * curr = root;

    while (curr != NULL || !st.empty()){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            Node * temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);
                // check if its root exist ()i.e., right element root exist or not
                while (!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else
                curr = temp;
        }
    }
    
    return postorder;
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

    vector<int> res = iterativePostOrder2(root);
    for (auto x : res){
        cout << x << " ";
    }
    cout << endl;

    vector<int> res1 = iterativePostOrder(root);
    for (auto x : res1){
        cout << x << " ";
    }

    return 0;
}

