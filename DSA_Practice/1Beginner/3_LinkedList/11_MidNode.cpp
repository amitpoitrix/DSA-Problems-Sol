#include<iostream>
using namespace std;
// Pepcoding Ques - Find Mid Node of Linked List - Using Two Pointers(Slow & fast pointers) approach(Iterative)
// Constraints : Don't use recursive approach and size() directly or indirectly and should be solve in single traversal

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

// Mid node of Linked List - Using Two Pointer
int midNode(Node * &head){
    Node * slow = head;
    Node * fast = head;
    // for finding the mid node we'll move slow by 1 step and fast by 2 step
    while (fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int main(){
    Node * head = NULL;

    int arr[] = {1,2,5};

    for (int i = 0; i < 3; i++){
        InsertAtTail(head, arr[i]);
    }
    display(head);

    cout << "Mid Node = " << midNode(head);

    cout << endl;
    return 0;
}