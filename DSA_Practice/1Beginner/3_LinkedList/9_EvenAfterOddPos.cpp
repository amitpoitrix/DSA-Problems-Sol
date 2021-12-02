#include<iostream>
using namespace std;
// Put Even Nodes after all Odd Position Nodes

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

// DISPLAY
// Here we pass value of head as we are just printing the Linked List
void display(Node * head){
    Node * temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Even After Odd Node Pos
void evenAfterOdd(Node * head){
    // We'll take 3 ptr
    Node * odd = head;
    Node * even = head->next;
    Node * evenStart = even;

    while (odd->next != NULL && even->next != NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    // Putting even nodes pos after odd ones
    odd->next = evenStart;
    // If No. of nodes is Odd than last node will be of odd pos so we'll make even node as last node
    if(odd->next == NULL){
        even->next = NULL;
    }
}

int main(){
    Node * head = NULL;

    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    InsertAtTail(head, 6);
    display(head);

    evenAfterOdd(head);
    display(head);

    cout << endl;
    return 0;
}