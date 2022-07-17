#include<bits/stdc++.h>
using namespace std;

// Lt: 138. Copy List with Random Pointer
// https://leetcode.com/problems/copy-list-with-random-pointer/

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Normal Approach
// TC - O(n) + O(n)
// SC - O(n)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node * ptr = head;
        
        while(ptr != NULL){
            mp[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }
        
        ptr = head;
        while(ptr != NULL){
            mp[ptr]->next = mp[ptr->next];
            mp[ptr]->random = mp[ptr->random];
            ptr = ptr->next;
        }
        
        return mp[head];
    }
};

// Optimised Approach
// TC - O(n) + O(n) + O(n)
// SC - O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return head;
        
        //Step 1: First we create deep copy nodes
        Node * itr = head;
        while(itr != NULL){
            Node * newNode = new Node(itr->val);
            newNode->next = itr->next;
            itr->next = newNode;
            itr = itr->next->next;
        }
        
        // Step 2: Connecting the random pointers of deep copy
        itr = head;
        while(itr != NULL){
            if(itr->random == NULL)
                itr->next->random = NULL;
            else
                itr->next->random = itr->random->next;
            
            itr = itr->next->next;
        }
        
        // Step 3: Separating out original and deep copy LL
        // Pointers for Orignal LL
        itr = head;
        Node * front = head->next->next;
        
        // Pointers for deep copy LL
        Node * dummy = new Node(-1);
        dummy->next = head->next;
        Node * temp = dummy->next;
        
        while(front != NULL){
            temp->next = front->next;
            temp = temp->next;
            
            itr->next = front;
            itr = itr->next;
            
            front = front->next->next;
        }
        
        temp->next = front;
        itr->next = front;
        
        return dummy->next;
    }
};

int main(){
    return 0;
}