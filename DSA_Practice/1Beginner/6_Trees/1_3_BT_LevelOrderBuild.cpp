#include<iostream>
#include<queue>
using namespace std;
// CM - Binary Tree - Level Order Build + HEIGHT of Tree + DIAMETER of Tree
// BFS - Breadth First Search Technique
// Here the Input is given in Level order Manner
// Input - 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
// Output 
// 1
// 2 3
// 4 5 6
// 7

// Node/Element Structure of Binary Tree
class Node{
public:
    int data;
    Node * left;    // stores the address of Left Subtree
    Node * right;   // stores the address of right Subtree

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Level Order build of Tree
Node * buildLevelOrderTree(){
    int d;
    cin >> d;

    Node * root = new Node(d);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()){
        Node * current = q.front();
        q.pop();

        int c1, c2;
        cin >> c1 >> c2;

        if(c1 != -1){
            current->left = new Node(c1);
            q.push(current->left);
        }

        if(c2 != -1){
            current->right = new Node(c2);
            q.push(current->right);
        }
    }

    return root;
}

// Level Order Printing
void levelOrderPrint(Node * root){
    // we'll use Queue data structure specially because of it FIFO Properties
    queue<Node*> q; // here queue is of type Node * (Pointer) as it will use to store address of child node
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        Node * temp = q.front();
        if(temp == NULL){
            cout << endl;   // New Line
            q.pop();
            // Edge Case - If stack goes empty after poping last NULL node
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            // If temp is not NULL than poping & printing the element
            q.pop();
            cout << temp->data << " ";
            // If Left child exist in temp than push it into the stack
            if(temp->left)
                q.push(temp->left);

            // If right child exist in temp than push it into the stack
            if(temp->right)
                q.push(temp->right);
        }
    }  
    return;
}

// Height of the tree
int heightOfTree(Node * root){
    if(root == NULL)
        return 0;

    int h1 = heightOfTree(root->left);    // Recursively calculating height of left subtree
    int h2 = heightOfTree(root->right);   // Recursively calculating height of right subtree

    return 1 + max(h1, h2);
}

// Diameter of Tree is the max distance btw any two nodes of a tree
// This method will take T.C - O(N^2) 
int diameterOfTree(Node * root){
    if(root == NULL)
        return 0;

    int h1 = heightOfTree(root->left) + heightOfTree(root->right);
    int h2 = diameterOfTree(root->left);
    int h3 = diameterOfTree(root->right);

    return max(h1, max(h2, h3));
}

// Optimized Method of computing Diameter - TC - O(N)
// will create a class that store data of each node in pairs of height & diameter
class HDPair{
public:
    int height;
    int diameter; 
};

HDPair optimizedDiameter(Node * root){
    HDPair p;   // creating object of class HDPair
    if(root == NULL){
        p.height = p.diameter = 0;
        return p;
    }

    // Otherwise - First will go to bottom as we are following bottom up approach
    HDPair left = optimizedDiameter(root->left);
    HDPair right = optimizedDiameter(root->right);

    // Now will return from bottom to up
    p.height = 1 + max(left.height, right.height);

    int d1 = left.height + right.height;    // d1 = height of left subtree + height of right subtree
    int d2 = left.diameter;     // d2 = diameter of left subtree
    int d3 = right.diameter;    // d3 = diameter of right subtree

    p.diameter = max(d1, max(d2, d3));

    return p;
}

int main(){
    Node * root = buildLevelOrderTree();
    levelOrderPrint(root);

    cout << "Height of Tree : " << heightOfTree(root) << endl;
    
    cout << "Diameter of Tree : " << diameterOfTree(root) << endl;

    cout << "Optimized Diameter of Tree : " << optimizedDiameter(root).diameter << endl;

    return 0;
}