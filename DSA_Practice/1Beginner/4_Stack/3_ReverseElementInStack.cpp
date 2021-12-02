#include<iostream>
#include<stack>
using namespace std;
// Reversing element of stack using Recursion - TC - O(n) & SC - O(1)

void insertAtBottom(stack<int> &st, int data){
    // base case
    if(st.empty()){
        st.push(data);   // if stack is empty than we'll push the ele(i.e., 5) that needs to be in bottom
        return;
    }

    // rec case
    int temp = st.top();  // 1st iteration temp -> 1 
    st.pop();
    insertAtBottom(st, data);    // ((2,3,4), 5) <- Parameters
    // Now coming back from base case and pushing the element(stored in temp) back from call stack 
    st.push(temp);    // push(1)
}

// Reverse of stack eg : Initially st -> 5,4,3,2,1 reverseStack() -> 1,2,3,4 and we need to insert 5 at bottom
void reverseStack(stack<int> &st){
    // base case
    if(st.empty()){
        return;
    }

    // rec case
    int ele = st.top();
    st.pop();
    reverseStack(st);   // st -> 1,2,3,4
    
    insertAtBottom(st, ele);    // ((1,2,3,4), 5) <- Parameters that are passed
}

// Displaying Stack element
void displayStack(stack<int> st){
    while (!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
    cout << endl;
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    displayStack(st);
    reverseStack(st);
    displayStack(st);

    cout << endl;
    return 0;
}