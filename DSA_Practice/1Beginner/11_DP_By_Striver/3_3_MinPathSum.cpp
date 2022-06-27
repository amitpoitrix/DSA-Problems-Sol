#include<iostream>
#include<vector>
using namespace std;
// DP by Striver : DP 10. Minimum Path Sum in Grid | DP on GRIDS

// Using Recursion
class Solution{
private:
    int f(int i, int j, vector<vector<int>> &grid){
        if(i == 0 && j == 0) return grid[i][j];
        if(i < 0 || j < 0) return 1e9;
        
        int up = grid[i][j] + f(i-1, j, grid);
        int left = grid[i][j] + f(i, j-1, grid);
        return min(up, left);
    }

public:
    int minSumPath(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size(); 
        return f(n-1, m-1, grid);
    }
};


// Using DP - Memoization(Top-Down)
// TC - O(n * m)
// SC - O(n * m) + O((n-1) + (m-1))
class Solution1{
private:
    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return dp[i][j] = grid[i][j]; 
        if(i < 0 || j < 0) return 1e9;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = grid[i][j] + f(i-1, j, grid, dp);
        int left = grid[i][j] + f(i, j-1, grid, dp);

        return dp[i][j] = min(up, left);
    }

public:
    int minSumPath(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, grid, dp);
    }
};


// Using DP - Tabulation(Bottom-Up)
// TC - O(n * m)
// SC - O(n * m)
class Solution2{
public:
    int minSumPath(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                
                else{
                    int up = grid[i][j];
                    if(i > 0) up += dp[i-1][j];
                    else up += 1e9;
                    
                    int left = grid[i][j];
                    if(j > 0) left += dp[i][j-1];
                    else left += 1e9;
                    
                    dp[i][j] = min(up, left);
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};


// Space Optimization on Tabulation(Bottom-Up)
// TC - O(n * m)
// SC - O(m)
class Solution3{
public:
    int minSumPath(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> prev(m, 0);
        
        for (int i = 0; i < n; i++){
            vector<int> curr(m, 0);

            for (int j = 0; j < m; j++){
                if(i == 0 && j == 0)
                    curr[j] = grid[i][j];
                
                else{
                    int up = grid[i][j];
                    if(i > 0) up += prev[j];
                    else up += 1e9;
                    
                    int left = grid[i][j];
                    if(j > 0) left += curr[j-1];
                    else left += 1e9;
                    
                    curr[j] = min(up, left);
                }
            }
            prev = curr;
        }
          
        return prev[m-1];
    }
};


int main(){
    std::vector<std::vector<int>> grid = {{5,9,6}, {11,5,2}};

    Solution3 obj;
    std::cout << obj.minSumPath(grid);

    return 0;
}