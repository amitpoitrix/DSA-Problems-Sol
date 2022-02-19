#include<iostream>
#include<vector>
// DP by Striver : DP 23. Unbounded Knapsack | 1-D Array Space Optimised Approach
// Here Repeatition of Element is Allowed infinite no. of times where in 0/1 only single use is allowed

// Using Recursion
// TC - >> O(2^n) i.e., Exponential time
// SC - O(w)
class Solution{
private:
    int f(int idx, int wt, std::vector<int> &profit, std::vector<int> &weight){
        if(idx == 0) return (int)(wt / weight[0]) * profit[0];

        int notTake = 0 + f(idx - 1, wt, profit, weight);
        int take = 0;
        if(weight[idx] <= wt) take = profit[idx] + f(idx, wt - weight[idx], profit, weight);

        return std::max(notTake, take);
    }

public:
    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
        return f(n - 1, w, profit, weight);
    }
};


// Using DP - Memoization(Top-Down)
// TC - O(n * w)
// SC - O(n * w) + O(w)
class Solution1{
private:
    int f(int idx, int wt, std::vector<int> &profit, std::vector<int> &weight, std::vector<std::vector<int>> &dp){
        if(idx == 0) return dp[idx][wt] = (int)(wt / weight[0]) * profit[0];

        if(dp[idx][wt] != -1) return dp[idx][wt];

        int notTake = 0 + f(idx - 1, wt, profit, weight, dp);
        int take = 0;
        if(weight[idx] <= wt) take = profit[idx] + f(idx, wt - weight[idx], profit, weight, dp);

        return dp[idx][wt] = std::max(notTake, take);
    }

public:
    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
        std::vector<std::vector<int>> dp(n, std::vector<int>(w + 1, -1));
        return f(n - 1, w, profit, weight, dp);
    }
};


// Using DP - Tabulation(Bottom-Up)
// TC - O(n * w)
// SC - O(n * w)
class Solution2{
public:
    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
        std::vector<std::vector<int>> dp(n, std::vector<int>(w + 1, 0));
        // Base Case for Tabulation
        for (int wt = 0; wt <= w; wt++){
            dp[0][wt] = (int)(wt / weight[0]) * profit[0];
        }
        
        for (int idx = 1; idx < n; idx++){
            for (int wt = 0; wt <= w; wt++){
                int notTake = 0 + dp[idx - 1][wt];
                int take = 0;
                if(weight[idx] <= wt) take = profit[idx] + dp[idx][wt - weight[idx]];

                dp[idx][wt] = std::max(notTake, take);   
            }
        }

        return dp[n - 1][w];
    }
};


// Space Complexity on Tabulation(Bottom-Up)
// TC - O(n * w)
// SC - O(w) + O(w)
class Solution3{
public:
    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
        std::vector<int> prev(w + 1, 0), curr(w + 1, 0);
        // Base Case for Tabulation
        for (int wt = 0; wt <= w; wt++){
            prev[wt] = (int)(wt / weight[0]) * profit[0];
        }
        
        for (int idx = 1; idx < n; idx++){
            for (int wt = 0; wt <= w; wt++){
                int notTake = 0 + prev[wt];
                int take = 0;
                if(weight[idx] <= wt) take = profit[idx] + curr[wt - weight[idx]];

                curr[wt] = std::max(notTake, take);   
            }
            prev = curr;
        }

        return prev[w];
    }
};


// Space Complexity on Tabulation(Bottom-Up) - Single Array Approach
// TC - O(n * w)
// SC - O(w)
class Solution4{
public:
    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
        std::vector<int> prev(w + 1, 0);
        // Base Case for Tabulation
        for (int wt = 0; wt <= w; wt++){
            prev[wt] = (int)(wt / weight[0]) * profit[0];
        }
        
        for (int idx = 1; idx < n; idx++){
            for (int wt = 0; wt <= w; wt++){
                int notTake = 0 + prev[wt];
                int take = 0;
                if(weight[idx] <= wt) take = profit[idx] + prev[wt - weight[idx]];

                prev[wt] = std::max(notTake, take);   
            }
        }

        return prev[w];
    }
};


int main(){

    return 0;
}