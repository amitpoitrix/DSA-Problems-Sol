#include<bits/stdc++.h>
using namespace std;

// Lt: 32. Longest Valid Parentheses
// https://leetcode.com/problems/longest-valid-parentheses/

// Approach 1:
// TC - O(n)
// SC - O(n)
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0)
            return 0;
        
        int maxLength = 0;
        stack<int> st;
        st.push(-1);
        
        for(int i=0; i < s.size(); i++){
            if(s[i] == '(')
                st.push(i);
            
            else{
                st.pop();
                
                if(st.empty())
                    st.push(i);
                else
                    maxLength = max(maxLength, i - st.top());
            }
        }
        
        return maxLength;
    }
};

// Approach 2: 
// TC - O(n)
// SC - O(1)
class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0, maxLength = 0;
        
        // Traversing from left to right
        for(int i=0; i < s.size(); i++){
            if(s[i] == '(')
                open++;
            
            else if(s[i] == ')')
                close++;
            
            if(open == close)
                maxLength = max(maxLength, open + close);
            
            if(close > open){
                open = 0;
                close = 0;
            }
        }
        
        // Traversing from right to left
        open = 0, close = 0;
        for(int i=s.size() - 1; i >= 0; i--){
            if(s[i] == '(')
                open++;
            
            else if(s[i] == ')')
                close++;
            
            if(open == close)
                maxLength = max(maxLength, open + close);
            
            if(open > close){
                open = 0;
                close = 0;
            }
        }
        
        return maxLength;
    }
};

int main(){
    return 0;
}