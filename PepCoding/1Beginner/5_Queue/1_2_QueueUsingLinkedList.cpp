#include<iostream>
using namespace std;
// Queue Implementation Using Linked List

// Declaring Node class for Linked List
class Node{
public:
    int data;
    Node * next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// Declaring Queue class
class Queue{
    Node * front;
    Node * back;
public:
    Queue(){
        front = NULL;
        back = NULL;
    }

    // 1. ENQUEUE Method
    void enqueue(int data){
        Node * n = new Node(data);
        // Edge Case - If Queue is empty
        if(front == NULL){
            front = n;
            back = n;
            return;
        }

        back->next = n;
        back = n;
    }

    // 2. DEQUEUE Method
    void dequeue(){
        if(front == NULL){
            cout << "Queue is Empty" << endl;
            return;
        }

        Node * toDelete = front;
        front = front->next;

        delete toDelete;
    }

    // 3. PEEK Method
    int peek(){
        if(front == NULL){
            cout << "Queue is Empty" << endl;
            return -1;
        }

        return front->data;
    }

    // 4. EMPTY Method
    bool empty(){
        return front == NULL;
    }
};

int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    // Print queue element
    for (int i = 0; i < 5; i++){
        cout << q.peek() << endl;
        q.dequeue();
    }

    cout << q.empty() << endl;

    cout << endl;
    return 0;
}