#include<iostream>
#include<vector>
using namespace std;
// DP by Striver: DP 27. Longest Common Substring | DP on Strings

// Tabulation
// TC - O(n * m)
// SC - O(n * m)
class Solution1{    
public:
    int lcs(string &str1, string &str2){
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int j=0; j <= m; j++){
            dp[0][j] = 0;
        }
        for(int i=0; i <= n; i++){
            dp[i][0] = 0;
        }
        
        int ans = 0;

        for(int i=1; i <= n; i++){
            for(int j=1; j <= m; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }

        return ans;
    }
};

// Space Optimization over Tabulation
// TC - O(n * m)
// SC - O(m)
class Solution2{    
public:
    int lcs(string &str1, string &str2){
        int n = str1.size(), m = str2.size();
        vector<int> prev(m+1, 0), cur(m+1, 0);
        
        int ans = 0;
        for(int i=1; i <= n; i++){
            for(int j=1; j <= m; j++){
                if(str1[i-1] == str2[j-1]){
                    cur[j] = 1 + prev[j-1];
                    ans = max(ans, cur[j]);
                }
                else
                    cur[j] = 0;
            }
            prev = cur;
        }

        return ans;
    }
};

int main(){

}