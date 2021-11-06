#include<iostream>
#include<vector>
// Flood Fill

using namespace std;
// asf -> answer so far
void floodfill(vector<vector<int>> maze, int sr, int sc, string asf,vector<vector<bool>> visited) {
//write your code here
    if(sr < 0 || sc < 0 || sr == maze.size() || sc == maze[0].size() || maze[sr][sc] == 1 || visited[sr][sc] == true)
        return;
    
    if(sr == maze.size() -1 && sc == maze[0].size() - 1){
        cout << asf << endl;
        return;
    }

    // rec call
    visited[sr][sc] = true;
    floodfill(maze, sr-1, sc, asf + "t", visited);
    floodfill(maze, sr, sc-1, asf + "l", visited);
    floodfill(maze, sr+1, sc, asf + "d", visited);
    floodfill(maze, sr, sc+1, asf + "r", visited);
    visited[sr][sc] = false;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> arr(n, vector<int>(m));

  vector<vector<bool>> visited(n, vector<bool>(m));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> arr[i][j];

  floodfill(arr, 0, 0, "", visited);
}