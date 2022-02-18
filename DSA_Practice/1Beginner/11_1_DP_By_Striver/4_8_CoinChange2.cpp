#include<iostream>
#include<vector>
// DP by Striver : DP 22. Coin Change 2 | Infinite Supply Problems | DP on Subsequences
// Find Total No. of Ways we can make a change for Target T

// Using Recursion
// TC - >> O(2^n) or Exponential time
// SC - O(n)
class Solution{
private:
    long f(int idx, int target, int *a){
        if(idx == 0){
            if(target % a[0] == 0) return 1;
            else return 0;
        }

        long notTaken = f(idx - 1, target, a);
        long take = 0;
        if(a[idx] <= target) take = f(idx, target - a[idx], a);

        return notTaken + take;
    }

public:
    long countWaysToMakeChange(int *denominations, int n, int value){
        return f(n-1, value, denominations);
    }
};


// Using DP - Memoization(Top-Down)
// TC - O(n * target)
// SC - O(n * target) + O(n)
class Solution1{
private:
    long f(int idx, int target, int *a, std::vector<std::vector<long>> &dp){
        if(idx == 0){
            if(target % a[0] == 0) return 1;
            else return 0;
        }

        if(dp[idx][target] != -1) return dp[idx][target];

        long notTaken = f(idx - 1, target, a, dp);
        long take = 0;
        if(a[idx] <= target) take = f(idx, target - a[idx], a, dp);

        return dp[idx][target] = notTaken + take;
    }

public:
    long countWaysToMakeChange(int *denominations, int n, int value){
        std::vector<std::vector<long>> dp(n, std::vector<long>(value + 1, -1));
        return f(n-1, value, denominations, dp);
    }
};


// Using DP - Tabulation(Bottom-Up)
// TC - O(n * target)
// SC - O(n * target)
class Solution2{
public:
    long countWaysToMakeChange(int *denominations, int n, int value){
        std::vector<std::vector<long>> dp(n, std::vector<long>(value + 1, 0));
        // Base Case for Tabulation
        for (int target = 0; target <= value; target++){
            if(target % denominations[0] == 0)
                dp[0][target] = 1;
        }
        
        for (int idx = 1; idx < n; idx++){
            for (int target = 0; target <= value; target++){
                long notTaken = dp[idx - 1][target];
                long take = 0;
                if(denominations[idx] <= target) take = dp[idx][target - denominations[idx]];

                dp[idx][target] = notTaken + take;
            }
        }
        
        return dp[n-1][value];
    }
};


// Space Complexity on Tabulation(Bottom-Up)
// TC - O(n * target)
// SC - O(n * target)
class Solution3{
public:
    long countWaysToMakeChange(int *denominations, int n, int value){
        std::vector<long> prev(value + 1, 0), curr(value + 1, 0);
        // Base Case for Tabulation
        for (int target = 0; target <= value; target++){
            if(target % denominations[0] == 0)
                prev[target] = 1;
        }
        
        for (int idx = 1; idx < n; idx++){
            for (int target = 0; target <= value; target++){
                long notTaken = prev[target];
                long take = 0;
                if(denominations[idx] <= target) take =curr[target - denominations[idx]];

                curr[target] = notTaken + take;
            }
            prev = curr;
        }
        
        return prev[value];
    }
};


int main(){

    return 0;
}