#include<iostream>
#include<vector>
using namespace std;
// DP by Striver: DP 36. Buy and Sell Stock - II | Recursion to Space Optimisation
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// Memoization
// TC - O(n * 2)
// SC - O(n * 2) + O(n)
class Solution {
private:
    int f(int idx, int buy, vector<int> &prices, vector<vector<int>> &dp){
        // base case
        if(idx == prices.size()) return 0;
        
        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        // Allowed to buy
        int profit = 0;
        if(buy){
            profit = max(-prices[idx] + f(idx+1, 0, prices, dp),
                        0 + f(idx+1, 1, prices, dp));
        }
        // Sell
        else{
            profit = max(prices[idx] + f(idx+1, 1, prices, dp),
                        0 + f(idx+1, 0, prices, dp));
        }
        
        return dp[idx][buy] = profit;
    }
    
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, dp);
    }
};

// Tabulation
// TC - O(n * 2)
// SC - O(n * 2)
class Solution2{
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // Base Case
        dp[n][0] = dp[n][1] = 0;
        
        // states
        for(int idx = n-1; idx >= 0; idx--){
            for(int buy = 0; buy <= 1; buy++){
                // Allowed to buy
                int profit = 0;
                if(buy){
                    profit = max(-prices[idx] + dp[idx+1][0],
                                0 + dp[idx+1][1]);
                }
                // Sell
                else{
                    profit = max(prices[idx] + dp[idx+1][1],
                                0 + dp[idx+1][0]);
                }

                dp[idx][buy] = profit;
            }
        }
        
        return dp[0][1];
    }
};

// Space Optimization
// TC - O(n * 2)
// SC - O(2)
class Solution3{
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> front(2, 0), cur(2, 0);
        // Base Case
        front[0] = front[1] = 0;
        
        // states
        for(int idx = n-1; idx >= 0; idx--){
            for(int buy = 0; buy <= 1; buy++){
                // Allowed to buy
                int profit = 0;
                if(buy){
                    profit = max(-prices[idx] + front[0],
                                0 + front[1]);
                }
                // Sell
                else{
                    profit = max(prices[idx] + front[1],
                                0 + front[0]);
                }

                cur[buy] = profit;
            }
            front = cur;
        }
        
        return front[1];
    }
};

// Space Optimization - Using 4 Variables
// TC - O(n)
// SC - (1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int frontBuy, frontNotBuy, curBuy, curNotBuy;
        // Base Case
        frontBuy = frontNotBuy = 0;
        
        // states
        for(int idx = n-1; idx >= 0; idx--){
            // Allowed to buy
            curBuy = max(-prices[idx] + frontNotBuy, frontBuy);
            // Sell
            curNotBuy = max(prices[idx] + frontBuy, frontNotBuy);

            frontNotBuy = curNotBuy;
            frontBuy = curBuy;
        }
        
        return frontBuy;
    }
};

int main(){
    return 0;
}