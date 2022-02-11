#include<iostream>
#include<vector>
// DP by Striver : DP 9. Unique Paths 2 | DP on Grid with Maze Obstacles
// Same as Lecture 8 with slight modification i.e., obstacles are there in the path

// Using Recursion - Give TLE in CodeStudio
// TC - 2^(m*n)
// SC - O(path Length) ~ O((m-1) + (n-1))
class Solution{
private:
    int f(int i, int j, std::vector< std::vector< int> > &mat){
        if(i >= 0 && j >= 0 && mat[i][j] == -1)
            return 0;

        else if(i == 0 && j == 0)
            return 1;
        
        else if(i < 0 || j < 0)
            return 0;
        
        else{
            int up = f(i-1, j, mat);
            int left = f(i, j-1, mat);
            return up + left;
        }
    }

public:
    int mazeObstacles(int n, int m, std::vector< std::vector< int> > &mat) {
        return f(n - 1, m - 1, mat);
    }
};

// Better Approach
// Using DP - Memoization(Top-Down) - Give TLE in CodeStudio but not in Leetcode
// TC - O(n * m)
// SC - O((m-1) + (n-1)) + O(n * m)
class Solution1{
private:
    int mod = (1e9 + 7);    // becoz of CodeStudio not in Leetcode

    int f(int i, int j,std::vector<std::vector<int>> &mat ,std::vector<std::vector<int>> &dp){
        if(i >= 0 && j >= 0 && mat[i][j] == -1)
            return 0;

        else if(i == 0 && j == 0)
            return 1;
        
        else if(i < 0 || j < 0)
            return 0;
        
        else if(dp[i][j] != -1)
            return dp[i][j];
        
        else{
            int up = f(i-1, j, mat, dp);
            int left = f(i, j-1, mat, dp);
            return dp[i][j] = (up + left) % mod;
        }
    }

public:
    int mazeObstacles(int n, int m, std::vector< std::vector< int> > &mat) {
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, -1));
        return f(n - 1, m - 1, mat, dp);
    }
};


// Using DP - Tabulation(Bottom-Up) - No TLE
// TC - O(n * m)
// SC - O(n * m)
class Solution2{
private:
    int mod = 1e9 + 7;

public:
    int mazeObstacles(int n, int m, std::vector< std::vector< int> > &mat) {
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
        dp[0][0] = 1;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(mat[i][j] == -1)
                    dp[i][j] = 0;
                
                else if(i == 0 && j == 0)
                    dp[i][j] = 1;
                
                else{
                    int up = 0;
                    int left = 0;

                    if(i > 0)
                        up = dp[i-1][j];
                    if(j > 0)
                        left = dp[i][j-1];

                    dp[i][j] = (up + left) % mod;
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};


// Space Optimization on Tabulation(Bottom-Up) - Give TLE in CodeStudio but not in Leetcode
// TC - O(n * m)
// SC - O(n)
class Solution3{
private:
    int mod = 1e9 + 7;

public:
    int mazeObstacles(int n, int m, std::vector< std::vector< int> > &mat) {
        std::vector<int> prev(m, 0);

        for (int i = 0; i < n; i++){
            std::vector<int> curr(m, 0);

            for (int j = 0; j < m; j++){
                if(mat[i][j] == -1)
                    curr[j] = 0;
                
                else if(i == 0 && j == 0)
                    curr[j] = 1;
                
                else{
                    int up = 0;
                    int left = 0;

                    if(i > 0)
                        up = prev[j];
                    if(j > 0)
                        left = curr[j-1];

                    curr[j] = (up + left) % mod;
                }
            }

            prev = curr;
        }
        
        return prev[m-1];
    }
};

int main(){

    return 0;
}