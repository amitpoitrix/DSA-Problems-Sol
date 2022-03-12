#include<iostream>

// Leetcode Daily 12/03/2022: 138. Copy List with Random Pointer
// Topic : Linked List
// https://leetcode.com/problems/copy-list-with-random-pointer/

class Node{
public:
    int data;
    Node *next, *random;

    Node(int data){
        this->data = data;
        this->next = this->random = NULL;
    }
};

class Solution {
public:
    Node * copyRandomList(Node * head) {
        // Step 1 : Copy the Linked List except random pointer i.e., A -> A`-> B -> B`-> C -> C`-> NULL
        Node * node = head;
        while (node){
            Node * temp = node->next;
            node->next = new Node(node->data);

            node->next->next = temp;
            node = temp;
        }

        // Step 2 : Copy the Random Pointer
        node = head;
        while (node){
            if(node->random)
                node->next->random = node->random->next;
            node = node->next->next;
        }
        
        // Step 3 : Separating the Original Linked List with newly created Linked List
        Node * ans = new Node(0);   // Dummy Node
        Node * helper = ans;
        while (head){
            // Linking newly created Linked List
            helper->next = head->next;
            helper = helper->next;

            // Linking back the Original Linked List
            head->next = head->next->next;
            head = head->next;
        }
        
        return ans->next;
    }
};

int main(){

    return 0;
}