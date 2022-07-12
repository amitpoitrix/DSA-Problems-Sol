#include<bits/stdc++.h>
using namespace std;

// Lt: 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            
            else{
                if(st.empty())
                    return false;
                
                char ch = st.top();
                st.pop();
                
                if((s[i] == ')' && ch != '(') || (s[i] == '}' && ch != '{') || (s[i] == ']' && ch != '['))
                    return false;
            }
        }
        
        if(st.empty())
            return true;
        
        return false;
    }
};

int main(){
    return 0;
}