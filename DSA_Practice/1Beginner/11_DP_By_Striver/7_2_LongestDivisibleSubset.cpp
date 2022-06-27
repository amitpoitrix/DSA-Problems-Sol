#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// DP by Striver: DP 44. Largest Divisible Subset | Longest Increasing Subsequence
// https://leetcode.com/problems/largest-divisible-subset/

// TC - O(n^2)
// SC - O(n)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);
        
        int maxi = 1;
        int lastIdx = 0;
        sort(nums.begin(), nums.end());
        
        for(int idx = 0; idx < n; idx++){
            hash[idx] = idx;
            for(int prev_idx = 0; prev_idx < idx; prev_idx++){
                if(nums[idx] % nums[prev_idx] == 0 && dp[idx] < 1 + dp[prev_idx]){
                    dp[idx] = 1 + dp[prev_idx];
                    hash[idx] = prev_idx;   // Bactracking
                }
            }
            if(maxi < dp[idx]){
                maxi = dp[idx];
                lastIdx = idx;
            }
        }
        
        vector<int> lis;
        lis.push_back(nums[lastIdx]);
        
        while(hash[lastIdx] != lastIdx){
            lastIdx = hash[lastIdx];
            lis.push_back(nums[lastIdx]);
        }
        
        reverse(lis.begin(), lis.end());
            
        return lis;
    }
};

int main(){
    return 0;
}