#include<iostream>
using namespace std;
// Queue Implementation
#define n 20

class Queue{
    int * arr;
    int front;
    int back;
public:
    Queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }

    // 1. ENQUEUE Method - Pushing the element from back
    void enqueue(int data){
        // Edge Case - If queue is full
        if(back == n-1){
            cout << "Queue Overflow" << endl;
        }

        back++;
        arr[back] = data;

        // Edge Case - if front is -1 than move it 1 step forward
        if(front == -1){
            front++;
        }
    }

    // 2. DEQUEUE Method - Removing(or POP) the element from front
    void dequeue(){
        if(front == -1 || front > back){
            cout << "Queue is Empty" << endl;
            return;
        }
        front++;
    }

    // 3. PEEK Method - Print the element from front
    int peek(){
        if(front == -1 || front > back){
            cout << "Queue is Empty" << endl;
            return -1;
        }

        return arr[front];
    }

    // 4. EMPTY Method
    bool empty(){
        if(front == -1 || front > back){
            return true;
        }
        return false;
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