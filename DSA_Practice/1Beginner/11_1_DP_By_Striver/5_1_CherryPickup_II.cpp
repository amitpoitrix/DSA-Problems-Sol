#include<iostream>
#include<vector>
// DP by Striver : DP 13. Cherry Pickup II | 3D DP Made Easy | DP On Grids
// 3D DP on Grid - Fixed Starting Point & Variable Ending Point

// Using Recursion - from first row to last row
// TC - O(3^n * 3^n) ~ O(3^(2n))
// SC - O(n) ~ Auxilliary Stack Space
class Solution{
private:
    // There will be 3 states i(common for both), j1, j2
    int f(int i, int j1, int j2, std::vector<std::vector<int>> &grid){
        // Base Case - Out of Bound Case
        if(j1 < 0 || j2 < 0 || j1 >= grid[0].size() || j2 >= grid[0].size()){
            return -1e8;    // As Max is Asked & also using -1e8 instead of INT_MIN as INT_MIN might reach beyond the capacity of int
        }
        
        // Base Case - Destination
        else if(i == grid.size()-1){
            if(j1 == j2)
                return grid[i][j1]; // or grid[i][j2]
            else
                return grid[i][j1] + grid[i][j2];
        }

        else{
            // As further choosing each chocolate for Alice, Bob can choose from 3 options so total 9 combos will be there
            int maxi = 0;
            for (int dj1 = -1; dj1 <= 1; dj1++){
                for (int dj2 = -1; dj2 <= 1; dj2++){
                    if(j1 == j2)
                        maxi = std::max(maxi, grid[i][j1] + f(i+1, j1 + dj1, j2 + dj2, grid));
                    else
                        maxi = std::max(maxi, grid[i][j1] + grid[i][j2] + f(i+1, j1 + dj1, j2 + dj2, grid));
                } 
            }
            
            return maxi;
        }
    }

public:
    int maximumChocolates(int r, int c, std::vector<std::vector<int>> &grid) {
        return f(0, 0, c-1, grid);
    }
};


// As problems on Grid do have overlapping subproblems
// Using DP - Memoization(Top-Down)
// TC - O(n * m * m) * 9
// SC - O(n * m * m) + O(n)
class Solution1{
private:
    int f(int i, int j1, int j2, std::vector<std::vector<int>> &grid, std::vector<std::vector<std::vector<int>>> &dp){
        if(j1 < 0 || j2 < 0 || j1 >= grid[0].size() || j2 >= grid[0].size()){
            return -1e8;    
        }

        else if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        
        else if(i == grid.size()-1){
            if(j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        else{
            int maxi = -1e8;
            for (int dj1 = -1; dj1 <= 1; dj1++){
                for (int dj2 = -1; dj2 <= 1; dj2++){
                    if(j1 == j2)
                        maxi = std::max(maxi, grid[i][j1] + f(i+1, j1 + dj1, j2 + dj2, grid, dp));
                    else
                        maxi = std::max(maxi, grid[i][j1] + grid[i][j2] + f(i+1, j1 + dj1, j2 + dj2, grid, dp));
                } 
            }
            
            return dp[i][j1][j2] = maxi;
        }
    }

public:
    int maximumChocolates(int r, int c, std::vector<std::vector<int>> &grid) {
        std::vector<std::vector<std::vector<int>>> dp(r, std::vector<std::vector<int>>(c, std::vector<int>(c, -1)));
        return f(0, 0, c-1, grid, dp);
    }
};


// Using DP - Tabulation(Bottom-Up)
// TC - O(n * m * m) * 9
// SC - O(n * m * m)
class Solution2{
public:
    int maximumChocolates(int r, int c, std::vector<std::vector<int>> &grid) {
        std::vector<std::vector<std::vector<int>>> dp(r, std::vector<std::vector<int>>(c, std::vector<int>(c, 0)));
        // Base case for Tabulation - Filling up the Last Row
        for (int j1 = 0; j1 < c; j1++){
            for (int j2 = 0; j2 < c; j2++){
                if(j1 == j2)
                    dp[r-1][j1][j2] = grid[r-1][j1];
                else
                    dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
            }
        }

        // As 3 states are getting changes i, j1, j2 so there will be 3 for loops
        for (int i = r-2; i >= 0; i--){
            for (int j1 = 0; j1 < c; j1++){
                for (int j2 = 0; j2 < c; j2++){

                    int maxi = -1e8;
                    for (int dj1 = -1; dj1 <= 1; dj1++){
                        for (int dj2 = -1; dj2 <= 1; dj2++){
                            int ans = 0;
                            if(j1 == j2)
                                ans = grid[i][j1];
                            else
                                ans = grid[i][j1] + grid[i][j2];
                            
                            // Out of Bound Condition Check
                            if(j1 + dj1 < 0 || j2 + dj2 < 0 || j1 + dj1 >= c || j2 + dj2 >= c)
                                ans += -1e8;
                            else
                                ans += dp[i+1][j1 + dj1][j2 + dj2];
                            
                            maxi = std::max(maxi, ans);
                        } 
                    }
            
                    dp[i][j1][j2] = maxi;

                }
            }
        }
        
        return dp[0][0][c-1];
    }
};


// Space Complexity on Tabulation(Bottom-Up)
// TC - O(n * m * m) * 9
// SC - O(m * m)
// When there is 1 State Change, SC - O(1)
// 2 states Change, SC - O(n)
// 3 states Change, SC - O(n*n)
class Solution3{
public:
    int maximumChocolates(int r, int c, std::vector<std::vector<int>> &grid) {
        std::vector<std::vector<int>> front(c, std::vector<int> (c, 0));
        // Base case for Tabulation - Filling up the Last Row
        for (int j1 = 0; j1 < c; j1++){
            for (int j2 = 0; j2 < c; j2++){
                if(j1 == j2)
                    front[j1][j2] = grid[r-1][j1];
                else
                    front[j1][j2] = grid[r-1][j1] + grid[r-1][j2];
            }
        }

        // As 3 states are getting changes i, j1, j2 so there will be 3 for loops
        for (int i = r-2; i >= 0; i--){
            std::vector<std::vector<int>> curr(c, std::vector<int> (c, 0));

            for (int j1 = 0; j1 < c; j1++){
                for (int j2 = 0; j2 < c; j2++){

                    int maxi = -1e8;
                    for (int dj1 = -1; dj1 <= 1; dj1++){
                        for (int dj2 = -1; dj2 <= 1; dj2++){
                            int ans = 0;
                            if(j1 == j2)
                                ans = grid[i][j1];
                            else
                                ans = grid[i][j1] + grid[i][j2];
                            
                            // Out of Bound Condition Check
                            if(j1 + dj1 < 0 || j2 + dj2 < 0 || j1 + dj1 >= c || j2 + dj2 >= c)
                                ans += -1e8;
                            else
                                ans += front[j1 + dj1][j2 + dj2];
                            
                            maxi = std::max(maxi, ans);
                        } 
                    }
            
                    curr[j1][j2] = maxi;

                }
            }

            front = curr;
        }
        
        return front[0][c-1];
    }
};


int main(){

    return 0;
}