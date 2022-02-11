#include<iostream>
#include<vector>
// DP by Striver : DP 5. Maximum Sum of Non-Adjacent Elements | House Robber | 1-D | DP on Subsequences

// Using Recursion
// TC - O(2^n)
class Solution{
private:
    int recursiveMaxSum(int idx, std::vector<int> &nums){
        if(idx == 0)
            return nums[idx];
        
        if(idx < 0)
            return 0;
        
        int pick = nums[idx] + recursiveMaxSum(idx - 2, nums);
        int notPick = 0 + recursiveMaxSum(idx - 1, nums);

        return std::max(pick, notPick);
    }

public:
    int maximumNonAdjacentSum(std::vector<int> &nums){
        int n = nums.size();
        return recursiveMaxSum(n-1, nums);
    }
};


// Using DP
// 1st Method - Memoization(Bottom-Up Approach)
// TC - O(n)
// SC - O(n) + O(n)
class Solution1{
private:
    int recursiveMaxSum(int idx, std::vector<int> &nums, std::vector<int> &dp){
        if(idx == 0)
            return nums[idx];
        
        if(idx < 0)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int pick = nums[idx] + recursiveMaxSum(idx - 2, nums, dp);
        int notPick = 0 + recursiveMaxSum(idx - 1, nums, dp);

        return dp[idx] = std::max(pick, notPick);
    }

public:
    int maximumNonAdjacentSum(std::vector<int> &nums){
        int n = nums.size();
        std::vector<int> dp(n+1, -1);
        return recursiveMaxSum(n-1, nums, dp);
    }
};


// 2nd Method : Tabulation(Top-Down)
// TC - O(n)
// SC - O(n)
class Solution2{
public:
    int maximumNonAdjacentSum(std::vector<int> &nums){
        int n = nums.size();
        std::vector<int> dp(n, -1);
        dp[0] = nums[0];
        int neg = 0;

        for (int i = 1; i < n; i++){
            int pick = nums[i] + neg;
            if(i > 1)
                pick += dp[i-2];
            
            int notPick = 0 + dp[i-1];

            dp[i] = std::max(pick, notPick);
        }
        
        return dp[n-1];
    }
};


// Space Optimization in Tabulation Method
// TC - O(n)
// SC - O(1)
class Solution3{
public:
    int maximumNonAdjacentSum(std::vector<int> &nums){
        int n = nums.size();
        int prev1 = nums[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++){
            int pick = nums[i];
            if(i > 1)
                pick += prev2;
            
            int notPick = 0 + prev1;

            int cur = std::max(pick, notPick);

            prev2 = prev1;
            prev1 = cur;
        }
        
        return prev1;
    }
};


int main(){
    std::vector<int> nums = {2,1,4,9};

    Solution3 obj;
    std::cout << obj.maximumNonAdjacentSum(nums);

    return 0;
}