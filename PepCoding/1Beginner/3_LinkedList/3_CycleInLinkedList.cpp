#include<iostream>
using namespace std;
// Cycle In Linked List

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

// DETECT CYCLE
bool detectCycle(Node * &head){
    Node * slow = head;
    Node * fast = head;

    while (fast != NULL && fast->next != NULL){
        slow = slow->next;  // Slow pointer is moved by 1 step
        fast = fast->next->next;    // Fast pointer is moved by 2 step

        if(slow == fast)
            return true;
    }
    return false;
}

// Make Cycle in Linked List
void makeCycle(Node * &head, int pos){
    Node * temp = head;
    Node * startHead;

    int count = 1;
    while (temp->next != NULL){
        if(count == pos){
            startHead = temp;
        }
        temp = temp->next;
        count++;
    }

    // Now temp points to last node and temp->next is NULL so to make LinkedList a cycle
    temp->next = startHead;
}

// Remove Cycle
void removeCycle(Node * &head){
    Node * slow = head;
    Node * fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    // After two pointers collide we'll make fast pointer to point to head i.e., Starting Node
    fast = head;

    while (slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    // Now Slow and Fast both points to same node now we'll make the slow points to NULL
    slow->next = NULL;
}


int main(){
    Node * head = NULL;

    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    InsertAtTail(head, 6);

    makeCycle(head, 3);
    cout << detectCycle(head) << endl;

    removeCycle(head);
    cout << detectCycle(head) << endl;

    display(head);
   
    cout << endl;
    return 0;
}