/*
 * 2257. Count Unguarded Cells in the Grid
 * Link: https://leetcode.com/problems/count-unguarded-cells-in-the-grid/?envType=daily-question&envId=2024-11-21
 * 
 * Approach: Simple Simulation
 */

class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int[][] visited = new int[m][n];

        for(int[] guard: guards) {
            visited[guard[0]][guard[1]] = -1;
        }

        for(int[] wall: walls) {
            visited[wall[0]][wall[1]] = -2;
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j] == -1) {
                    // means its a guard
                    markVisited(i, j, m, n, visited);
                }
            }
        }

        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j] == 0) {
                    count++;
                }
            }
        }

        return count;
    }

    private void markVisited(int row, int col, int m, int n, int[][] visited) {
        // Means at {row, col} we've guard
        // Moving north
        for(int i = row - 1; i >= 0; i--) {
            if(visited[i][col] == -1 || visited[i][col] == -2) {
                // As we saw the guard or wall
                break;  
            }

            if(visited[i][col] == 0) {
                visited[i][col] = 1;
            }
        }

        // Moving east
        for(int j = col + 1; j < n; j++) {
            if(visited[row][j] == -1 || visited[row][j] == -2) {
                // As we saw the guard or wall
                break;  
            }

            if(visited[row][j] == 0) {
                visited[row][j] = 1;
            }
        }

        // Moving south
        for(int i = row + 1; i < m; i++) {
            if(visited[i][col] == -1 || visited[i][col] == -2) {
                // As we saw the guard or wall
                break;  
            }

            if(visited[i][col] == 0) {
                visited[i][col] = 1;
            }
        }

        // Moving west
        for(int j = col - 1; j >= 0; j--) {
            if(visited[row][j] == -1 || visited[row][j] == -2) {
                // As we saw the guard or wall
                break;  
            }

            if(visited[row][j] == 0) {
                visited[row][j] = 1;
            }
        }
    }
}