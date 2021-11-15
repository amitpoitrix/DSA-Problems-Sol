#include<iostream>
using namespace std;
// Find Intersection Point In Linked List

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

// Length of Linked List
int length_LL(Node * head){
    Node * temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

// Intersecting two linked list at given pos 
void intersect(Node * head1, Node * head2, int pos){
    // Here Assuming temp1 > temp2 .. length wise
    Node * temp1 = head1;
    // Traversing temp1 till that given pos
    pos--;
    while (pos--){
        temp1 = temp1->next;
    }

    // Traversing temp2 till last node 
    Node * temp2 = head2;
    while (temp2->next != NULL){
        temp2 = temp2->next;
    }

    temp2->next = temp1;
}

// Finding Intersecting value of 2 Linked List
int intersection(Node * &head1, Node * &head2){
    Node * ptr1;
    Node * ptr2;

    int l1 = length_LL(head1);
    int l2 = length_LL(head2);

    int d = 0;

    if(l1 > l2){
        ptr1 = head1;
        ptr2 = head2;
        d = l1 - l2;
    }
    else{
        ptr1 = head2;
        ptr2 = head1;
        d = l2 - l1;
    }

    while (d--){
        ptr1 = ptr1->next;
        if(ptr1 == NULL)
            return -1;
    }
    
    while (ptr1 != NULL && ptr2 != NULL){
        if(ptr1 == ptr2)
            return ptr1->data;
            
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return -1;
}

int main(){
    Node * head1 = NULL;
    Node * head2 = NULL;

    InsertAtTail(head1, 1);
    InsertAtTail(head1, 2);
    InsertAtTail(head1, 3);
    InsertAtTail(head1, 8);
    InsertAtTail(head1, 5);
    InsertAtTail(head1, 6);
    display(head1);

    InsertAtTail(head2, 9);
    InsertAtTail(head2, 10);
    intersect(head1, head2, 4);
    display(head2);

    cout << intersection(head1, head2);

    cout << endl;
    return 0;
}