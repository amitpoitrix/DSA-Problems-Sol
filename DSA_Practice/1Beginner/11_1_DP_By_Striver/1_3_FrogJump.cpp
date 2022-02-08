#include<iostream>
#include<vector>
#include<limits.h>
// DP by Striver : DP 3. Frog Jump
// Frog can jump from i -> i+1 or i+2 & we have to find min energy require by from to go from 0 to n-1

// Using Recursion 
// This will cause TLE in last 2 test cases
class Solution{
private:
    int recursiveFrogJump(int idx, std::vector<int> &heights){
        if(idx == 0)
            return 0;
        
        int left = recursiveFrogJump(idx - 1, heights) + abs(heights[idx] - heights[idx - 1]);
        int right = INT_MAX;
        if(idx > 1)
            right = recursiveFrogJump(idx - 2, heights) + abs(heights[idx] - heights[idx - 2]);
        
        return std::min(left, right);
    }

public:
    int frogJump(int n, std::vector<int> &heights){
        return recursiveFrogJump(n - 1, heights);   // Here we'll pass n-1 i.e., last element index 
    }
};


// Using DP
// 1st Method: Memoization(Top-Down)
// TC - O(n)
// SC - O(n) + O(n)
class Solution1{
private:
    int recursiveFrogJump(int idx, std::vector<int> &heights, std::vector<int> &dp){
        if(idx == 0)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];

        int left = recursiveFrogJump(idx - 1, heights, dp) + abs(heights[idx] - heights[idx - 1]);
        int right = INT_MAX;
        if(idx > 1)
            right = recursiveFrogJump(idx - 2, heights, dp) + abs(heights[idx] - heights[idx - 2]);
        
        return dp[idx] = std::min(left, right);
    }

public:
    int frogJump(int n, std::vector<int> &heights){
        std::vector<int> dp(n+1, -1);   // Here we're taking space as n+1 for storing dp[n] value as we are dealing with 0 based indexing
        return recursiveFrogJump(n - 1, heights, dp);   // Here we'll pass n-1 i.e., last element index 
    }
};


// 2nd Method: Tabulation(Bottom - Up)
// TC - O(n)
// SC - O(n)
class Solution2{
public:
    int frogJump(int n, std::vector<int> &heights){
        std::vector<int> dp(n, -1);
        dp[0] = 0;

        for (int i = 1; i < n; i++){
            int left = dp[i-1] + abs(heights[i] - heights[i-1]);
            int right = INT_MAX;
            if(i > 1)
                right = dp[i-2] + abs(heights[i] - heights[i-2]);
            
            dp[i] = std::min(left, right);
        }
        
        return dp[n-1];  
    }
};

// Space Optimization in Tabulation Method 
// TC - O(n)
// SC - O(1)
class Solution3{
public:
    int frogJump(int n, std::vector<int> &heights){
        int prev1 = 0;
        int prev2 = 0;

        for (int i = 1; i < n; i++){
            int left = prev1 + abs(heights[i] - heights[i-1]);
            int right = INT_MAX;
            if(i > 1)
                right = prev2 + abs(heights[i] - heights[i-2]);
            
            int cur = std::min(left, right);
            prev2 = prev1;
            prev1 = cur;
        }
        
        return prev1;   // As when i reaches n loop will break & last value will be held at prev1  
    }
};


int main(){
    std::vector<int> heights = {10,20,30,10};
    int n = heights.size();

    Solution3 obj;
    std::cout << obj.frogJump(n, heights);

    return 0;
}