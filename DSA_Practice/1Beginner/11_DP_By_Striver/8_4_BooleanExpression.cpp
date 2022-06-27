#include<iostream>
#include<vector>
using namespace std;
// DP by Striver: DP 52. Evaluate Boolean Expression to True | Partition DP

// Memoization
// TC - O(n * n * 2) * O(n) ~ O(n^3)
// SC - O(n^2 * 2) + O(n)
class Solution{
private:
    int mod = 1e9+7;

    long long f(int i, int j, int isTrue, string &exp, vector<vector<vector<int>>> &dp){
        // 1st Base Case
        if(i > j) return 0;
        // 2nd Base Case
        if(i == j){
            if(isTrue) 
                return exp[i] == 'T';
            else 
                return exp[i] == 'F';
        }
        
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        
        long long ways = 0;
        for(int idx = i+1; idx <= j-1; idx += 2){
            long long lT = f(i, idx-1, 1, exp, dp);
            long long lF = f(i, idx-1, 0, exp, dp);
            long long rT = f(idx+1, j, 1, exp, dp);
            long long rF = f(idx+1, j, 0, exp, dp);
            
            if(exp[idx] == '&'){
                if(isTrue)
                    ways = (ways + (lT * rT) % mod) % mod;
                else
                    ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod; 
            }
            
            else if(exp[idx] == '|'){
                if(isTrue)
                    ways = (ways + (lT * rF) % mod + (lF * rT) % mod + (lT * rT) % mod) % mod;
                else
                    ways = (ways + (lF * rF) % mod) % mod;
            }
            
            else{
                if(isTrue)
                    ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
                else
                    ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
            }
        }
        
        return dp[i][j][isTrue] = ways;
    }

public:
    int evaluateExp(string & exp) {
        int n = exp.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (2, -1))); 
        return f(0, n-1, 1, exp, dp);
    }
};

// Tabulation
// TC - O(n^3)
// SC - O(2 * n^2)
class Solution2{
private:
    int mod = 1e9+7;

public:
    int evaluateExp(string & exp) {
        int n = exp.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (2, 0)));
        
        for(int i=0; i < n; i++){
            if(exp[i] == 'T') 
                dp[i][i][1] = 1;
            else
                dp[i][i][0] = 1;
        }
        
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j <= n-1; j++){
                if(i > j) continue;
                
                long long ways = 0;
                for(int idx = i+1; idx <= j-1; idx += 2){
                    long long lT = dp[i][idx-1][1];
                    long long lF = dp[i][idx-1][0];
                    long long rT = dp[idx+1][j][1];
                    long long rF = dp[idx+1][j][0];

                    if(exp[idx] == '&'){
                        dp[i][j][1] = (dp[i][j][1] + (lT * rT) % mod) % mod;
                        dp[i][j][0] = (dp[i][j][0] + (lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod; 
                    }

                    else if(exp[idx] == '|'){
                        dp[i][j][1] = (dp[i][j][1] + (lT * rF) % mod + (lF * rT) % mod + (lT * rT) % mod) % mod;
                        dp[i][j][0] = (dp[i][j][0] + (lF * rF) % mod) % mod;
                    }

                    else{
                        dp[i][j][1] = (dp[i][j][1] + (lT * rF) % mod + (lF * rT) % mod) % mod;
                        dp[i][j][0] = (dp[i][j][0] + (lT * rT) % mod + (lF * rF) % mod) % mod;
                    }
                }
            } 
        }
        
        return dp[0][n-1][1];
    }
};

int main(){
    return 0;
}