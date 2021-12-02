#include<iostream>
#include<stack>
using namespace std;
// Pepcoding - Find Duplicates Parenthesis using stack
// eg : 1. ((a+b)+(c+d)) -> False ; 2. (a+b)+((a+b)) -> True

int main(){
    string str;
    cin >> str;

    stack<char> st;

    for (int i = 0; i < str.size(); i++){
        char ch = str[i];
        // if closing bracket encounters than check if top element is opening bracket if yes than its duplicate
        if(ch == ')'){
            if(st.top() == '('){
                cout << "True" << endl;
                return 0;
            }
            else{
                while (st.top() != '('){
                    st.pop();
                }
                st.pop();
            }
        }
        // If other than closing bracket encounter than directly push it into the stack
        else{
            st.push(ch);
        }
    }

    // if no duplicate parenthesis found than print false  
    cout << "False";

    cout << endl;
    return 0;
}