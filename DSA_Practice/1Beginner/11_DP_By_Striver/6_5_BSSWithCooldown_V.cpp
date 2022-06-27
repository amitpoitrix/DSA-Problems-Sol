#include<iostream>
#include<vector>
using namespace std;
// DP by Striver: DP 39. Buy and Sell Stocks With Cooldown | Recursion to Space Optimisation
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

// Memoization
// TC - O(n * 2)
// SC - O(n * 2) + O(n)
class Solution {
private:
    int f(int idx, int buy, vector<int> &prices, vector<vector<int>> &dp){
        if(idx >= prices.size()) return 0;
        
        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        if(buy)
            return dp[idx][buy] = max(-prices[idx] + f(idx+1, 0, prices, dp),
                      0 + f(idx+1, 1, prices, dp));
        
        return dp[idx][buy] = max(prices[idx] + f(idx+2, 1, prices, dp),
                  0 + f(idx+1, 0, prices, dp));
    }
    
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return f(0, 1, prices, dp);
    }
};

// Tabulation
// TC - O(n)
// SC - O(n)
class Solution2{    
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int> (2, 0));
        
        for(int idx = n-1; idx >= 0; idx--){
            dp[idx][1] = max(-prices[idx] + dp[idx+1][0],
                              0 + dp[idx+1][1]);

            dp[idx][0] = max(prices[idx] + dp[idx+2][1],
                          0 + dp[idx+1][0]);
        }
        
        return dp[0][1];
    }
};

// Space Optimization
// TC - O(n)
// SC - O(1)
class Solution3{    
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> front2(2, 0), front1(2, 0), cur(2, 0);
        
        for(int idx = n-1; idx >= 0; idx--){
            cur[1] = max(-prices[idx] + front1[0],
                              0 + front1[1]);

            cur[0] = max(prices[idx] + front2[1],
                          0 + front1[0]);
            
            front2 = front1;
            front1 = cur;
        }
        
        return front1[1];
    }
};

int main(){
    return 0;
}