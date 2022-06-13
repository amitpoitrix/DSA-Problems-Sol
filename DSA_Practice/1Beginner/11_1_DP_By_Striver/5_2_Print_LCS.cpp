#include<iostream>
#include<vector>
using namespace std;
// DP by Striver: DP 26. Print Longest Common Subsequence | Dp on Strings

class Solution2{    
public:
    string printLCS(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int j=0; j <= m; j++){
            dp[0][j] = 0;
        }
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

        // Printing LCS
        int len = dp[n][m];
        string s = "";
        for(int i=0; i < len; i++){
            s += "$";
        }

        int idx = len - 1, i = n, j = m;
        while(i > 0 && j > 0){
            if(text1[i-1] == text2[j-1]){
                s[idx] = text1[i-1];
                idx--;
                i--;
                j--;
            }

            else if(dp[i-1][j] > dp[i][j-1])
                i--;
            
            else
                j--;
        }

        return s;
    }
};

int main(){
    string text1 = "abcde";
    string text2 = "bdgek";

    Solution2 obj;
    cout << obj.printLCS(text1, text2);

    return 0;
}