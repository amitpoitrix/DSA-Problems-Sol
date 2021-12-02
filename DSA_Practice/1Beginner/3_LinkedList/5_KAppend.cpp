#include<iostream>
using namespace std;
// Appending K Node in front of Linked List

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

// K Node Append at the start of Linked List
Node * KAppend(Node * &head, int k){
    // We'll take 3 pointers
    Node * newHead;
    Node * newTail;
    Node * tail = head;

    int l = length_LL(head);
    int count = 1;
    k = k % l;  // if k > l 
    while (tail->next != NULL){
        if(count == l-k){
            newTail = tail;
        }
        if(count == l-k+1){
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    
    tail->next = head;
    newTail->next = NULL;

    return newHead;
}

int main(){
    Node * head = NULL;

    int arr[] = {1,2,3,4,5,6};

    for (int i = 0; i < 6; i++){
        InsertAtTail(head, arr[i]);
    }
    display(head);

    Node * newHead = KAppend(head, 3);
    display(newHead);
   
    cout << endl;
    return 0;
}