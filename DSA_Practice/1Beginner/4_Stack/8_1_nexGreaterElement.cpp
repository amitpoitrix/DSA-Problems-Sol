#include <bits/stdc++.h>
using namespace std;

// Next Greater Element
// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1/

// TC - O(n) 
// SC - O(n)
class Solution{
public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> res;
        stack<long long> st;
        
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= arr[i]){
                st.pop();
            }
            
            if(st.empty())
                res.push_back(-1);
            else
                res.push_back(st.top());
            
            st.push(arr[i]);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};


int main(){
    return 0;
}