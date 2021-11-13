#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node * next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// Here we pass reference of head i.e., &head as we are modifying the Linked List
void InsertAtTail(Node * &head, int data){
    // Creating Node n having data
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

// Here we pass value of head as we are just printing the Linked List
void display(Node * head){
    Node * temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    Node * head = NULL;
    InsertAtTail(head, 3);
    InsertAtTail(head, 8);
    InsertAtTail(head, 9);

    display(head);

    cout << endl;
    return 0;
}