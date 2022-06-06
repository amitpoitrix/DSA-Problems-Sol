#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
// DP by Striver : DP 3. Frog Jump
// Frog can jump from i -> i+1 or i+2 & we have to find min energy require by from to go from 0 to n-1

// Using Recursion 
// This will cause TLE in last 2 test cases
class Solution{
private:
    int recursiveFrogJump(int idx, vector<int> &heights){
        if(idx == 0)
            return 0;
        
        int left = recursiveFrogJump(idx - 1, heights) + abs(heights[idx] - heights[idx - 1]);
        int right = INT_MAX;    // when idx is 0 or 1
        if(idx > 1)
            right = recursiveFrogJump(idx - 2, heights) + abs(heights[idx] - heights[idx - 2]);
        
        return min(left, right);
    }

public:
    int frogJump(int n, vector<int> &heights){
        // As frog jumps from 1 to N so there is for 0 based last stair will be at (N-1)
        return recursiveFrogJump(n - 1, heights);
    }
};


// Using DP
// 1st Method: Memoization(Top-Down)
// TC - O(n)
// SC - O(n) + O(n)
class Solution1{
private:
    int recursiveFrogJump(int idx, vector<int> &heights, vector<int> &dp){
        if(idx == 0)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];

        int left = recursiveFrogJump(idx - 1, heights, dp) + abs(heights[idx] - heights[idx - 1]);
        int right = INT_MAX;
        if(idx > 1)
            right = recursiveFrogJump(idx - 2, heights, dp) + abs(heights[idx] - heights[idx - 2]);
        
        return dp[idx] = min(left, right);
    }

public:
    int frogJump(int n, vector<int> &heights){
        // Creating dp of size [n+1] for storing value of dp[n] generally
        vector<int> dp(n+1, -1);
        // As frog jumps from 1 to N so there is for 0 based last stair will be at (N-1)
        return recursiveFrogJump(n - 1, heights, dp);
    }
};


// 2nd Method: Tabulation(Bottom - Up)
// TC - O(n)
// SC - O(n)
class Solution2{
public:
    int frogJump(int n, vector<int> &heights){
        vector<int> dp(n, -1);
        dp[0] = 0;

        for (int i = 1; i < n; i++){
            int left = dp[i-1] + abs(heights[i] - heights[i-1]);
            int right = INT_MAX;
            if(i > 1)
                right = dp[i-2] + abs(heights[i] - heights[i-2]);
            
            dp[i] = min(left, right);
        }
        
        return dp[n-1];  
    }
};

// Space Optimization in Tabulation Method 
// TC - O(n)
// SC - O(1)
class Solution3{
public:
    int frogJump(int n, vector<int> &heights){
        int prev1 = 0;
        int prev2 = 0;

        for (int i = 1; i < n; i++){
            int left = prev1 + abs(heights[i] - heights[i-1]);
            int right = INT_MAX;
            if(i > 1)
                right = prev2 + abs(heights[i] - heights[i-2]);
            
            int cur = min(left, right);
            prev2 = prev1;
            prev1 = cur;
        }
        // As when i reaches n loop will break & last value will be held at prev1 or cur
        return prev1;   
    }
};


int main(){
    vector<int> heights = {10,20,30,10};
    int n = heights.size();

    Solution3 obj;
    cout << obj.frogJump(n, heights);

    return 0;
}