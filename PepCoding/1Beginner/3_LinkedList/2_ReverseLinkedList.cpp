#include<iostream>
using namespace std;
// Reversing of Linked List - YT(Apna College)

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

// REVERSING OF LINKED LIST
// Iterative Way
Node * reverse(Node * &head){
    // For Iterative way we take 3 pointers
    Node * previous = NULL;
    Node * current = head;
    Node * nextptr;

    while (current != NULL){
        nextptr = current->next;
        current->next = previous;

        previous = current;
        current = nextptr;
    }
    
    return previous;
}

// Recursive Way
Node * reverseRecursive(Node * &head){
    // base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    // rec case
    Node * newHead = reverseRecursive(head->next);
    head->next->next = head;    // head -> 1 -> 2  =>  head -> 1 <- 2
    head->next = NULL;  // head -> 1 <- 2  => NULL <- (head <-) 1 <- 2

    return newHead;
}

// Reversing Kth node in Linked List - Here we didn't handle that case if last left nodes < k
Node * reverseK(Node * &head, int k){
    // First iterative way to reverse till K nodes
    Node * previous = NULL;
    Node * current = head;
    Node * nextptr;

    int count = 0;
    while (current != NULL && count < k){
        nextptr = current->next;
        current->next = previous;

        previous = current;
        current = nextptr;
        count++;
    }

    // Then receursive way for rest of the nodes
    if(nextptr != NULL){    // OR current != NULL
        head->next = reverseK(nextptr, k);
    }

    return previous;
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

    // Node * newHead = reverse(head);
    // Node * newHead = reverseRecursive(head);
    Node * newHead = reverseK(head, 5);
    display(newHead);

    cout << endl;
    return 0;
}