#include<iostream>
#include<vector>
using namespace std;
// DP by Striver : DP 19. 0/1 Knapsack | Single Array Space Optimised Approach | DP on Subsequences

// Using Recursion
// TC - O(2^n)
// SC - O(n)
class Solution{
private:
    int f(int idx, int maxWeight, std::vector<int> &weight, std::vector<int> &value){
        if(maxWeight == 0) return 0;
        
        if(idx == 0){
            if(weight[0] <= maxWeight) return value[0];
            else return 0;
        }

        int notTake = f(idx - 1, maxWeight, weight, value);
        int take = -1e8;
        if(weight[idx] <= maxWeight)
            take = f(idx - 1, maxWeight - weight[idx], weight, value);
        
        return std::max(notTake, take);
    }

public:
    int knapsack(std::vector<int> &weight, std::vector<int> &value, int n, int maxWeight) {
        return f(n - 1, maxWeight, weight, value);
    }
};


// Using DP - Memoization(Top-Down)
// TC - O(n * W)
// SC - O(n * W) + O(n)
class Solution1{
private:
    int f(int idx, int maxWeight, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp){
        // 1st Base Case
        if(maxWeight == 0) return 0;
        // 2nd Base Case
        if(idx == 0){
            if(weight[0] <= maxWeight) 
                return value[0];
            else 
                return 0;
        }

        if(dp[idx][maxWeight] != -1) return dp[idx][maxWeight];

        int notTake = 0 + f(idx - 1, maxWeight, weight, value, dp);
        int take = -1e8;
        if(weight[idx] <= maxWeight)
            take = value[idx] + f(idx - 1, maxWeight - weight[idx], weight, value, dp);
        
        return dp[idx][maxWeight] = max(notTake, take);
    }

public:
    int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight) {
        vector<vector<int>> dp(n, vector<int> (maxWeight + 1, -1));
        return f(n - 1, maxWeight, weight, value, dp);
    }
};


// Using DP - Tabulation(Bottom-Up)
// TC - O(n * W)
// SC - O(n * W)
class Solution2{
public:
    int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight) {
        vector<vector<int>> dp(n, vector<int> (maxWeight + 1, 0));
        // Base Case : when wt[0] <= W than only assign val[0]
        for (int w = weight[0]; w <= maxWeight; w++) 
            dp[0][w] = value[0];
        
        for (int idx = 1; idx < n; idx++){
            for (int w = 1; w <= maxWeight; w++){
                int notTake = 0 + dp[idx - 1][w];
                int take = -1e8;
                if(weight[idx] <= w)
                    take = value[idx] + dp[idx - 1][w - weight[idx]];
                
                dp[idx][w] = max(notTake, take);
            }
        }

        return dp[n-1][maxWeight];
    }
};


// Space Optimization on Tabulation(Bottom-Up)
// TC - O(n * W)
// SC - O(W) + O(W); using 2 arrays
class Solution3{
public:
    int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight) {
        vector<int> prev(maxWeight + 1, 0), curr(maxWeight + 1, 0);
        // Base Case
        for (int w = weight[0]; w <= maxWeight; w++) 
            prev[w] = value[0];
        
        for (int idx = 1; idx < n; idx++){
            for (int w = 1; w <= maxWeight; w++){ 
                int notTake = 0 + prev[w];
                int take = -1e8;
                if(weight[idx] <= w)
                    take = value[idx] + prev[w - weight[idx]];
                
                curr[w] = max(notTake, take);
            }
            prev = curr;
        }

        return prev[maxWeight];
    }
};


// Space Optimization on Tabulation(Bottom-Up) - Single Array Optimization
// TC - O(n * W)
// SC - O(W)
class Solution4{
public:
    int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight) {
        vector<int> prev(maxWeight + 1, 0);
        // Base Case
        for (int w = weight[0]; w <= maxWeight; w++) 
            prev[w] = value[0];
        
        for (int idx = 1; idx < n; idx++){
            // Iterating w from Right to left
            for (int w = maxWeight; w >= 1; w--){
                int notTake = 0 + prev[w];
                int take = -1e8;
                if(weight[idx] <= w)
                    take = value[idx] + prev[w - weight[idx]];
                
                prev[w] = max(notTake, take);
            }
        }

        return prev[maxWeight];
    }
};


int main(){
    std::vector<int> weight = {7};
    std::vector<int> value = {1};
    int maxWeight = 1;
    int n = weight.size();

    Solution3 obj;
    std::cout << obj.knapsack(weight, value, n, maxWeight);

    return 0;
}