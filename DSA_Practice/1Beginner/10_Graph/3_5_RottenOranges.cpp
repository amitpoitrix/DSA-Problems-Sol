#include<bits/stdc++.h>
using namespace std;

// Lt: 994. Rotting Oranges
// https://leetcode.com/problems/rotting-oranges/

// Approach 1: Using BFS only
class Solution1 {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int minTime = 0, total = 0, cntRotten = 0;
        // {row, col}
        queue<pair<int, int>> rotten;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] != 0)
                    total++;
                if(grid[i][j] == 2)
                    rotten.push({i, j});
            }
        }
        
        // Up -> Right -> Down -> Left
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = { 0, 1, 0,-1};
        
        while(!rotten.empty()){
            int k = rotten.size();
            cntRotten += k;
            
            while(k--){
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();
                
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1)
                        continue;
                    
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }
            
            if(!rotten.empty())
                    minTime++;
        }
        
        return (total == cntRotten)? minTime: -1;
    }
};


// Approach 2: Using BFS only
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0, minTime = 0, countOranges = 0;
        // {{row, col}, time}
        queue<pair<pair<int, int>, int>> q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) // Count Total no. of fresh oranges
                    fresh++;

                if(grid[i][j] == 2) // Push all the rotten oranges co-ordinates into queue along with intital time = 0
                    q.push({{i, j}, 0});
            }
        }
        
        // For visiting 4 directions
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        vector<vector<int>> vis = grid; // copying the given grid
        
        // Moving level wise to rote fresh oranges and computing time parallely
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            minTime = max(minTime, t);  // Computing max time elapsed parallely
            
            // Visiting all 4 neighbours
            for(int i = 0; i < 4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                // Validating along with checking of Fresh oranges to make it rotten
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 1){
                    vis[nrow][ncol] = 2;    // Making it rotten
                    q.push({{nrow, ncol}, t + 1});  // Computing its time by referencing its neighbours time + 1
                    countOranges++; // No. of fresh oranges becomes rotten
                }
            }
            
        }
        
        return (fresh == countOranges) ? minTime: -1;
    }
};

int main(){
    return 0;
}