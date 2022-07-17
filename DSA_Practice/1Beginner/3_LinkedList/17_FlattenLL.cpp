#include<iostream>
using namespace std;

// Flattening a Linked List 
// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}	
};

class Solution{
private:
    Node * merge(Node * l1, Node * l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l1->data > l2->data)
            swap(l1, l2);
        
        Node * res = l1;
        
        while(l1 != NULL && l2 != NULL){
            Node * temp = NULL;
            while(l1 != NULL && l1->data <= l2->data){
                temp = l1;
                l1 = l1->bottom;
            }
            temp->bottom = l2;
            swap(l1, l2);
        }
        
        return res;
    }

public:
    Node *flatten(Node *root){
        if(root == NULL || root->next == NULL)
            return root;
        
        root->next = flatten(root->next);
   
        return merge(root, root->next);    
    }
};

int main(){
    return 0;
}