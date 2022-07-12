#include<bits/stdc++.h>
using namespace std;

// Lt: 994. Rotting Oranges
// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int minTime = 0, total = 0, cntRotten = 0;
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

int main(){
    return 0;
}