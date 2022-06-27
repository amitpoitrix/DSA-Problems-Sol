#include<iostream>
#include<vector>
using namespace std;
// DP by Striver: DP 34. Wildcard Matching | Recursive to 1D Array Optimisation 
// https://leetcode.com/problems/wildcard-matching/

// Memoization
// TC - O(n * m)
// SC - O(n * m) + O(n + m)
class Solution {
private:
    bool f(int i, int j, string &p, string &s, vector<vector<int>> &dp){
        // Base Case
        // 1. When both p & s got exhausted
        if(i < 0 && j < 0) return true;
        // 2. When only p got exhausted
        if(i < 0 && j >= 0) return false;
        // 3. When only s got exhausted
        if(i >= 0 && j < 0){
            // Now p should have '*' to match empty string else return false
            for(int k=0; k <= i; k++){
                if(p[k] != '*')
                    return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        // Match
        if(p[i] == s[j] || p[i] == '?')
            return dp[i][j] = f(i-1, j-1, p, s, dp);
        
        if(p[i] == '*')
            return dp[i][j] = f(i-1, j, p, s, dp) | f(i, j-1, p, s, dp);
        
        // Not Match
        return dp[i][j] = false;
    }
    
public:
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, p, s, dp);
    }
};

// Tabulation
// TC - O(n * m)
// SC - O(n * m)
class Solution2{    
public:
    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        // 1st Base Case
        dp[0][0] = true;
        // 2nd Base Case
        for(int j = 1; j <= m; j++){
            dp[0][j] = false;
        }
        // 3rd Base Case
        for(int i=1; i <= n; i++){
            bool flag = true;
            for(int k=1; k <= i; k++){
                if(p[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }
        
        // states
        for(int i=1; i <= n; i++){
            for(int j=1; j <= m; j++){
                // Match
                if(p[i-1] == s[j-1] || p[i-1] == '?')
                    dp[i][j] = dp[i-1][j-1];

                else if(p[i-1] == '*')
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];

                // Not Match
                else
                    dp[i][j] = false;
            }
        }
        
        return dp[n][m];
    }
};

// Space Optimization
// TC - O(n * m)
// SC - O(m) + O(m)
class Solution {    
public:
    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        vector<bool> prev(m+1, 0), cur(m+1, 0);
        // 1st Base Case
        prev[0] = true;
        // 2nd Base Case
        for(int j = 1; j <= m; j++){
            prev[j] = false;
        }
        
        // states
        for(int i=1; i <= n; i++){
            // 3rd Base Case: Every time 0th column of each row has to be initialised
            bool flag = true;
            for(int k=1; k <= i; k++){
                if(p[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            cur[0] = flag;
            
            for(int j=1; j <= m; j++){
                // Match
                if(p[i-1] == s[j-1] || p[i-1] == '?')
                    cur[j] = prev[j-1];

                else if(p[i-1] == '*')
                    cur[j] = prev[j] | cur[j-1];

                // Not Match
                else
                    cur[j] = false;
            }
            prev = cur;
        }
        
        return prev[m];
    }
};

int main(){
    return 0;
}