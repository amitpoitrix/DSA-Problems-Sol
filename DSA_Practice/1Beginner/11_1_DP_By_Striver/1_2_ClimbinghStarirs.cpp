#include<iostream>
#include<vector>
// DP by Striver : 70. Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/

// Same as Fibonacci Problem
// TC - O(n)
// SC - O(1)
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
            return n;

        int climb1 = 1;
        int climb2 = 2;
        int climb = 0; 
 
        for(int i = 3;i <= n;i++){
            climb = climb1 + climb2;
            climb1 = climb2;
            climb2 = climb;
        }
        
        return climb;
    }
};

// TC - O(n); faster than above Sol
// SC - O(n)
class Solution2{
public:
    int climbStairs(int n){
        if(n <= 2)
            return n;
        
        std::vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};

int main(){

    return 0;
}