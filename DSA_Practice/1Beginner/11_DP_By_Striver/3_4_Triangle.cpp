#include<iostream>
#include<vector>
using namespace std;
// DP by Striver : DP 11. Triangle | Fixed Starting Point and Variable Ending Point | DP on GRIDS
// Here we have to calculate min path sum from 0th row to reach last row

// In last 3 lec we're doing problems related to fix starting & ending points now in this couple of 3 Lec we'll see 
// variable starting and ending points

// Using Recursion
// TC - O(2^(1 + 2 + 3 + .... + n)) ~ O(2^(n^2))
// SC - O(n) - Auxilliary Stack Space as we have to move just the no. of rows
class Solution{
private:
    int f(int i, int j, std::vector<std::vector<int>>& triangle, int n){
        // Base case - Destination or Result you wanna achieve
        // As 0th row has only 1 element as compare to last row which has (i+n) elements 
        // so we'll start recursion from (0,0) -> (n-1, m-1)
        if(i == n-1)
            return triangle[i][j];
        
        else{
            int d = triangle[i][j] + f(i+1, j, triangle, n);
            int dg = triangle[i][j] + f(i+1, j+1, triangle, n);
            
            return std::min(d, dg);
        }
    }

public:
    int minimumPathSum(std::vector<std::vector<int>>& triangle, int n){
        return f(0, 0, triangle, n);
    }
};


// As it has overlapping subproblems 
// Using DP - Memoization(Top-Down) - This will give TLE in Code Studio
// TC - O(n * n)
// SC - O(n * n) + O(n)
class Solution1{
private:
    int f(int i, int j, vector<vector<int>>& triangle, int n, vector<vector<int>>& dp){
        // Base Case - i reaches last row
        if(i == n-1) return triangle[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int d = triangle[i][j] + f(i+1, j, triangle, n, dp);
        int dg = triangle[i][j] + f(i+1, j+1, triangle, n, dp);
            
        return dp[i][j] = min(d, dg);
}

public:
    int minimumPathSum(vector<vector<int>>& triangle, int n){
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, 0, triangle, n, dp);
    }
};


// 2nd DP Method - Tabulation(Bottom-Up) - Its will always work in reverse order as compare to Memoization Method
// TC - O(n * n)
// SC - O(n * n)
class Solution2{
public:
    int minimumPathSum(vector<vector<int>>& triangle, int n){
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int j = 0; j < n; j++){
            dp[n-1][j] = triangle[n-1][j];
        }

        for (int i = n-2; i >= 0; i--){
            for (int j = i; j >= 0; j--){
                
                int d = triangle[i][j] + dp[i+1][j];
                int dg = triangle[i][j] + dp[i+1][j+1];
                
                dp[i][j] = min(d, dg);

            }
        }
        // Here the return statement of the Tabulation is the 
        // Passing parameters of Memoization Method
        return dp[0][0];
    }
};


class Solution3{
public:
    int minimumPathSum(vector<vector<int>>& triangle, int n){
        vector<int> front(n, 0);

        for (int j = 0; j < n; j++){
            front[j] = triangle[n-1][j];
        }

        for (int i = n-2; i >= 0; i--){
            vector<int> curr(n, 0);

            for (int j = i; j >= 0; j--){    
                int d = triangle[i][j] + front[j];
                int dg = triangle[i][j] + front[j+1];
                
                curr[j] = min(d, dg);
            }
            front = curr;
        }

        return front[0];
    }
};


int main(){

    return 0;
}