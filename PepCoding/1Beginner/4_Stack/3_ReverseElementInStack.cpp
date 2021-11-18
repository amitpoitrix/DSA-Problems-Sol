#include<iostream>
#include<stack>
using namespace std;
// Reversing element of stack using Recursion - TC - O(n) & SC - O(1)

void insertAtBottom(stack<int> &st, int ele){
    // base case
    if(st.empty()){
        st.push(ele);   // if stack is empty than we'll push the ele(i.e., 5) that needs to be in bottom
        return;
    }

    // rec case
    int topEle = st.top();  // 1st iteration topEle -> 1 
    st.pop();
    insertAtBottom(st, ele);    // ((2,3,4), 5) <- Parameters

    st.push(topEle);    // push(1)
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