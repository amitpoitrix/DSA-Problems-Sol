#include<iostream>
#include<vector>
using namespace std;
// DP by Striver: DP 37. Buy and Sell Stocks III | Recursion to Space Optimisation
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

// Memoization
// TC - O(n * 2 * 3)
// SC - O(n * 2 * 3) + O(n)
class Solution {
private:
    int f(int idx, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp){
        // base case
        if(cap == 0) return 0;
        if(idx == prices.size()) return 0;
        
        if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
        
        // buy
        if(buy)
            return dp[idx][buy][cap] = max(-prices[idx] + f(idx+1, 0, cap, prices, dp),
                  0 + f(idx+1, 1, cap, prices, dp));
        
        // sell
        return dp[idx][buy][cap] = max(prices[idx] + f(idx+1, 1, cap-1, prices, dp),
                  0 + f(idx+1, 0, cap, prices, dp));
    }
    
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 3D dp
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        return f(0, 1, 2, prices, dp);
    }
};

// Tabulation
// TC - O(n * 2 * 3)
// SC - O(n * 2 * 3)
class Solution2{
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));
        
        // No need to handle base case as everything is already been assign to 0
        
        for(int idx = n-1; idx >= 0; idx--){
            for(int buy = 0; buy <= 1; buy++){
                // Cap should start from 1 as for 0 it is handle in base case i.e., cap == 0 return 0
                for(int cap = 1; cap <= 2; cap++){
                    // buy
                    if(buy){
                        dp[idx][buy][cap] = max(-prices[idx] + dp[idx+1][0][cap] ,
                              0 + dp[idx+1][1][cap]);
                    }

                    // sell
                    else{
                        dp[idx][buy][cap] = max(prices[idx] + dp[idx+1][1][cap-1],
                              0 + dp[idx+1][0][cap]);
                    }
                }
            }
        }
        
        return dp[0][1][2];
    }
};

// Space Optimization
// TC - O(n * 2 * 3)
// SC - O(2 * 3)
class Solution3{
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> front(2, vector<int> (3, 0));
        vector<vector<int>> cur(2, vector<int> (3, 0));
        
        for(int idx = n-1; idx >= 0; idx--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= 2; cap++){
                    // buy
                    if(buy){
                        cur[buy][cap] = max(-prices[idx] + front[0][cap] ,
                              0 + front[1][cap]);
                    }

                    // sell
                    else{
                        cur[buy][cap] = max(prices[idx] + front[1][cap-1],
                              0 + front[0][cap]);
                    }
                }
            }
            front = cur;
        }
        
        return front[1][2];
    }
};

// Another Solution - Using dp[N][4]
// Memoization
// TC - O(n * 4)
// SC - O(n * 4) + O(n)
class Solution4{
private:
    int f(int idx, int trans, vector<int> &prices, vector<vector<int>> &dp){
        // Base Case
        if(idx == prices.size() || trans == 4) return 0;
        
        if(dp[idx][trans] != -1) return dp[idx][trans];
        
        // Buy - Even
        if(trans % 2 == 0)
            return dp[idx][trans] = max(-prices[idx] + f(idx+1, trans+1, prices, dp),
                      0 + f(idx+1, trans, prices, dp));
        
        // sell - odd
        return dp[idx][trans] = max(prices[idx] + f(idx+1, trans+1, prices, dp),
                  0 + f(idx+1, trans, prices, dp));
    }
    
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (4, -1));
        return f(0, 0, prices, dp);
    }
};

// Tabulation
// TC - O(n * 5)
// SC - O(n * 5)
class Solution5{    
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (5, 0));
        
        // states
        for(int idx = n-1; idx >= 0; idx--){
            for(int trans = 0; trans < 4; trans++){
                // buy - even
                if(trans % 2 == 0){
                    dp[idx][trans] = max(-prices[idx] + dp[idx+1][trans+1],
                              0 + dp[idx+1][trans]);
                }

                // sell - odd
                else{
                    dp[idx][trans] = max(prices[idx] + dp[idx+1][trans+1],
                          0 + dp[idx+1][trans]);
                }
            }
        }
        
        return dp[0][0];
    }
};

// Space Optimization
// TC - O(n * 5)
// SC - O(5)
class Solution6{    
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> front(5, 0), cur(5, 0);
        
        // states
        for(int idx = n-1; idx >= 0; idx--){
            for(int trans = 0; trans < 4; trans++){
                // buy - even
                if(trans % 2 == 0){
                    cur[trans] = max(-prices[idx] + front[trans+1],
                              0 + front[trans]);
                }

                // sell - odd
                else{
                    cur[trans] = max(prices[idx] + front[trans+1],
                          0 + front[trans]);
                }
            }
            front = cur;
        }
        
        return front[0];
    }
};

int main(){
    return 0;
}