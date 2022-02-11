#include<iostream>
#include<vector>
#include<limits.h>
// DP by Striver : DP 4. Frog Jump with K Distance
// Now frog can jump from i -> i+1, i+2, i+3.... i+k
// https://atcoder.jp/contests/dp/tasks/dp_b

// Using Recursion
// TC - O(n * k)
class Solution{
private:
    int recursiveFrogJumpk(int idx, std::vector<int> &heights, int k){
        if(idx == 0)
            return 0;
        
        int minStep = INT_MAX;
        for (int j = 1; j <= k; j++){
            if(idx - j >= 0){
                int jump = recursiveFrogJumpk(idx - j, heights, k) + abs(heights[idx] - heights[idx - j]);
                minStep = std::min(minStep, jump);
            }
        }
        
        return minStep;
    }

public:
    int frogJump(int n, std::vector<int> &heights, int k){
        return recursiveFrogJumpk(n-1, heights, k);
    }
};


// Using DP
// 1st Method : Memoization(Top-Down)
// TC - O(n * k)
// SC - O(n) + O(n)
class Solution1{
private:
    int recursiveFrogJumpk(int idx, std::vector<int> &heights, int k, std::vector<int> &dp){
        if(idx == 0)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];

        int minStep = INT_MAX;
        for (int j = 1; j <= k; j++){
            if(idx - j >= 0){
                int jump = recursiveFrogJumpk(idx - j, heights, k, dp) + abs(heights[idx] - heights[idx - j]);
                minStep = std::min(minStep, jump);
            }
        }
        
        return dp[idx] = minStep;
    }

public:
    int frogJump(int n, std::vector<int> &heights, int k){
        std::vector<int> dp(n+1, -1);
        return recursiveFrogJumpk(n-1, heights, k, dp);
    }
};


// 2nd Method : Tabulation(Bottom-Up) - 1D DP
// TC - O(n * k)
// SC - O(n)
class Solution2{
public:
    int frogJump(int n, std::vector<int> &heights, int k){
        std::vector<int> dp(n, -1);
        dp[0] = 0;

        for (int i = 1; i < n; i++){
            int minStep = INT_MAX;
            for (int j = 1; j <= k; j++){
                if(i - j >= 0){
                    int jump = dp[i - j] + abs(heights[i] - heights[i - j]);
                    minStep = std::min(minStep, jump);
                }
            }
            dp[i] = minStep;
        }
        
        return dp[n-1];
    }
};


int main(){
    std::vector<int> heights = {40, 10, 20, 70, 80, 10, 20, 70, 80, 60};
    int n = heights.size();
    int k = 4;

    Solution2 obj;
    std::cout << obj.frogJump(n, heights, k);

    return 0;
}