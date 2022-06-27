#include<iostream>
#include<vector>
using namespace std;
// DP by Striver: DP 51. Burst Balloons | Partition DP
// https://leetcode.com/problems/burst-balloons/

// Memoization
// TC - O(n^3)
// SC - O(n^2) + O(n)
class Solution {
private:
    int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        // Base Case
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int maxi = -1e9;
        for(int idx = i; idx <= j; idx++){
            int cost = (nums[i-1] * nums[idx] * nums[j+1])
                        + f(i, idx - 1, nums, dp) + f(idx + 1, j, nums, dp);
            maxi = max(maxi, cost);
        }
        return dp[i][j] = maxi;
    }
    
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return f(1, n, nums, dp);
    }
};

// Tabulation
// TC - O(n^3)
// SC - O(n^2)
class Solution2{    
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        
        vector<vector<int>> dp(n+2, vector<int> (n+2, 0));
        
        for(int i = n; i >= 1; i--){
            for(int j = 1; j <= n; j++){
                if(i > j) continue; // As here it'll be out of range
                
                int maxi = -1e9;
                for(int idx = i; idx <= j; idx++){
                    int cost = (nums[i-1] * nums[idx] * nums[j+1])
                                + dp[i][idx-1] + dp[idx+1][j];
                    maxi = max(maxi, cost);
                }
                dp[i][j] = maxi;
            }
        }
        
        return dp[1][n];
    }
};

int main(){
    return 0;
}