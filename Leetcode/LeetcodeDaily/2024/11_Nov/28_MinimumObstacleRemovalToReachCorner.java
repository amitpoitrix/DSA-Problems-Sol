import java.util.*;

/*
 * 2290. Minimum Obstacle Removal to Reach Corner
 * Link: https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/description/?envType=daily-question&envId=2024-11-28
 * 
 * Approach:
 * 
 * The solution finds the minimum number of obstacles to remove to reach the bottom-right corner of a grid from 
 * the top-left using a modified Dijkstra's algorithm. 
 * It utilizes a priority queue to explore cells with the least obstacle count first, ensuring an optimal path 
 * is found. 
 * Each neighboring cell is evaluated, and the obstacle count is updated if a shorter path is discovered. 
 * The result is stored in a 2D array, and the minimum obstacle count to reach the destination is returned. 
 * 
 * The overall time complexity is O((m * n) log (m * n)).
 */

 class Solution {
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};

    public int minimumObstacles(int[][] grid) {
        // Using Djikstra's Algorithm

        int m = grid.length;
        int n = grid[0].length;

        // We can't use queue as distance is not unit weight
        Queue<Tuple> pq = new PriorityQueue<>((Tuple a, Tuple b) -> a.distance - b.distance);

        int[][] result = new int[m][n];
        for(int[] row: result) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        // for src node
        pq.offer(new Tuple(0, 0, 0));

        while(!pq.isEmpty()) {

            Tuple t = pq.poll();

            int currDist = t.distance;
            int currX = t.x;
            int currY = t.y;

            if((currX == m-1) && (currY == n-1)) {
                return result[currX][currY];
            }

            for(int i = 0; i < 4; i++) {

                int newX = currX + dx[i];
                int newY = currY + dy[i];

                if(newX >= 0 && newX < m && newY >= 0 && newY < n) {

                    if(currDist + grid[newX][newY] < result[newX][newY]) {

                        result[newX][newY] = currDist + grid[newX][newY];
                        pq.offer(new Tuple(currDist + grid[newX][newY], newX, newY));
                    }
                }
            }
        }

        return result[m-1][n-1];
    }
}

class Tuple {
    int distance;
    int x;
    int y;

    Tuple(int distance, int x, int y) {
        this.distance = distance;
        this.x = x;
        this.y = y;
    }
}