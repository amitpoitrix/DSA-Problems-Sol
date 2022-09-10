#include<bits/stdc++.h>
using namespace std;

// Lt: 130. Surrounded Regions
// https://leetcode.com/problems/surrounded-regions/

// Using BFS & DFS
// TC - O(n * m)
// SC - O(n * m)
class Solution {
private:
    void dfs(int row, int col, vector<vector<char>> &mat, vector<vector<int>> &vis, int delRow[], int delCol[]){
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 0; i < 4; i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && mat[nRow][nCol] == 'O'){
                dfs(nRow, nCol, mat, vis, delRow, delCol);
            }
        }
    }
    
    void bfs(int row, int col, vector<vector<char>> &mat, vector<vector<int>> &vis, int delRow[], int delCol[]){
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int, int>> q;
        q.push({row, col});
        
        while(!q.empty()){
            int qRow = q.front().first;
            int qCol = q.front().second;
            q.pop();
        
            for(int i = 0; i < 4; i++){
                int nRow = qRow + delRow[i];
                int nCol = qCol + delCol[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && mat[nRow][nCol] == 'O'){
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }
    
public:
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        // Now we'll traverse the surrounding & mark the vis for 'O'
        // First row & last row
        for(int j = 0; j < m; j++){
            // Checking for first row
            if(!vis[0][j] && mat[0][j] == 'O'){
                bfs(0, j, mat, vis, delRow, delCol);
            }
            // Checking for last row
            if(!vis[n-1][j] && mat[n-1][j] == 'O'){
                bfs(n-1, j, mat, vis, delRow, delCol);
            }
        }
        
        // First col & last col
        for(int i = 0; i < n; i++){
            // Checking for first col
            if(!vis[i][0] && mat[i][0] == 'O'){
                bfs(i, 0, mat, vis, delRow, delCol);
            }
            // Checking for last col
            if(!vis[i][m-1] && mat[i][m-1] == 'O'){
                bfs(i, m-1, mat, vis, delRow, delCol);
            }
        }
        
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && mat[i][j] == 'O')
                    mat[i][j] = 'X';
            }
        }
    }
};

int main(){
    return 0;
}