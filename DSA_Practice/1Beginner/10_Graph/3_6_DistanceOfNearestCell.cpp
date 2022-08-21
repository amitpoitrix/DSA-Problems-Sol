#include<bits/stdc++.h>
using namespace std;

// GFG: Distance of nearest cell having 1
// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1

// Approach: Using BFS Traversal only
// TC - O(n * m)
// SC - O(n * m)
class Solution {
public:
	vector<vector<int>>nearest(vector<vector<int>>grid){
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    vector<vector<int>> res(n, vector<int>(m, 0));
	    vector<vector<int>> vis(n, vector<int>(m, 0));
	    
	    // Queue DS for BFS Traversal - {{row, col}, dist}
	    queue<pair<pair<int, int>, int>> q;
	    
	    // Filling up initial or starting value of queue
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            if(grid[i][j] == 1){
	                vis[i][j] = 1;
	                q.push({{i, j}, 0});
	            }
	            else
	                vis[i][j] = 0;
	        }
	    }
	    
	    int delrow[] = {-1, 0, 1, 0};
	    int delcol[] = {0, 1, 0, -1};
	    
	    // Starting the BFS Traversal
	    while(!q.empty()){
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int dist = q.front().second;
	        q.pop();
	        
	        res[row][col] = dist;
	        
	        // Visiting its 4 neighbour nodes
	        for(int i = 0; i < 4; i++){
	            int nrow = row + delrow[i];
	            int ncol = col + delcol[i];
	            
	            // Validation
	            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]){
	                vis[nrow][ncol] = 1;
	                q.push({{nrow, ncol}, dist + 1});
	            }
	        }
	    }
	    
	    return res;
	}
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}