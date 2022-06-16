#include<iostream>
#include<vector>
using namespace std;
// DP by Striver: DP 35. Best Time to Buy and Sell Stock | DP on Stocks
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        for(int i=1; i < prices.size(); i++){
            int cost = prices[i] - buy;
            profit = max(profit, cost);
            buy = min(buy, prices[i]);
        }
        
        return profit;
    }
};

int main(){
    return 0;
}