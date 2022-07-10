#include <bits/stdc++.h>
using namespace std;

// The Stock Span Problem (GFG)
// https://www.geeksforgeeks.org/the-stock-span-problem/

class Solution1{
public:
    vector<int> stockSpan(vector<int> arr){
         // First calculate Next Greatest on Left (index-wise)
        int n = arr.size(), pseudoIdx = -1;
        vector<int> ngl;
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }

            if(st.empty())
                ngl.push_back(pseudoIdx);
            else
                ngl.push_back(st.top());

            st.push(i);
        }

        // Now computing the stock span of all n days
        vector<int> span;
        for(int i = 0; i < n; i++){
            span.push_back(i - ngl[i]);
        }

        return span;
    }
};

class Solution{
public:
    vector<int> stockSpan(vector<int> arr){
        // First calculate Next Greatest on Left (index-wise)
        int n = arr.size(), pseudoIdx = -1;
        vector<int> ngl;
        stack<pair<int, int>> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top().first <= arr[i]){
                st.pop();
            }

            if(st.empty())
                ngl.push_back(pseudoIdx);
            else
                ngl.push_back(st.top().second);

            st.push({arr[i], i});
        }

        // Now computing the stock span of all n days
        vector<int> span;
        for(int i = 0; i < n; i++){
            span.push_back(i - ngl[i]);
        }

        return span;
    }
};

// Lt: 901. Online Stock Span
// https://leetcode.com/problems/online-stock-span/

// For Computing Individual Span based on its price
class StockSpanner {    
public:
    stack<pair<int, int>> st;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;
        while(!st.empty() && st.top().first <= price){
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main(){
    return 0;
}