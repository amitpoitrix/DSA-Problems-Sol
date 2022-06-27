#include<iostream>
#include<vector>
using namespace std;
// DP by Striver: DP 38. Buy and Stock Sell IV | Recursion to Space Optimisation

// 1st Solution - Using dp[n+1][2][k+1]
// Tabulation Method of Buy And Sell Stock III
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1, 0)));
        
        // No need to handle base case as everything is already been assign to 0
        
        for(int idx = n-1; idx >= 0; idx--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= k; cap++){
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
        
        return dp[0][1][k];
    }
};

// 2nd Solution using - dp[n][2k]
// Memoization
// TC - O(n * 2k)
// SC - O(n * 2k) + O(n)
class Solution1{
private:
    int f(int idx, int trans, vector<int> &prices, int k, vector<vector<int>> &dp){
        // base case
        if(idx == prices.size() || trans == 2*k) return 0;
        
        if(dp[idx][trans] != -1) return dp[idx][trans];
        
        // Buy - Even
        if(trans % 2 == 0)
            return dp[idx][trans] = max(-prices[idx] + f(idx+1, trans+1, prices, k, dp),
                      0 + f(idx+1, trans, prices, k, dp));
        
        // Sell - odd
        return dp[idx][trans] = max(prices[idx] + f(idx+1, trans+1, prices, k, dp),
                  0 + f(idx+1, trans, prices, k, dp));
    }
    
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2*k, -1));
        return f(0, 0, prices, k, dp);
    }
};

// Tabulation
// TC - O(n * 2k)
// SC - O(n * 2k)
class Solution2{    
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2*k+1, 0));
        
        for(int idx = n-1; idx >= 0; idx--){
            for(int trans = 0; trans < 2*k; trans++){
                // buy - even
                if(trans % 2 == 0){
                    dp[idx][trans] = max(-prices[idx] + dp[idx+1][trans+1],
                              0 + dp[idx+1][trans]);
                }

                // Sell - odd
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
// TC - O(n * 2k)
// SC - O(2k) + O(2k)
class Solution3{    
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> front(2*k+1, 0), cur(2*k+1, 0);
        
        for(int idx = n-1; idx >= 0; idx--){
            for(int trans = 0; trans < 2*k; trans++){
                // buy - even
                if(trans % 2 == 0){
                    cur[trans] = max(-prices[idx] + front[trans+1],
                              0 + front[trans]);
                }

                // Sell - odd
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