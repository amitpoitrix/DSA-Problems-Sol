#include<iostream>
using namespace std;
// Stack Implementation - LIFO - Last In First Out

#define n 100

class Stack{
    // private data members of stack class
    int * arr;  // Declaring Dynamic array
    int top;

public:
    Stack(){
        arr = new int[n];   // size - n value describe under #define
        top = -1;
    }

    // 1.PUSH Method - Insert the element from top of the stack
    void push(int x){
        // Edge Case - If Stack is full
        // Here we're comparing top with size of stack
        if(top == n-1){
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        arr[top] = x;
    }

    // 2.POP Method - Delete/Remove the element from top of the stach
    void pop(){
        // Here we're comparing top with value 
        if(top == -1){
            cout << "No element to Pop" << endl;
        }

        top--;
    }

    // 3. TOP Method - Returns the Top most element of the stack
    int Top(){
        // Edge Case - If stack is empty
        if(top == -1){
            cout << "No element on Top" << endl;
            return -1;
        }

        return arr[top];
    }

    // 4. EMPTY Method - returns true if stack is empty or else false
    bool empty(){
        return top == -1;
    }
};


int main(){
    // Stack st;
    // st.push(1);
    // st.push(2);
    // st.push(3);
    // cout << st.Top() << endl;

    // st.pop();
    // cout << st.Top() << endl;

    // st.pop();
    // st.pop();
    // cout << st.empty() << endl;

    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    while (!st.empty()){
        cout << st.Top() << endl;
        st.pop();
    }

    cout << endl;
    return 0;
}