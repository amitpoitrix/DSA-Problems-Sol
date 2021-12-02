#include<iostream>
#include<stack>
#include<queue>
using namespace std;
// Implementing Queue using Stack

// Approach 1 : Using two Stacks
class Queue{
    stack<int> s1;
    stack<int> s2;
    queue<int> q1;
public:
    // 1. ENQUEUE Method - O(1)
    void enqueue(int data){
        s1.push(data);
    }

    // 2. DEQUEUE Method - O(n)
    int dequeue(){
        if(s1.empty() && s2.empty()){
            cout << "Queue is Empty" << endl;
            return -1;
        }

        // s2 stack top value will behave as Queue front value
        if(s2.empty()){
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        int topVal = s2.top();
        s2.pop();
        return topVal;
    }

    // 3. EMPTY Method - O(n)
    bool Empty(){
        if(s1.empty() && s2.empty())
            return true;
        return false;
    }
};

// Approach 2 : Using One Stack and another Function call stack
class Queue2{
    stack<int> s1;
public:
    // 1. ENQUEUE Method - O(1)
    void enqueue(int data){
        s1.push(data);
    }

    // 2. DEQUEUE Method - O(n)
    int dequeue(){
        // Edge Case - If Queue is empty
        if(s1.empty()){
            cout << "Queue is Empty" << endl;
            return -1;
        }

        // base case
        int x = s1.top();
        s1.pop();
        // This checking of empty() is after getting the top element from stack
        if (s1.empty()){
            return x;
        }

        // rec case
        int item = dequeue();
        s1.push(x);  // Pushing the item x of current state back to stack after getting item value(or Required Ans)
        
        return item;
    }

    // 3. EMPTY Method - O(n)
    bool Empty(){
        if(s1.empty())
            return true;
        return false;
    }
};


int main(){
    // Queue q;
    Queue2 q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    // Print queue element
    for (int i = 0; i < 5; i++){
        cout << q.dequeue() << endl;
    }

    cout << q.Empty() << endl;

    cout << endl;
    return 0;
}