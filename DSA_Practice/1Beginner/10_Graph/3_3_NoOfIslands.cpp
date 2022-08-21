#include <bits/stdc++.h>
using namespace std;

// GFG: Find the number of islands
// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

// GFG Ques: Check for neighbour in 8 direction
// TC - O(v^2)
// SC - O(V^2)
class Solution {
private:
    // Using DFS Traversal
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>> &vis) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        
        // Traverse towards its neighbour nodes
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                int nrow = row + i;
                int ncol = col + j;
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                    dfs(nrow, ncol, grid, vis);
                }
            }
        }
    }

    // Using BFS Traversal
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>> &vis) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        q.push({row, col});
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            // Traverse towards its neighbour nodes
            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    int nrow = r + i;
                    int ncol = c + j;
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }

    }    
    
public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> vis(row, vector<int> (col, 0));
        int cnt = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    // dfs(i, j, grid, vis);
                    bfs(i, j, grid, vis);
                }
            }
        }
        
        return cnt;
    }
};

// Leetcode Ques: Here only check for 4 direction
class Solution {
private:
    // Using DFS Traversal
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>> &vis) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        
        // Traverse its neighbour nodes
        int rd[] = {-1, 0, 1, 0};
        int cd[] = {0, 1, 0, -1};
        
        for(int i = 0; i < 4; i++){
            int nrow = row + rd[i];
            int ncol = col + cd[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1')
                dfs(nrow, ncol, grid, vis);
        }
    }
    
    // Using BFS Traversal
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>> &vis) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        
        int rd[] = {-1, 0, 1, 0};
        int cd[] = {0, 1, 0, -1};
        
        queue<pair<int, int>> q;
        q.push({row, col});
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            // Traverse its neighbour nodes
            for(int i = 0; i < 4; i++){
                int nrow = r + rd[i];
                int ncol = c + cd[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> vis(row, vector<int> (col, 0));
        int cnt = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i, j, grid, vis);
                }
            }
        }
        
        return cnt;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
