/**
 * 1368. Minimum Cost to Make at Least One Valid Path in a Grid
 * Link: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/?envType=daily-question&envId=2025-01-18
 * 
 * 
 * Approach 1: Using Backtracking DFS
 * The idea behind this approach is to explore all possible paths from the starting point (top-left) to the destination 
 * (bottom-right) by recursively trying all four directions (up, down, left, right). 
 * At each step, we calculate the cost of moving to the next cell and backtrack when we reach a dead end or a previously 
 * visited cell. 
 * The key challenge is that this approach does not prioritize low-cost paths, which results in inefficient exploration
 * and causes time limit exceeded (TLE) errors for large grids.
 * 
 * Complexity:
 * Time: O(4^(m * n))
 * Space: O(m * n)
 */

class Solution1 {
    // right left down up
    private int[] dx = {0, 0, 1, -1};
    private int[] dy = {1, -1, 0, 0};

    public int minCost(int[][] grid) {
        // Approach 1: Trying All Ways - Backtracking
        // 1 -> right, 2 -> left, 3 -> down, 4 -> up
        int m = grid.length;
        int n = grid[0].length;

        boolean[][] visited = new boolean[m][n];

        return dfs(0, 0, 0, visited, grid, m, n);
    }

    private int dfs(int row, int col, int cost, boolean[][] visited, int[][] grid, int m, int n) {
        // Base Case
        if(row == m - 1 && col == n - 1) {
            return cost;
        }

        visited[row][col] = true;

        // Finding the min cost so far from all the 4 directions
        int minCost = Integer.MAX_VALUE;

        for(int i = 0; i < 4; i++) {
            int newRow = dx[i] + row;
            int newCol = dy[i] + col;

            if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !visited[newRow][newCol]) {
                // Computing nextCost
                int nextCost = (grid[row][col] == i + 1) ? 0: 1;

                minCost = Math.min(minCost, dfs(newRow, newCol, cost + nextCost, visited, grid, m, n));
            }
        }

        visited[row][col] = false;
        
        return minCost;
    }
}


/**
 * Approach 2: Using Dijkstra Algorithm
 * This approach leverages Dijkstra’s algorithm, which uses a priority queue to always process the cell with the current 
 * lowest cost. 
 * It iteratively explores neighboring cells and calculates the cost to reach them, adding the new cost to the 
 * priority queue. 
 * If a cheaper path to a cell is found, it updates the cost and reprocesses that cell. 
 * The algorithm ensures that we always process cells in the order of their minimum cost, leading to an optimal solution 
 * with much better efficiency compared to backtracking.
 * 
 * Complexity:
 * Time: O(m * n * log(m * n))
 * Space: O(m * n)
 */

class Solution2 {
    // 1 -> right, 2 -> left, 3 -> down, 4 -> up
    private int[] dx = {0, 0, 1, -1};
    private int[] dy = {1, -1, 0, 0};

    public int minCost(int[][] grid) {
        // Approach 2: Using Dijkstra Algorithm in Grid
        int m = grid.length;
        int n = grid[0].length;

        // minHeap {cost, {coordinates}}
        Queue<Triple> minHeap = new PriorityQueue<>(
            new Comparator<Triple> () {
                @Override
                public int compare(Triple t1, Triple t2) {
                    return Integer.compare(t1.cost, t2.cost);
                }
            }
        );

        // Populating result with Infinity
        // result[i][j] -> shortest distance from source(0, 0) to (i, j) 
        int[][] result = new int[m][n];
        for(int[] row: result) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        // Starting from (0, 0) with cost 0
        minHeap.offer(new Triple(0, 0, 0));
        result[0][0] = 0;   

        while(!minHeap.isEmpty()) { // O(m * n * log(m * n))
            Triple t = minHeap.poll();

            int currentCost = t.cost;
            int row = t.x;
            int col = t.y;

            // Optimisation
            if(row == m - 1 && col == n - 1) {
                return currentCost;
            }

            // Going to adjacent nodes
            for(int i = 0; i < 4; i++) {
                int newRow = dx[i] + row;
                int newCol = dy[i] + col;

                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    // use grid[row][col] not grid[newRow][newCol]
                    int newCost = currentCost + ((grid[row][col] == i + 1) ? 0: 1);

                    // Relaxation
                    if(newCost < result[newRow][newCol]) {
                        result[newRow][newCol] = newCost;
                        minHeap.offer(new Triple(newCost, newRow, newCol));
                    }
                }
            }
        }

        return result[m-1][n-1];
    }

    static class Triple {
        int cost;
        int x;
        int y;

        Triple(int cost, int x, int y) {
            this.cost = cost;
            this.x = x;
            this.y = y;
        }
    }
}