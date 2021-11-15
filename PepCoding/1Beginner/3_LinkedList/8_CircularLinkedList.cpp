#include <iostream>
using namespace std;
// Circular Linked List

class Node{
public:
    int data;
    Node * next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// INSERTION on Circular Linked List
void insertAtHead(Node * &head, int val){
    Node * n = new Node(val);
    // Edge Case - If Circular Linked List is empty
    if(head == NULL){
         n->next = n;
         head = n;
         return;
    }

    // Traverse till last node
    Node * temp = head;
    while (temp->next != head){
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtTail(Node* &head, int val){
    // Edge Case - If Circular Linked List is empty
    if(head == NULL){
        insertAtHead(head, val);
        return;
    }

    Node * n = new Node(val);
    // Traverse till last node
    Node * temp = head;
    while (temp->next != head){
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}

// DELETION
void deletionAtHead(Node * &head){
    // Edge Case - if circular linked list is empty
    if(head == NULL){
        return;
    }

    Node * temp = head;
    while (temp->next != head){
        temp = temp->next;
    }
    Node * toDelete = head;
    temp->next = head->next;
    head = head->next;
    delete toDelete;
}

void deletion(Node * &head, int pos){
    // Edge Case - Deleting the first node
    if(pos == 1){
        deletionAtHead(head);
        return;
    }
    Node * temp = head;
    // Traversing temp till given pos
    int count = 1;
    while (count != pos-1){
        temp = temp->next;
        count++;
    }

    Node * toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

// DISPLAY - Circular Linked List
void display(Node * head){
    Node * temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << "Head" << endl;
}

int main(){
    Node * head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);

    insertAtHead(head, 5);
    display(head);

    deletion(head, 3);
    display(head);

    deletionAtHead(head);
    display(head);

    cout << endl;
    return 0;
}