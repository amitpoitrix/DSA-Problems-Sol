#include<iostream>
#include<unordered_map>
// Detect Cycle in Linked List Using Hashing

class Node{
public:
    int data;
    Node * next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// INSERT
void InsertAtTail(Node * &head, int data){
    Node * n = new Node(data);
    // If Linked List is empty
    if(head == NULL){
        head = n;
        return;
    }

    // Traverse till end node
    Node * temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = n;
}

// Detecting Cycle in Linked List using Hash table
bool containsCycle(Node* head){
    std::unordered_map<Node*, bool> hashtable;

    Node * temp = head;
    while (temp != NULL){
        // Check if temp already exist in HashTable
        if(hashtable.count(temp) != 0)
            return true;
        
        hashtable[temp] = true;
        temp = temp->next;
    }
    return false;
}   

int main(){
    Node * head = NULL;

    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    InsertAtTail(head, 6);

    // Making Cycle
    Node * temp = head->next->next->next->next;
    temp->next = head->next->next;

    if(containsCycle(head))
        std::cout << "Cycle Found";
    else
        std::cout << "Cycle Not Found";

    return 0;
}