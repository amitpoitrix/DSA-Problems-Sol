import java.util.*;

/*
 * 2577. Minimum Time to Visit a Cell In a Grid
 * Link: https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/description/?envType=daily-question&envId=2024-11-29
 * 
 * 
 * Approach:
 * 
 * This solution uses a priority queue-based BFS (similar to Dijkstra’s algorithm) to find the minimum time to 
 * reach the bottom-right corner of the grid. 
 * 
 * Starting from (0,0), it explores neighboring cells and pushes them into the queue with the earliest possible 
 * time based on the grid's constraints. 
 * 
 * If a cell's time is less than or equal to current time + 1, it can be visited immediately; 
 * otherwise, the wait time is adjusted based on parity. 
 * 
 * The algorithm continues until the destination is reached or all possibilities are exhausted. 
 * 
 * If the destination is unreachable, it returns -1.
 */

 class Solution {
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};

    public int minimumTime(int[][] grid) {
        // Using Dijkstra Algorithm but without its resultant[] which initialises to infinity
        int m = grid.length;
        int n = grid[0].length;

        // Edge Case: No possibility of doing to & fro to increase the time
        if(grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        boolean[][] visited = new boolean[m][n];

        Queue<Tuple> pq = new PriorityQueue<>((Tuple a, Tuple b) -> a.time - b.time);
        pq.offer(new Tuple(0, 0, 0));

        while(!pq.isEmpty()) {
            Tuple t = pq.poll();

            int currTime = t.time;
            int currX = t.x;
            int currY = t.y;

            // if we reach destination than return current time
            if(currX == m - 1 && currY == n - 1) {
                return currTime;
            }

            for(int i = 0; i < 4; i++) {
                int newX = currX + dx[i];
                int newY = currY + dy[i];

                if(newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    
                    // computing new time
                    int newTime;
                    if(currTime + 1 >= grid[newX][newY]) {
                        newTime = currTime + 1;
                    } else {
                        // we need to increase time - while doing to & fro movement
                        if((grid[newX][newY] - currTime) % 2 != 0) {
                            // means odd
                            newTime = grid[newX][newY];
                        } else {
                            // even
                            newTime = grid[newX][newY] + 1;
                        }
                    }

                    pq.offer(new Tuple(newTime, newX, newY));
                }
            }
        }

        return -1;
    }
}

class Tuple {
    int time;
    int x;
    int y;

    Tuple(int time, int x, int y) {
        this.time = time;
        this.x = x;
        this.y = y;
    }
}