#include<bits/stdc++.h>
using namespace std;

// GFG: Flood Fill Algorithm
// https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

// TC - O(n * m) * 4
// SC - O(n * m) + O(n * m)
class Solution {
private:
    // Using DFS Traversal
    void dfs(int sr, int sc, vector<vector<int>>& ans, vector<vector<int>> &image, int initColor, 
    int newColor, int delrow[], int delcol[]) {
        ans[sr][sc] = newColor;
        int n = image.size();
        int m = image[0].size();
        
        // Traversing its adjacent grid
        for(int i = 0; i < 4; i++){
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
            image[nrow][ncol] == initColor && ans[nrow][ncol] != newColor){
                dfs(nrow, ncol, ans, image, initColor, newColor, delrow, delcol);
            }
        }
    }

    // Using BFS Traversal
    void bfs(int sr, int sc, vector<vector<int>>& ans, vector<vector<int>> &image, int initColor, 
    int newColor, int delrow[], int delcol[]) {
        ans[sr][sc] = newColor;
        int n = image.size();
        int m = image[0].size();
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            // Traversing its adjacent grid
            for(int i = 0; i < 4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                image[nrow][ncol] == initColor && ans[nrow][ncol] != newColor){
                    ans[nrow][ncol] = newColor;
                    q.push({nrow, ncol});
                }
            }
            
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initColor = image[sr][sc];
        vector<vector<int>> ans = image;
        
        // For moving 4 direction
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        dfs(sr, sc, ans, image, initColor, newColor, delrow, delcol);
        
        return ans;
    }
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j]; 
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}