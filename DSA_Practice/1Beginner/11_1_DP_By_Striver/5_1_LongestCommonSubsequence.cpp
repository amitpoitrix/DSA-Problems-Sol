#include<iostream>
#include<vector>
using namespace std;
// DP by Striver: Dp 25. Longest Common Subsequence | Top Down | Bottom-Up | Space Optimised | DP on Strings
// https://leetcode.com/problems/longest-common-subsequence/submissions/

// Memoization
// TC - O(n * m)
// SC - O(n * m) + O(n + m)
class Solution1{
private:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        // base case
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // Match
        if(s[i] == t[j])
            return dp[i][j] = 1 + f(i-1, j-1, s, t, dp);
        // Don't Match
        return dp[i][j] = 0 + max(f(i-1, j, s, t, dp), f(i, j-1, s, t, dp));
    }
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, text1, text2, dp);
    }
};

// Tabulation
// TC - O(n * m)
// SC - O(n * m)
class Solution2{    
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // Base Case
        // When i = 0
        for(int j=0; j <= m; j++){
            dp[0][j] = 0;
        }
        // When j = 0
        for(int i=0; i <= n; i++){
            dp[i][0] = 0;
        }

        for(int i=1; i <= n; i++){
            for(int j=1; j <= m; j++){
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][m];
    }
};

// Space Optimization over Tabulation
// TC - O(n * m)
// SC - O(m)
class Solution3{    
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m+1, 0), cur(m+1, 0);
        // Base Case
        // When i = 0
        for(int j=0; j <= m; j++){
            prev[j] = 0;
        }
        // When j = 0
        // for(int i=0; i <= n; i++){
        //     dp[i][0] = 0;
        // }

        for(int i=1; i <= n; i++){
            for(int j=1; j <= m; j++){
                if(text1[i-1] == text2[j-1])
                    cur[j] = 1 + prev[j-1];
                else
                    cur[j] = 0 + max(prev[j], cur[j-1]);
            }
            prev = cur;
        }

        return prev[m];
    }
};

int main(){
    return 0;
}