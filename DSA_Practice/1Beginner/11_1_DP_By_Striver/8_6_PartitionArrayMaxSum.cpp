#include<iostream>
#include<vector>
using namespace std;
// DP by Striver: DP 54. Partition Array for Maximum Sum | Front Partition
// https://leetcode.com/problems/partition-array-for-maximum-sum/

// Memoization
// TC - O(n*k)
// SC - O(n) + O(n)
class Solution {
private:
    int min(int a, int b){
        if(a < b) 
            return a;
        return b;
    }
    
    int f(int idx, vector<int> &arr, int k, vector<int> &dp){
        // Base Case
        if(idx == arr.size()) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int len = 0;
        int maxi = -1e9;
        int maxAns = -1e9;
        for(int j = idx; j < min(idx + k, arr.size()); j++){
            len++;
            maxi = max(maxi, arr[j]);
            int sum = (len * maxi) + f(j+1, arr, k, dp);
            maxAns = max(maxAns, sum);
        }
        
        return dp[idx] = maxAns;
    }
    
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(0, arr, k, dp);
    }
};

// Tabulation
// TC - O(n * k)
// SC - O(n)
class Solution2{
private:
    int min(int a, int b){
        if(a < b) 
            return a;
        return b;
    }
    
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        
        for(int idx = n-1; idx >= 0; idx--){
            int len = 0;
            int maxi = -1e9;
            int maxAns = -1e9;
            for(int j = idx; j < min(idx + k, n); j++){
                len++;
                maxi = max(maxi, arr[j]);
                int sum = (len * maxi) + dp[j+1];
                maxAns = max(maxAns, sum);
            }
            dp[idx] = maxAns;
        }
        
        return dp[0];
    }
};

int main(){
    return 0;
}