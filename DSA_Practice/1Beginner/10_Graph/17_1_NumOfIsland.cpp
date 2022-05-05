#include<iostream>
#include<vector>
using namespace std;

// Striver SDE Sheet : Number of Island
// https://leetcode.com/problems/number-of-islands/

// Algo:
// Apply dfs on grid whose value is 1 and check for further dfs call on 4 direction i.e., Up Down Left right

// TC - O(mn) - Avg Case; O(m^2 * n^2) - Worst Case
class Solution {
private:
    void dfs(int i, int j, int row, int col, vector<vector<char>>& grid){
        if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        // Up Down Left Right (U D L R)
        dfs(i-1, j, row, col, grid);
        dfs(i+1, j, row, col, grid);
        dfs(i, j-1, row, col, grid);
        dfs(i, j+1, row, col, grid);
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int ans = 0;
        
        for(int i=0; i < row; i++){
            for(int j=0; j < col; j++){
                // Calling dfs only when grid is 1
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(i, j, row, col, grid);
                }
            }
        }
        
        return ans;
    }
};

int main(){
    return 0;
}