#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// DP by Striver: DP 31. Shortest Common Supersequence | DP on Strings
// https://leetcode.com/problems/shortest-common-supersequence/

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
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

        // Getting Shortest Common Supersequence
        string ans = "";
        int i=n, j=m;
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--, j--;
            }

            else if(dp[i-1][j] > dp[i][j-1]){
                ans += str1[i-1];
                i--;
            }

            else{
                ans += str2[j-1];
                j--;
            }
        }

        // If any of the strings remaining
        // If s1 remains
        while(i > 0){
            ans += str1[i-1];
            i--;
        }

        // If s2 remains
        while(j > 0){
            ans += str2[j-1];
            j--;
        }

        // reversing the string
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main(){
    return 0;
}
