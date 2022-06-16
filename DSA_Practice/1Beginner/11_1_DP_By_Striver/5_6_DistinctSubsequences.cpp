#include<iostream>
#include<vector>
using namespace std;
// DP by Striver: DP 32. Distinct Subsequences | 1D Array Optimisation Technique
// https://leetcode.com/problems/distinct-subsequences/

// Memoization
// TC - O(n * m)
// SC - O(n * m) + O(n + m)
class Solution {
private:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        // Base Case
        if(j < 0) return 1;
        if(i < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        // Match
        if(s[i] == t[j])
            return dp[i][j] = f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp);
        
        return dp[i][j] = f(i-1, j, s, t, dp);
    }
    
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, s, t, dp);
    }
};

// Tabulation
// TC - O(n * m)
// SC - O(n * m)
class Solution2 {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<double>> dp(n+1, vector<double>(m+1, 0));
        
        for(int i=0; i <= n; i++){
            dp[i][0] = 1;
        }
        
        for(int i=1; i <= n; i++){
            for(int j=1; j <= m; j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return (int)dp[n][m];
    }
};

// Space Optimization over Tabulation
// TC - O(n * m)
// SC - O(m) + O(m)
class Solution3 {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<double> prev(m+1, 0), cur(m+1, 0);
        
        prev[0] = cur[0] = 1;
        
        for(int i=1; i <= n; i++){
            for(int j=1; j <= m; j++){
                if(s[i-1] == t[j-1])
                    cur[j] = prev[j-1] + prev[j];
                else
                    cur[j] = prev[j];
            }
            prev = cur;
        }
        
        return (int)prev[m];
    }
};

// Single Array Space Optimization over Tabulation
// TC - O(n * m)
// SC - O(m)
class Solution4 {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<double> prev(m+1, 0);
        prev[0] = 1;
        
        for(int i=1; i <= n; i++){
            for(int j=m; j >= 1; j--){
                if(s[i-1] == t[j-1])
                    prev[j] = prev[j-1] + prev[j];
            }
        }
        
        return (int)prev[m];
    }
};

int main(){
    return 0;
}