#include<bits/stdc++.h>
using namespace std;

// 85. Maximal Rectangle
// https://leetcode.com/problems/maximal-rectangle/

// This Approach is Giving TLE in GFG but not in Leetcode
class Solution {
private:
    vector<int> nsr(int arr[], int n){
        vector<int> right;
        stack<pair<int, int>> st;
        int pseudoIdx = n;
        
        for(int i = n-1; i >= 0; i--){
            if(st.empty())
                right.push_back(pseudoIdx);
                
            else if(!st.empty() && st.top().first < arr[i])
                right.push_back(st.top().second);
                
            else if(!st.empty() && st.top().first >= arr[i]){
                while(!st.empty() && st.top().first >= arr[i]){
                    st.pop();
                }
                
                if(st.empty())
                    right.push_back(pseudoIdx);
                else
                    right.push_back(st.top().second);
            }
            
            st.push({arr[i], i});
        }
        
        reverse(right.begin(), right.end());
        return right;
    }
    
    // Next Smallest Element On Left
    vector<int> nsl(int arr[], int n){
        vector<int> left;
        stack<pair<int, int>> st;
        int pseudoIdx = -1;
        
        for(int i = 0; i < n; i++){
                while(!st.empty() && st.top().first >= arr[i]){
                    st.pop();
                }
                
                if(st.empty())
                    left.push_back(pseudoIdx);
                else
                    left.push_back(st.top().second);

            
            st.push({arr[i], i});
        }
        
        return left;
    }
    
    //Function to find largest rectangular area possible in a given histogram.
    int MAH(int arr[], int n){
        vector<int> right = nsr(arr, n);
        vector<int> left = nsl(arr, n);
        
        vector<int> width(n);
        int maxArea = 0;
        
        for(int i = 0; i < n; i++){
            width[i] = right[i] - left[i] - 1;
            maxArea = max(maxArea, width[i] * arr[i]);
        }
        
        return maxArea;
    }    
    
public:
    int maximalRectangle(vector<vector<char>>& M) {
        int n = M.size();
        int m = M[0].size();
        int row[m];
        for(int j = 0; j < m; j++){
            row[j] = M[0][j] - '0';
        }
        
        int mx = MAH(row, m);
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(M[i][j] == '0')
                    row[j] = 0;
                else
                    row[j] = row[j] + (M[i][j] - '0');
            }
            mx = max(mx, MAH(row, m));
        }
        
        return mx;
    }
};

int main(){
    return 0;
}