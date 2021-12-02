#include<iostream>
#include<stack>
using namespace std;
// Program for Infix to Postfix Expression
// (a-b/c)*(a/k-l)   ->   abc/-ak/l-*

int prec(char ch){
    if(ch == '^')
        return 3;   // As ^(power) has higher precedence
    else if(ch == '/' || ch == '*')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else
        return -1;  // for opening bracket '(' bracket
}

string infixToPostfix(string s){
    stack<char> st;
    string res;

    for (int i = 0; i < s.size(); i++){
        // Step 1 : If encouter operand than directly print it
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            res += s[i];
        }
        // step 2 : If encounter opening bracket '(' than directly push into the stack
        else if(s[i] == '('){
            st.push(s[i]);
        }
        // step 3 : If encounter closing bracket ')' than directly print the element from top and pop simultaneously till opening bracket '(' encounters 
        else if(s[i] == ')'){
            while (!st.empty() && st.top() != '('){
                res += st.top();    // print
                st.pop();
            }
            // Removing the opening bracket '(' from stack
            if(!st.empty()){
                st.pop();
            }
        }
        // step 4 : If encounter operator than pop(print) the top of the stack operator till encounter lower precedence operator than current operator
        // and than push that current operator at last
        else{
            while (!st.empty() && prec(st.top()) >= prec(s[i])){
                res += st.top();    // print
                st.pop();
            }
            st.push(s[i]);
        }
    }
    
    // Printing rest of the element from stack if left out
    while (!st.empty()){
        res += st.top();
        st.pop();
    }
    
    return res;
}

int main(){
    cout << infixToPostfix("(a-b/c)*(a/k-l)");

    cout << endl;
    return 0;
}