#include<iostream>
#include<vector>
using namespace std;
// Recursion By Striver : L19. Rat in A Maze | Backtracking
// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

// TC - 4^(n*m)
// SC - O(n*m)
class Solution{
private:
    void ratMazePath(int i, int j, vector<vector<int>> &m, int n, string path, vector<vector<int>> &vis, 
    vector<string> &res, int di[], int dj[]){
        if(i == n-1 && j == n-1){
            res.push_back(path);
            return;
        }

        string dir = "DLRU";
        // Looping for All 4 Direction i.e, Down Left Right Up
        for (int idx = 0; idx < 4; idx++){
            int nexti = i + di[idx];
            int nextj = j + dj[idx];

            if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && m[nexti][nextj] == 1){
                // Marking the previous visited path
                vis[i][j] = 1;
                ratMazePath(nexti, nextj, m, n, path + dir[idx], vis, res, di, dj);
                vis[i][j] = 0;
            }
        }
        
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        // visited[]
        vector<vector<int>> vis(n, vector<int> (n, 0));
        // 4 Direction : D L R U
        // Down(i+1, j), Left(i, j-1), Right(i, j+1), Up(i-1, j)
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};

        // Checking if Starting Path is Valid or not
        if(m[0][0] == 1){
            ratMazePath(0, 0, m, n, "", vis, res, di, dj);
        }
        
        return res;
    }
};

int main(){
    std::vector<std::vector<int>> m = 
        {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}};
    
    int n = m.size();

    Solution obj;
    for (auto x : obj.findPath(m, n)){
        for (auto y : x){
            std::cout << y << " ";
        }
        std::cout << "\n";
    }

    return 0;
}