#include<iostream>
#include<vector>
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
    int f(int idx, int maxWeight, std::vector<int> &weight, std::vector<int> &value, std::vector<std::vector<int>> &dp){
        if(maxWeight == 0) return 0;
        
        if(idx == 0){
            if(weight[0] <= maxWeight) return value[0];
            else return 0;
        }

        if(dp[idx][maxWeight] != -1) return dp[idx][maxWeight];

        int notTake = 0 + f(idx - 1, maxWeight, weight, value, dp);
        int take = -1e8;
        if(weight[idx] <= maxWeight)
            take = value[idx] + f(idx - 1, maxWeight - weight[idx], weight, value, dp);
        
        return dp[idx][maxWeight] = std::max(notTake, take);
    }

public:
    int knapsack(std::vector<int> &weight, std::vector<int> &value, int n, int maxWeight) {
        std::vector<std::vector<int>> dp(n, std::vector<int> (maxWeight + 1, -1));
        return f(n - 1, maxWeight, weight, value, dp);
    }
};


// Using DP - Tabulation(Bottom-Up)
// TC - O(n * W)
// SC - O(n * W)
class Solution2{
public:
    int knapsack(std::vector<int> &weight, std::vector<int> &value, int n, int maxWeight) {
        std::vector<std::vector<int>> dp(n, std::vector<int> (maxWeight + 1, 0));
        // Base Case for Tabulation & it should start from weight[0] instead of 1 
        for (int w = weight[0]; w <= maxWeight; w++) dp[0][w] = value[0];
        
        for (int idx = 1; idx < n; idx++){
            for (int w = 0; w <= maxWeight; w++){
                int notTake = 0 + dp[idx - 1][w];
                int take = -1e8;
                if(weight[idx] <= w)
                    take = value[idx] + dp[idx - 1][w - weight[idx]];
                
                dp[idx][w] = std::max(notTake, take);
            }
        }

        return dp[n-1][maxWeight];
    }
};


// Space Optimization on Tabulation(Bottom-Up)
// TC - O(n * W)
// SC - O(W) + O(W)
class Solution3{
public:
    int knapsack(std::vector<int> &weight, std::vector<int> &value, int n, int maxWeight) {
        std::vector<int> prev(maxWeight + 1, 0), curr(maxWeight + 1, 0);
        // Base Case for Tabulation & it should start from weight[0] instead of 1 
        for (int w = weight[0]; w <= maxWeight; w++) 
            prev[w] = value[0];
        
        for (int idx = 1; idx < n; idx++){
            for (int w = 0; w <= maxWeight; w++){ 
                int notTake = 0 + prev[w];
                int take = -1e8;
                if(weight[idx] <= w)
                    take = value[idx] + prev[w - weight[idx]];
                
                curr[w] = std::max(notTake, take);
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
    int knapsack(std::vector<int> &weight, std::vector<int> &value, int n, int maxWeight) {
        std::vector<int> prev(maxWeight + 1, 0);
        // Base Case for Tabulation & it should start from weight[0] instead of 1 
        for (int w = weight[0]; w <= maxWeight; w++) prev[w] = value[0];
        
        for (int idx = 1; idx < n; idx++){
            // As we require prev[] for both the case(i.e., pick or notPick) so iterating from last(or Max) Weight 
            for (int w = maxWeight; w >= 0; w--){
                int notTake = 0 + prev[w];
                int take = -1e8;
                if(weight[idx] <= w)
                    take = value[idx] + prev[w - weight[idx]];
                
                prev[w] = std::max(notTake, take);
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