#include<bits/stdc++.h>
using namespace std;

// Maximum Rectangular Area in a Histogram 
// https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1#

class Solution{
private:
    // Next Smallest Element On Right
    vector<long long> nsr(long long arr[], int n){
        vector<long long> right;
        stack<int> st;
        int pseudoIdx = n;
        
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            if(st.empty())
                right.push_back(pseudoIdx);
            else
                right.push_back(st.top());
            
            st.push(i);
        }
        
        reverse(right.begin(), right.end());
        return right;
    }
    
    // Next Smallest Element On Left
    vector<long long> nsl(long long arr[], int n){
        vector<long long> left;
        stack<int> st;
        int pseudoIdx = -1;
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            if(st.empty())
                left.push_back(pseudoIdx);
            else
                left.push_back(st.top());
            
            st.push(i);
        }
        
        return left;
    }
    
public:
    long long getMaxArea(long long arr[], int n){
        vector<long long> right = nsr(arr, n);
        vector<long long> left = nsl(arr, n);
        
        vector<long long> width(n);
        long long maxArea = 0;
        
        for(int i = 0; i < n; i++){
            width[i] = right[i] - left[i] - 1;
            maxArea = max(maxArea, width[i] * arr[i]);
        }
        
        return maxArea;
    }
};

int main(){
    return 0;
}