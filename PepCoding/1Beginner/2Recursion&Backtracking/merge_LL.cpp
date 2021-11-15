#include<iostream>
using namespace std;
// Merge two Linked List - Time Complexity - O(n+m)

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

// MERGE of Two Linked List
// 1. Iterative way
Node * mergeLL(Node * &head1, Node * &head2){
    Node * ptr1 = head1;
    Node * ptr2 = head2;
    // we'll create a dummyNode - After which merge sorted linked list starts and its not a pointer its a node
    Node * dummyNode = new Node(-1);
    Node * ptr3 = dummyNode;

    while (ptr1 != NULL && ptr2 != NULL){
        if (ptr1->data < ptr2->data){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }

    while (ptr1 != NULL){
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }
    
    while (ptr2 != NULL){
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }

    return dummyNode->next;
}

// 2. Recursive way
Node * mergeRecursive(Node * &head1, Node * &head2){
    // base case - if any one of the Linked List is finish traversing return the another one which is left out
    if(head1 == NULL)
        return head2;

    if(head2 == NULL)
        return head1;  

    // rec case
    Node * result;
    if(head1->data < head2->data){
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    }
    else{
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }

    return result;
}

int main(){
    Node * head1 = NULL;
    Node * head2 = NULL;

    int arr1[] = {1, 4, 5, 7};
    for (int i = 0; i < 4; i++){
        InsertAtTail(head1, arr1[i]);
    }
    display(head1);

    int arr2[] = {2, 3, 6};
    for (int i = 0; i < 3; i++){
        InsertAtTail(head2, arr2[i]);
    }
    display(head1);

    // Node * newMergeHead = mergeLL(head1, head2);
    Node * newMergeHead = mergeRecursive(head1, head2);

    display(newMergeHead);

    cout << endl;
    return 0;
}