#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// DP by Striver: DP 50. Minimum Cost to Cut the Stick
// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

// Memoization
// TC - O(m^3)
// SC - O(m^2) + O(m)
class Solution {
private:
    int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
        // Base Case
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mini = 1e9;
        for(int idx = i; idx <= j; idx++){
            int cost = (cuts[j+1] - cuts[i-1])
                + f(i, idx-1, cuts, dp) + f(idx+1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
    
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int>> dp(m+1, vector<int> (m+1, -1));
        return f(1, m, cuts, dp);
    }
};

// Tabulation
// TC - O(m^3)
// SC - O(m^2) + O(m)
class Solution2{    
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int>> dp(m+2, vector<int> (m+2, 0));
        
        for(int i = m; i >= 1; i--){
            for(int j = 1; j <= m; j++){
                // Base Case
                if(i > j) continue;
                
                int mini = 1e9;
                for(int idx = i; idx <= j; idx++){
                    int cost = (cuts[j+1] - cuts[i-1])
                        + dp[i][idx-1] + dp[idx+1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        
        return dp[1][m];
    }
};

int main(){
    return 0;
}