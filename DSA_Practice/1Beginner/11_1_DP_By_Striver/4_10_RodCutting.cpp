#include<iostream>
#include<vector>
// DP by Striver : DP 24. Rod Cutting Problem | 1D Array Space Optimised Approach
// Last Ques on DP on Subsequence

// Rod Cutting Problem is basically cutting of Rods from length 1....n of n length rod & each length rod has a price. We need to find
// how the rod should be cut so as to earn max value. A fix size Rod can be used Infinite/Multiple amount of times
// This Rod Cutting Problem is same as Unbounded Knapsack Problem

// Using Recursion
// TC - >> O(2^n) i.e., Exponential
// SC - O(n)
class Solution{
private:
    int f(int idx, int N, std::vector<int> &price){
        if(idx == 0) return N * price[0];   // lets say when idx reaches 0 length of Rod left(N) is 12 & 0th Rod will be of 
        // size 1(i.e., idx + 1) so we will require 12 such 1 length size of Rods to meet N.

        int notTake = 0 + f(idx - 1, N, price);
        int take = -1e9;
        int rodLength = idx + 1;    // As length of Rod is from 1 .... n
        if(rodLength <= N) take = price[idx] + f(idx, N - rodLength, price);

        return std::max(notTake, take);
    }

public:
    int cutRod(std::vector<int> &price, int n){
        return f(n-1, n, price);
    }
};


// Using DP - Memoization(Top-Down)
// TC - O(n * n)
// SC - O(n * n) + O(n)
class Solution1{
private:
    int f(int idx, int N, std::vector<int> &price, std::vector<std::vector<int>> &dp){
        if(idx == 0) return N * price[0];   // lets say when idx reaches 0 length of Rod left(N) is 12 & 0th Rod will be of 
        // size 1(i.e., idx + 1) so we will require 12 such 1 length size of Rods to meet N.

        if(dp[idx][N] != -1) return dp[idx][N];
        int notTake = 0 + f(idx - 1, N, price, dp);
        int take = -1e9;
        int rodLength = idx + 1;    // As length of Rod is from 1 .... n
        if(rodLength <= N) take = price[idx] + f(idx, N - rodLength, price, dp);

        return dp[idx][N] = std::max(notTake, take);
    }

public:
    int cutRod(std::vector<int> &price, int n){
        std::vector<std::vector<int>> dp(n, std::vector<int>(n + 1, -1));
        return f(n-1, n, price, dp);
    }
};


// Using DP - Tabulation(Bottom-Up)
// TC - O(n * n)
// SC - O(n * n)
class Solution2{
public:
    int cutRod(std::vector<int> &price, int n){
        std::vector<std::vector<int>> dp(n, std::vector<int>(n + 1, -1));
        // Base Case for Tabulation
        for (int N = 0; N <= n; N++){
            dp[0][N] = N * price[0];
        }
        
        for (int idx = 1; idx < n; idx++){
            for (int N = 0; N <= n; N++){
                int notTake = 0 + dp[idx - 1][N];
                int take = -1e9;
                int rodLength = idx + 1;
                if(rodLength <= N) take = price[idx] + dp[idx][N - rodLength];

                dp[idx][N] = std::max(notTake, take);   
            }
        }
        
        return dp[n-1][n];
    }
};


// Space Complexity on Tabulation(Bottom-Up)
// TC - O(n * n)
// SC - O(n) + O(n)
class Solution3{
public:
    int cutRod(std::vector<int> &price, int n){
        std::vector<int> prev(n+1, 0), curr(n+1, 0);
        // Base Case for Tabulation
        for (int N = 0; N <= n; N++){
            prev[N] = N * price[0];
        }
        
        for (int idx = 1; idx < n; idx++){
            for (int N = 0; N <= n; N++){
                int notTake = 0 + prev[N];
                int take = -1e9;
                int rodLength = idx + 1;
                if(rodLength <= N) take = price[idx] + curr[N - rodLength];

                curr[N] = std::max(notTake, take);   
            }
            prev = curr;
        }
        
        return prev[n];
    }
};


// Space Complexity on Tabulation(Bottom-Up) - Single Array Approach
// TC - O(n * n)
// SC - O(n)
class Solution4{
public:
    int cutRod(std::vector<int> &price, int n){
        std::vector<int> prev(n+1, 0);
        // Base Case for Tabulation
        for (int N = 0; N <= n; N++){
            prev[N] = N * price[0];
        }
        
        for (int idx = 1; idx < n; idx++){
            for (int N = 0; N <= n; N++){
                int notTake = 0 + prev[N];
                int take = -1e9;
                int rodLength = idx + 1;
                if(rodLength <= N) take = price[idx] + prev[N - rodLength];

                prev[N] = std::max(notTake, take);   
            }
        }
        
        return prev[n];
    }
};


int main(){

    return 0;
}