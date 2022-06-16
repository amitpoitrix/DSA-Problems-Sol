#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// DP by Striver: DP 41. Longest Increasing Subsequence | Memoization
// https://leetcode.com/problems/longest-increasing-subsequence/

// Memoization
// TC - O(n * n)
// SC - O(n * n) + O(n)
class Solution {
private:
    int f(int idx, int prev_idx, vector<int> &nums, vector<vector<int>> &dp){
        // base case
        if(idx == nums.size()) return 0;
        
        if(dp[idx][prev_idx+1] != -1) return dp[idx][prev_idx+1];
        
        int notTake = 0 + f(idx + 1, prev_idx, nums, dp);
        int take = -1e8;
        if(prev_idx == -1 || nums[idx] > nums[prev_idx])
            take = 1 + f(idx + 1, idx, nums, dp);
        
        return dp[idx][prev_idx+1] = max(notTake, take);
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return f(0, -1, nums, dp);
    }
};

// Tabulation
// TC - O(n * n)
// SC - O(n * n)
class Solution2{    
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        // No need to handle base case
        
        for(int idx = n-1; idx >= 0; idx--){
            for(int prev_idx = idx - 1; prev_idx >= -1; prev_idx--){
                int notTake = 0 + dp[idx + 1][prev_idx + 1];
                int take = -1e8;
                if(prev_idx == -1 || nums[idx] > nums[prev_idx])
                    take = 1 + dp[idx + 1][idx + 1];

                dp[idx][prev_idx+1] = max(notTake, take);
            }
        }
        
        return dp[0][-1+1];
    }
};


// Another Tabulation Method
// TC - O(n^2)
// SC - O(n)
class Solution3{    
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        
        int maxi = 1;
        for(int idx = 0; idx < n; idx++){
            for(int prev_idx = 0; prev_idx < idx; prev_idx++){
                if(nums[prev_idx] < nums[idx])
                    dp[idx] = max(dp[idx], 1 + dp[prev_idx]);
            }
            maxi = max(maxi, dp[idx]);
        }
        
        return maxi;
    }
};

// Print LIS
class Solution4{    
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);
        
        int maxi = 1;
        int lastIdx = 0;
        for(int idx = 0; idx < n; idx++){
            hash[idx] = idx;
            for(int prev_idx = 0; prev_idx < idx; prev_idx++){
                if(nums[prev_idx] < nums[idx] && dp[idx] < 1 + dp[prev_idx]){
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
        
        // Print LIS
        for(auto x: lis)
            cout << x << " ";
        cout << "\n";
            
        return maxi;
    }
};

// Length of LIS using Binary Search
// TC - O(nlogn)
// SC - O(n)
class Solution5{    
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        
        for(int i=1; i < n; i++){
            if(nums[i] > temp.back())
                temp.push_back(nums[i]);
            else{
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
        }
        
        return temp.size();
    }
};

int main(){
    return 0;
}