#include<iostream>
#include<vector>
using namespace std;
// DP by Striver : DP 56. Count Square Submatrices with All Ones | DP on Rectangles
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

// Tabulation Method Only
// TC - O(n * m)
// SC - O(n * m)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // dp[][] of matrix size
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        int sum = 0;
        // Filling up 0th row
        for(int j=0; j < m; j++){
            dp[0][j] = matrix[0][j];
            sum += dp[0][j];
        }
        // Filling up 0th col
        for(int i=0; i < n; i++){
            dp[i][0] = matrix[i][0];
            sum += dp[i][0];
        }
        sum -= dp[0][0];    // As its being added 2 times
        
        // Now filling up the rest the dp matrix
        for(int i=1; i < n; i++){
            for(int j=1; j < m; j++){
                if(matrix[i][j] == 0)
                    dp[i][j] = 0;
                else{
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
                }
                sum += dp[i][j];
            }
        }
        
        return sum;
    }
};

int main(){
    return 0;
}