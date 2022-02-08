#include<iostream>
#include<vector>
// DP By Striver : Fibonacci

// Approach 1 : Memoization(or Modified Recursive Approach) - TOP DOWN APPROACH
// TC - O(n)
// SC - O(n) + O(n); 1st O(n) is becoz of Auxillary Recursive Stack Space & 2nd O(n) is becoz of dp array 
class Solution{
public:
    int fibDP(int n, std::vector<int> &dp){
        if(n <= 1)
            return n;
        
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = fibDP(n-1, dp) + fibDP(n-2, dp);
    }
};

// Approach 2 : Tabulation Method - BOTTOM UP APPROACH
// TC - O(n)
// SC - O(n); space used for storing dp array
class Solution2{
public:
    int fibDP(int n, std::vector<int> &dp){
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }

    // Modified Space Complexity to O(1)
    int fibDP2(int n){
        int prev2 = 0;
        int prev1 = 1;

        for (int i = 2; i <= n; i++){
            int curri = prev1 + prev2;
            prev2 = prev1;
            prev1 = curri;
        }
        
        return prev1;
    }
};

int main(){
    int n;
    std::cin >> n;
    std::vector<int> dp(n+1, -1); // size (n+1) becoz of 0 based indexing

    Solution2 obj;
    std::cout << obj.fibDP(n, dp) << "\n";
    std::cout << obj.fibDP2(n);

    return 0;
}