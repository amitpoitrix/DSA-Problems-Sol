#include<iostream>
#include<vector>
using namespace std;
// DP by Striver : DP 12. Minimum/Maximum Falling Path Sum | Variable Starting and Ending Points | DP on Grids
// Here we are Calculation Max Path Sum from Variable Starting Point to Variable Ending Point

// Using Recursion
// TC - 3^n
// SC - O(n)
class Solution{
private:
    int f(int i, int j, vector<vector<int>> &matrix){
        // 1st Base Case - When it moves out of bound
        if(j < 0 || j >= matrix[0].size()) return -1e9;
        
        // 2nd Base Case - When it reach Destination
        if(i == 0) return matrix[i][j];
        
        int ldg = matrix[i][j] + f(i-1, j-1, matrix);
        int up = matrix[i][j] + f(i-1, j, matrix);
        int rdg = matrix[i][j] + f(i-1, j+1, matrix);

        return max(ldg, std::max(up, rdg));
    }

public:
    int getMaxPathSum(vector<vector<int>> &matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        
        // As Starting & ending Point is variable so we'll call recursion 
        // for each element of last row 
        int maxi = -1e9;
        for (int j = 0; j < m; j++){
            maxi = max(maxi, f(n-1, j, matrix));
        }
        
        return maxi;
    }
};


// Using DP - Memoization(Top-Down)
// TC - O(n * m)
// SC - O(n * m) + O(n)
class Solution1{
private:
    int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        // 1st Base Case - When it moves out of bound
        if(j < 0 || j >= matrix[0].size()) return -1e9;
        // 2nd Base Case - When it reach Destination
        if(i == 0) return matrix[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ldg = matrix[i][j] + f(i-1, j-1, matrix, dp);
        int up = matrix[i][j] + f(i-1, j, matrix, dp);
        int rdg = matrix[i][j] + f(i-1, j+1, matrix, dp);

        return dp[i][j] = max(ldg, max(up, rdg));
    }

public:
    int getMaxPathSum(vector<vector<int>> &matrix){
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        // As Starting & ending Point is variable so we'll call recursion 
        // for each element of last row 
        int maxi = -1e9;
        for (int j = 0; j < m; j++){
            maxi = max(maxi, f(n-1, j, matrix, dp));
        }
        
        return maxi;
    }
};


// Using DP - Tabulation(Bottom-Up)
// TC - O(n * m) + O(m)
// SC - O(n * m)
class Solution2{
public:
    int getMaxPathSum(vector<vector<int>> &matrix){
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        // Base Case in Tabulation - Filling up the first row
        for (int j = 0; j < m; j++){
            dp[0][j] = matrix[0][j];
        }     
        
        for (int i = 1; i < n; i++){
            for (int j = 0; j < m; j++){
                int up = matrix[i][j] + dp[i-1][j];

                int ldg = matrix[i][j];
                if(j-1 >= 0) ldg += dp[i-1][j-1];
                else ldg += -1e9;

                int rdg = matrix[i][j]; 
                if(j+1 < m) rdg += dp[i-1][j+1];
                else rdg += -1e9;

                dp[i][j] = max(ldg, max(up, rdg));
            }
        }

        // Tabulation way of handling multiple recursive calls in memoization
        int maxi = -1e9;
        for (int j = 0; j < m; j++){
            maxi = max(maxi, dp[n-1][j]);
        }
        
        return maxi;
    }
};


// Space Optimization on Tabulation(Bottom-Up)
// TC - O(n * m) + O(m)
// SC - O(m)
class Solution3{
public:
    int getMaxPathSum(vector<vector<int>> &matrix){
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> prev(m, 0);
        // Base Case in Tabulation - Filling up the first row
        for (int j = 0; j < m; j++){
            prev[j] = matrix[0][j];
        }     
        
        for (int i = 1; i < n; i++){
            vector<int> curr(m, 0);

            for (int j = 0; j < m; j++){
                int up = matrix[i][j] + prev[j];

                int ldg = matrix[i][j];
                if(j-1 >= 0) ldg += prev[j-1];
                else ldg += -1e9;

                int rdg = matrix[i][j]; 
                if(j+1 < m) rdg += prev[j+1];
                else rdg += -1e9;

                curr[j] = max(ldg, max(up, rdg));
            }

            prev = curr;
        }

        int maxi = -1e9;
        for (int j = 0; j < m; j++){
            maxi = max(maxi, prev[j]);
        }
        
        return maxi;
    }
};


int main(){

    return 0;
}