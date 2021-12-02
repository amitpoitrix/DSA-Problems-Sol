#include<iostream>
using namespace std;
// LinkedList - Apna College YT
// Note : Don't forget to pass head by reference (&head) when modifying linked list

class Node{
public:
    int data;
    Node * next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


// INSERTION
void InsertAtHead(Node * &head, int data){
    Node * n = new Node(data);
    // If Linked List is empty
    if(head == NULL){
        head = n;
        return;
    }

    n->next = head;
    head = n;
}

// Here we pass reference of head i.e., &head as we are modifying the Linked List
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

// Insert at a given position
void InsertAtPos(Node * &head, int data, int pos){
    Node * n = new Node(data);

    if(pos == 0){
        InsertAtHead(head, data);
        return;
    }
    
    Node * temp = head;
    // Traversing(or Jumping) till 2nd Last element of given pos
    for (int jump = 1; jump <= pos-1 && temp != NULL; jump++){
        temp = temp->next;
    }

    if(temp == NULL){
        cout << "Given Position is Out of bound" << endl;
        return;
    }

    n->next = temp->next;
    temp->next = n;
}


// DELETION
// At Front
void deletionAtHead(Node * &head){
    if(head == NULL){
        return;
    }

    Node * temp = head;
    head = head->next;

    delete temp;
}

// At Back
void deletionAtTail(Node * &head){
    if(head == NULL){
        return;
    }

    if(head->next == NULL){
        deletionAtHead(head);
        return;
    }

    Node * temp = head;
    // Traversing till 2nd last element
    while (temp->next->next != NULL){
        temp = temp->next;
    }

    Node * second = temp->next;
    temp->next = NULL;

    delete second;
}

// Value wise
void deletion(Node * &head, int val){
    // No node in the Linked List
    if(head == NULL){
        return;
    }
    // Only 1 element in the Linked List
    if(head->next == NULL){
        deletionAtHead(head);
        return;
    }

    Node * temp = head;
    // Traversing till 2nd last element of given val
    while (temp->next->data != val){
        temp = temp->next;
    }

    Node * second = temp->next; // second points to Node to be deleted
    temp->next = temp->next->next;
    
    delete second;  // Deleting Second Node otherwise there will be Memory Leak
}


// SEARCH
// Search() - we use Linear search as for Binary search getting mid element will take O(n) time
int searchKey(Node * head, int key){
    Node * temp = head;
    int idx = 0;
    while (temp != NULL){
        if(temp->data == key){
            return idx;
        }
        temp = temp->next;
        idx++;
    }
    return -1;
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


int main(){
    Node * head = NULL;

    InsertAtTail(head, 3);
    InsertAtTail(head, 8);
    InsertAtTail(head, 9);
    display(head);
 
    InsertAtHead(head, 2);
    InsertAtHead(head, 1);
    display(head);

    InsertAtPos(head, 89, 3);
    display(head);

    deletion(head, 9);
    display(head);

    deletionAtHead(head);
    display(head);

    deletionAtTail(head);
    display(head);

    int key;
    cin >> key;
    cout << searchKey(head, key);

    cout << endl;
    return 0;
}