#include<iostream>
#include<vector>
// Striver SDE Sheet - Day1-Array-Part1
// Leetcode - 121. Best Time to Buy and Sell Stock

// BruteForce Approach
// TC - O(n^2)
// SC - O(1)
// Getting TLE
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        for (int i = 0; i <= n - 2; i++){
            for (int j = i + 1; j <= n - 1; j++){
                if(prices[j] > prices[i])
                    maxProfit = std::max(maxProfit, prices[j] - prices[i]);
            }
        }
        
        return maxProfit;
    }
};


// Optimized Approach
// TC - O(n)
// SC - O(1)
// ACCEPTED
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int minPrice = 1e9;
        for (int i = 0; i <= n - 1; i++){
            // Maintaining min price
            minPrice = std::min(minPrice, prices[i]);
            maxProfit = std::max(maxProfit, prices[i] - minPrice);
        }
        
        return maxProfit;
    }
};

// Just a Thought : If you want to reduce 2 nested loops to 1 single loop think of a 2 Pointer Approach

int main(){

    return 0;
}