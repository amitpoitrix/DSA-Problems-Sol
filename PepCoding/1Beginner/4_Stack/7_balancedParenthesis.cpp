#include<bits/stdc++.h>
using namespace std;
// Program : Balanced Parenthesis

bool isValid(string s){
    stack<char> st;
    bool ans = true;

    for (int i = 0; i < s.size(); i++){
        // step 1. checking for opening bracket if found than directly push it into the stack
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }
        // if its closing bracket
        else if(s[i] == ')'){
            if(!st.empty() && st.top() == '('){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }

        else if(s[i] == '}'){
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }

        else if(s[i] == ']'){
            if(!st.empty() && st.top() == '['){
                st.pop();
            }
            else{
                ans = false;
                break;
            }
        }
    }

    // checking if stack left with any element
    if(!st.empty()){
        return false;
    }

    return ans;
}

int main(){
    string s = "[{()}]";
    if(isValid(s)){
        cout << "Valid string";
    }
    else{
        cout << "Invalid string";
    }

    cout << endl;
    return 0;
}