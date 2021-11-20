#include<iostream>
using namespace std;
// Stack Implementation Using Linked List

// Creating a Linked List node
class Node{
public:
    int data;
    Node * next;

    Node(int data){
        this->data = data;
        this->next = next;
    }
};

// Creating Stack class and its functions
class Stack{
    // Declaring private members of stack class 
    Node * head; // here head pointer resembles top pointer of stack
public:
    Stack(){
        head = NULL;
    }
    // 1. PUSH Method - Here both the case will be consider whether list is empty or not
    void push(int data){
        Node * n = new Node(data);
        n->next = head;
        head = n;
    }
    // 2. EMPTY Method
    bool empty(){
        return head == NULL;
    }
    // 3. TOP Method
    int Top(){
        return head->data;
    }
    // 4. POP Method
    void pop(){
        if(head != NULL){
            Node * temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main(){
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
    
    cout << endl;
    return 0;
}