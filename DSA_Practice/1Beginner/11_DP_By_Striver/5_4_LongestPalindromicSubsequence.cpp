#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// DP by Striver: DP 28. Longest Palindromic Subsequence

// Tabulation
// TC - O(n * m)
// SC - O(n * m)
class Solution1{    
private:
    int longestCommonSubsequence(string &str1, string &str2){
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int j=0; j <= m; j++){
            dp[0][j] = 0;
        }
        for(int i=0; i <= n; i++){
            dp[i][0] = 0;
        }

        for(int i=1; i <= n; i++){
            for(int j=1; j <= m; j++){
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][m];
    }

public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return longestCommonSubsequence(s, t);
    }
};


// Space Optimization over Tabulation
// TC - O(n * m)
// SC - O(m)
class Solution2{
private:
    int longestCommonSubsequence(string &str1, string &str2){
        int n = str1.size(), m = str2.size();
        vector<int> prev(m+1, 0), cur(m+1, 0);
        for(int j=0; j <= m; j++){
            prev[j] = 0;
        }

        for(int i=1; i <= n; i++){
            for(int j=1; j <= m; j++){
                if(str1[i-1] == str2[j-1])
                    cur[j] = 1 + prev[j-1];
                else
                    cur[j] = 0 + max(prev[j], cur[j-1]);
            }
            prev = cur;
        }

        return prev[m];
    }
    
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return longestCommonSubsequence(s, t);
    }
};

int main(){
    return 0;
}