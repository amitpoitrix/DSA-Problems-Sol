#include<iostream>
#include<vector>
using namespace std;
// DP by Striver: DP 33. Edit Distance | Recursive to 1D Array Optimised Solution
// https://leetcode.com/problems/edit-distance/

// Memoization
// TC - O(n * m)
// SC - O(n * m) + O(n + m)
class Solution {
private:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        // base case
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j])
            return dp[i][j] = f(i-1, j-1, s1, s2, dp);
        
        return dp[i][j] = 1 + min(f(i, j-1, s1, s2, dp), min(f(i-1, j, s1, s2, dp), f(i-1, j-1, s1, s2, dp)));
    }
    
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, word1, word2, dp);
    }
};

// Tabulation
// TC - O(n * m)
// SC - O(n * m)
class Solution2{    
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // 1st Base Case: When i==0 return j
        for(int j=0; j <= m; j++){
            dp[0][j] = j;
        }
        // 2nd Base Case: When j==0 return i
        for(int i=0; i <= n; i++){
            dp[i][0] = i;
        }
        
        for(int i=1; i <= n; i++){
            for(int j=1; j <= m; j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
        
        return dp[n][m];
    }
};

// Space Optimization
// TC - O(n * m)
// SC - O(m) + O(m)
class Solution3{    
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> prev(m+1, 0), cur(m+1, 0);
        // 1st Base Case: When i==0 return j
        for(int j=0; j <= m; j++){
            prev[j] = j;
        }
        
        for(int i=1; i <= n; i++){
            // 2nd Base Case: When j==0 return i
            cur[0] = i;
            for(int j=1; j <= m; j++){
                if(word1[i-1] == word2[j-1])
                    cur[j] = prev[j-1];
                else
                    cur[j] = 1 + min(cur[j-1], min(prev[j], prev[j-1]));
            }
            prev = cur;
        }
        
        return prev[m];
    }
};

int main(){
    return 0;
}