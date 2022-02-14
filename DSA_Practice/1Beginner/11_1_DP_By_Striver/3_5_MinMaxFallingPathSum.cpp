#include<iostream>
#include<vector>
// DP by Striver : DP 12. Minimum/Maximum Falling Path Sum | Variable Starting and Ending Points | DP on Grids
// Here we are Calculation Max Path Sum from Variable Starting Point to Variable Ending Point

// Using Recursion
// TC - 3^n
// SC - O(n)
class Solution{
private:
    int f(int i, int j, std::vector<std::vector<int>> &matrix){
        // Base Case - When it moves out of bound
        if(j < 0 || j >= matrix[0].size())
            return -1e9;    // As we are calculation Max Path so returning smallest possible value
        
        // Base Case - When it reach Destination
        else if(i == 0)
            return matrix[i][j];
        
        else{
            int ldg = matrix[i][j] + f(i-1, j-1, matrix);
            int up = matrix[i][j] + f(i-1, j, matrix);
            int rdg = matrix[i][j] + f(i-1, j+1, matrix);

            return std::max(ldg, std::max(up, rdg));
        }
    }

public:
    int getMaxPathSum(std::vector<std::vector<int>> &matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        
        // As Starting & ending Point is Variable we'll start recursion from last row each variable
        int maxi = -1e9;
        for (int j = 0; j < m; j++){
            maxi = std::max(maxi, f(n-1, j, matrix));
        }
        
        return maxi;
    }
};


// Using DP - Memoization(Top-Down)
// TC - O(n * m)
// SC - O(n * m) + O(n)
class Solution1{
private:
    int f(int i, int j, std::vector<std::vector<int>> &matrix, std::vector<std::vector<int>> &dp){
        // Base Case - When it moves out of bound
        if(j < 0 || j >= matrix[0].size())
            return -1e9;    // As we are calculation Max Path so returning smallest possible value
        
        // Base Case - When it reach Destination
        else if(i == 0)
            return matrix[i][j];
        
        else if(dp[i][j] != -1)
            return dp[i][j];
        
        else{
            int ldg = matrix[i][j] + f(i-1, j-1, matrix, dp);
            int up = matrix[i][j] + f(i-1, j, matrix, dp);
            int rdg = matrix[i][j] + f(i-1, j+1, matrix, dp);

            return dp[i][j] = std::max(ldg, std::max(up, rdg));
        }
    }

public:
    int getMaxPathSum(std::vector<std::vector<int>> &matrix){
        int n = matrix.size();
        int m = matrix[0].size();

        std::vector<std::vector<int>> dp(n, std::vector<int>(m, -1));
        
        // As Starting & ending Point is Variable we'll start recursion from last row each variable
        int maxi = -1e9;
        for (int j = 0; j < m; j++){
            maxi = std::max(maxi, f(n-1, j, matrix, dp));
        }
        
        return maxi;
    }
};


// Using DP - Tabulation(Bottom-Up)
// TC - O(n * m) + O(m)
// SC - O(n * m)
class Solution2{
public:
    int getMaxPathSum(std::vector<std::vector<int>> &matrix){
        int n = matrix.size();
        int m = matrix[0].size();

        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
        // Base Case in Tabulation - Filling up the first row
        for (int j = 0; j < m; j++){
            dp[0][j] = matrix[0][j];
        }     
        
        for (int i = 1; i < n; i++){
            for (int j = 0; j < m; j++){
                int up = matrix[i][j] + dp[i-1][j];

                int ldg = matrix[i][j];
                if(j-1 >= 0)
                    ldg += dp[i-1][j-1];
                else
                    ldg += -1e9;

                int rdg = matrix[i][j]; 
                if(j+1 < m)
                    rdg += dp[i-1][j+1];
                else
                    rdg += -1e9;

                dp[i][j] = std::max(ldg, std::max(up, rdg));
            }
        }

        int maxi = -1e9;
        for (int j = 0; j < m; j++){
            maxi = std::max(maxi, dp[n-1][j]);
        }
        
        return maxi;
    }
};


// Space Optimization on Tabulation(Bottom-Up)
// TC - O(n * m) + O(m)
// SC - O(m)
class Solution3{
public:
    int getMaxPathSum(std::vector<std::vector<int>> &matrix){
        int n = matrix.size();
        int m = matrix[0].size();

        std::vector<int> prev(m, 0);
        // Base Case in Tabulation - Filling up the first row
        for (int j = 0; j < m; j++){
            prev[j] = matrix[0][j];
        }     
        
        for (int i = 1; i < n; i++){
            std::vector<int> curr(m, 0);

            for (int j = 0; j < m; j++){
                int up = matrix[i][j] + prev[j];

                int ldg = matrix[i][j];
                if(j-1 >= 0)
                    ldg += prev[j-1];
                else
                    ldg += -1e9;

                int rdg = matrix[i][j]; 
                if(j+1 < m)
                    rdg += prev[j+1];
                else
                    rdg += -1e9;

                curr[j] = std::max(ldg, std::max(up, rdg));
            }

            prev = curr;
        }

        int maxi = -1e9;
        for (int j = 0; j < m; j++){
            maxi = std::max(maxi, prev[j]);
        }
        
        return maxi;
    }
};


int main(){

    return 0;
}