#include<iostream>
#include<vector>
// DP by Striver : DP 8. Grid Unique Paths | DP on Grids |
// DP 2nd Pattern : DP on Grids

// Using Recursion - Give TLE in CodeStudio
// TC - 2^(m*n)
// SC - O(path Length) ~ O((m-1) + (n-1))
class Solution{
private:
    int f(int i, int j){
        if(i == 0 && j == 0)
            return 1;
        
        else if(i < 0 || j < 0)
            return 0;
        
        else{
            int up = f(i-1, j);
            int left = f(i, j-1);
            return up + left;
        }
    }

public:
    int uniquePaths(int m, int n) {
        return f(m-1, n-1);
    }
};

// Better Approach
// Using DP - Memoization(Top-Down) - Give TLE in CodeStudio but not in Leetcode
// TC - O(n * m)
// SC - O((m-1) + (n-1)) + O(n * m)
class Solution1{
private:
    int f(int i, int j, std::vector<std::vector<int>> &dp){
        if(i == 0 && j == 0)
            return 1;
        
        else if(i < 0 || j < 0)
            return 0;
        
        else if(dp[i][j] != -1)
            return dp[i][j];
        
        else{
            int up = f(i-1, j, dp);
            int left = f(i, j-1, dp);
            return dp[i][j] = up + left;
        }
    }

public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, -1));
        return f(m-1, n-1, dp);
    }
};


// Using DP - Tabulation(Bottom-Up) - Give TLE in CodeStudio but not in Leetcode
// TC - O(n * m)
// SC - O(n * m)
class Solution2{
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                
                if(i == 0 && j == 0)
                    dp[i][j] = 1;
                
                else{
                    int up = 0;
                    int left = 0;

                    if(i > 0)
                        up = dp[i-1][j];
                    if(j > 0)
                        left = dp[i][j-1];

                    dp[i][j] = up + left;
                }

            }
        }
        
        return dp[m-1][n-1];
    }
};


// Space Optimization on Tabulation(Bottom-Up) - Give TLE in CodeStudio but not in Leetcode
// TC - O(n * m)
// SC - O(n)
class Solution3{
public:
    int uniquePaths(int m, int n) {
        std::vector<int> prev(n, 0);

        for (int i = 0; i < m; i++){
            std::vector<int> curr(n, 0);

            for (int j = 0; j < n; j++){
                
                if(i == 0 && j == 0)
                    curr[j] = 1;
                
                else{
                    int up = 0;
                    int left = 0;

                    if(i > 0)
                        up = prev[j];
                    if(j > 0)
                        left = curr[j-1];

                    curr[j] = up + left;
                }

            }

            prev = curr;
        }
        
        return prev[n-1];
    }
};


// Most Optimized Approach - Grid Unique Paths | GOOGLE interview question | Brute-Better-Optimal
// https://www.youtube.com/watch?v=t_f0nwwdg5o&ab_channel=takeUforward
// Using Combinatorial Solution
// TC - O(m-1) or O(n-1)
// SC - O(1)
class Solution4{
public:
    int uniquePaths(int m, int n) {
        int N = m + n -2;
        int R = m - 1;
        double res = 1;

        for (int i = 1; i <= R; i++){
            res = res * (N - R + i) / i;
        }
        
        return (int)res;
    } 
};


int main(){
    Solution3 obj;
    std::cout << obj.uniquePaths(3,2);

    return 0;
}