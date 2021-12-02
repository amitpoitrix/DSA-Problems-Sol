#include<iostream>
using namespace std;
// Doubly Linked List
// Note : Don't forget to pass head by reference (&head) when modifying linked list

class Node{
public:
    int data;
    Node * next;
    Node * prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// INSERTION
// Inserting node at the start of doubly Linked List
void insertAthead(Node * &head, int data){
    Node * n = new Node(data);
    n->next = head;
    // Edge Case - What if head points to NULL i.e., Linked List is empty
    if(head != NULL){
        head->prev = n;
    }
    head = n;
}

// Inserting node at the end of doubly Linked List
void insertAtTail(Node * &head, int data){
    // Edge Case - No node in the Linked List
    if(head == NULL){
        insertAthead(head, data);
        return;
    }

    Node * n = new Node(data);

    Node * temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp;
}

// DELETION
// Deletion at head
void deletionAtHead(Node * &head){
    // Edge Case - what if Linked List is empty
    if(head == NULL)
        return;

    Node * temp = head;
    head = head->next;
    // Edge Case - what if only 1 node is present in Linked List
    if(head->next != NULL){
         head->prev = NULL;
    }

    delete temp;
}

void deletion(Node * &head, int pos){
    // Edge Case - if node to be deleted is the starting node
    if(pos == 1){
        deletionAtHead(head);
        return;
    }

    Node * temp = head;
    int count = 1;
    while (temp != NULL && count != pos){
        temp = temp->next;
        count++;
    }

    temp->prev->next = temp->next;
    // Edge Case - what if node to be deleted is the last node
    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    } 

    delete temp;
    
}

// DISPLAY
void display(Node * head){
    Node * temp = head;
    while (temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    Node * head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);

    insertAthead(head, 5);
    display(head);

    deletion(head, 2);
    display(head);

    deletionAtHead(head);
    display(head);

    cout << endl;
    return 0;
}