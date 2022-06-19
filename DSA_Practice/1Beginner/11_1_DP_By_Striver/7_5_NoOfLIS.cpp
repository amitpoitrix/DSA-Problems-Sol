#include<iostream>
#include<vector>
using namespace std;
// DP by Striver: DP 47. Number of Longest Increasing Subsequences
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        
        int maxi = 1;
        for(int idx = 0; idx < n; idx++){
            for(int prev = 0; prev < idx; prev++){
                // If dp is changing than copy the prev count
                if(nums[prev] < nums[idx] && dp[idx] < 1 + dp[prev]){
                    dp[idx] = 1 + dp[prev];
                    count[idx] = count[prev];
                }
                // if dp is same than inc count by prev count
                else if(nums[prev] < nums[idx] && dp[idx] == 1 + dp[prev]){
                    count[idx] += count[prev];
                }
            }
            maxi = max(maxi, dp[idx]);
        }
        
        // Sums up all the LIS count
        int nos = 0;
        for(int idx = 0; idx < n; idx++){
            if(dp[idx] == maxi)
                nos += count[idx];
        }
        
        return nos;
    }
};

int main(){
    return 0;
}