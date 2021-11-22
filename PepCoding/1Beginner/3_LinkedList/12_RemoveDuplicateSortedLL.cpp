#include<iostream>
using namespace std;
// Pepcoding Ques - Remove Duplicates in Sorted Linked List
// Constraints : TC - O(n) & SC - O(1)

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

// Remove duplicates from Sorted Linked List
void removeDuplicates(Node * &head){
    Node * temp = head;
    // Edge Case - If empty linked list is passed
    if(!temp)
        return;

    while (temp->next != NULL){
        if(temp->data == temp->next->data)
            temp->next = temp->next->next;

        else
            temp = temp->next;
    }
}

int main(){
    Node * head = NULL;

    int arr[] = {1,2,2,3,3,3,4,4,4,4,5};

    for (int i = 0; i < 11; i++){
        InsertAtTail(head, arr[i]);
    }
    display(head);

    removeDuplicates(head);

    display(head);

    cout << endl;
    return 0;
}