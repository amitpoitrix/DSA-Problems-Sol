#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
// Evaluating(Calculating) Prefix expression using Stack

int prefixExpression(string s){
    stack<int> st;
    // As its Prefix Expression so we'll traverse from Last character of string and for Postfix Expression we'll start from starting char
    for (int i = s.size()-1; i >= 0; i--){
        // If we encounter operand
        if(s[i] >= '0' && s[i] <= '9'){
            st.push(s[i] - '0');    // As we are pushing int element from string
        }
        // else if we encounter operator
        else{
            int op1 = st.top();     // In PostFix we'll make op2 as first element that come from top of the stack
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (s[i]){
            case '+':
                st.push(op1 + op2);
                break;

            case '-':
                st.push(op1 - op2);
                break;

            case '*':
                st.push(op1 * op2);
                break;

            case '/':
                st.push(op1 / op2);
                break;

            case '^':
                st.push(op1 ^ op2);
                break;
            }
         }
    }

    return st.top();
}

int main(){
    cout << prefixExpression("-+7*45+20");

    cout << endl;
    return 0;
}