#include<iostream>
using namespace std;
// Pepcoding Ques - Find Kth Node from End of Linked List - Using Two Pointers(Slow & fast pointers) approach(Iterative)
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

// Kth Node from end
int KthNodeFromEnd(Node * &head, int k){
    Node * slow = head;
    Node * fast = head;
    // First we move the fast pointer to Kth position
    for (int i = 0; i < k; i++){
        fast = fast->next;
    }

    // Now we'll move both slow and fast pointer by 1 step
    while (fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow->data;
}


int main(){
    Node * head = NULL;

    int arr[] = {1,2,3,4,5,6};

    for (int i = 0; i < 6; i++){
        InsertAtTail(head, arr[i]);
    }
    display(head);

    cout << "Kth Node from End = " << KthNodeFromEnd(head, 2);

    cout << endl;
    return 0;
}