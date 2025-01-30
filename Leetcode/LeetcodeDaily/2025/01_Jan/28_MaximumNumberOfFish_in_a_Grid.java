/**
 * 2658. Maximum Number of Fish in a Grid
 * Link: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/?envType=daily-question&envId=2025-01-28
 * 
 * 
 * Approach 1: Using DFS
 * The DFS approach recursively explores connected components, diving deep into each direction until no more 
 * fish-containing cells are reachable. 
 * Each cell is visited once, and fish counts are accumulated during the recursive calls.
 * 
 * Complexity:
 * Time: O(n * m)
 * Space: O(1)
 */

class Solution1 {
    private int[] dx = {-1, 1, 0, 0};
    private int[] dy = {0, 0, -1, 1};

    public int findMaxFish(int[][] grid) {
        /*
            BFS: Queue<Coordinates>
            No need of visited[][] will choose those coordinates whose value i.e., grid[i][j] > 0 and once processing done than we'll make it grid[i][j] = 0

            Same Approach should be apply in DFS also
        */

        // Approach 1: Using DFS
        int m = grid.length;
        int n = grid[0].length;

        // No need of visited[][]

        int maxFishCount = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // If there is water having fish than only applying DFS
                if(grid[i][j] > 0) {
                    maxFishCount = Math.max(maxFishCount, dfs(i, j, grid, m, n));
                }
            }
        }

        return maxFishCount;
    }

    private int dfs(int row, int col, int[][] grid, int m, int n) {
        int fishCount = grid[row][col];
        grid[row][col] = 0; // Act as visited[][]

        // Going to Adjacent nodes i.e., 4 directions
        for(int i = 0; i < 4; i++) {
            int newRow = dx[i] + row;
            int newCol = dy[i] + col;

            if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] > 0) {
                fishCount += dfs(newRow, newCol, grid, m, n);
            }
        }

        return fishCount;
    }
}


/**
 * Approach 2: Using BFS
 * This approach explores each connected component using BFS. 
 * Starting from a cell with fish, all reachable cells are visited level by level, accumulating the fish count 
 * and marking cells as visited. 
 * The idea is to traverse the grid iteratively, ensuring all connected cells are explored systematically.
 * 
 * Complexity:
 * Time: O(n * m)
 * Space: O()
 */

class Solution2 {
    private int[] dx = {-1, 1, 0, 0};
    private int[] dy = {0, 0, -1, 1};

    public int findMaxFish(int[][] grid) {
        /*
            BFS: Queue<Coordinates>
            No need of visited[][] will choose those coordinates whose value i.e., grid[i][j] > 0 and once processing done than we'll make it grid[i][j] = 0

            Same Approach should be apply in DFS also
        */

        // Approach 2: Using BFS
        int m = grid.length;
        int n = grid[0].length;

        // No need of visited[][]

        int maxFishCount = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // If there is water having fish than only applying DFS
                if(grid[i][j] > 0) {
                    maxFishCount = Math.max(maxFishCount, bfs(i, j, grid));
                }
            }
        }

        return maxFishCount;
    }

    private int bfs(int row, int col, int[][] grid) {
        Queue<Coordinate> queue = new LinkedList<>();
        queue.offer(new Coordinate(row, col));

        int fishCount = 0;

        while(!queue.isEmpty()) {
            Coordinate c = queue.poll();

            int currentRow = c.row;
            int currentCol = c.col;

            fishCount += grid[currentRow][currentCol];
            grid[currentRow][currentCol] = 0;   // Act as visited[][]

            for(int i = 0; i < 4; i++) {
                int newRow = dx[i] + currentRow;
                int newCol = dy[i] + currentCol;

                if(newRow >= 0 && newRow < grid.length && newCol >= 0 && newCol < grid[0].length && grid[newRow][newCol] > 0) {
                    queue.offer(new Coordinate(newRow, newCol));
                }
            }
        }

        return fishCount;
    }

    static class Coordinate {
        int row;
        int col;

        Coordinate(int row, int col) {
            this.row = row;
            this.col = col;
        }
    }
}


/**
 * Approach 3: Using DSU
 * The intuition is to treat each cell as a node and connect adjacent cells containing fish using the union 
 * operation. 
 * By grouping connected cells into components, the size array tracks the total fish count for each component. 
 * The goal is to find the maximum size of any connected component, representing the maximum fish collected.
 * 
 * Complexity:
 * Time: O(n * m)
 * Space: O(n * m)
 */

class Solution3 {
    private int[] dx = {-1, 1, 0, 0};
    private int[] dy = {0, 0, -1, 1};

    public int findMaxFish(int[][] grid) {
        // Approach 3: Using DSU - As we've to done grouping and we can consider unionBySize
        int m = grid.length;
        int n = grid[0].length;

        // As in DSU we're using parent[] & size[] in 1D form so converting 2D to 1D
        int totalCell = m * n;

        DSU dsu = new DSU(totalCell);
        dsu.populateParent(totalCell);

        // size with grid[i][j] value
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0) {
                    int idx = i * n + j;    // 2D to 1D indexing
                    dsu.populateSize(idx, grid[i][j]);
                }
            }
        }

        // Now we'll do the grouping using union by traversing each and every node in matrix
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0) {
                    // Getting current element idx
                    int currentIdx = i * n + j;

                    // Now getting adjacent element idx
                    for(int k = 0; k < 4; k++) {
                        int newRow = dx[k] + i;
                        int newCol = dy[k] + j;

                        if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] > 0) {
                            int adjacentIdx = newRow * n + newCol;

                            dsu.unionBySize(currentIdx, adjacentIdx);
                        }
                    }
                }
            }
        }

        return dsu.maxElementInSize();
    }

    static class DSU {
        private int[] parent;
        private int[] size;

        public DSU(int n) {
            this.parent = new int[n];
            this.size = new int[n];
        }

        public void populateParent(int n) {
            for(int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        public void populateSize(int idx, int value) {
            size[idx] = value;
        }

        public int maxElementInSize() {
            int maxElement = 0;

            for(int i = 0; i < size.length; i++) {
                maxElement = Math.max(maxElement, size[i]);
            }

            return maxElement;
        }

        // DSU - find parents node of current node
        public int find(int node) {
            if(node == parent[node]) {
                return node;
            }

            return parent[node] = find(parent[node]);
        }

        // DSU - union by size - we use it when count of nodes in a group metters
        public void unionBySize(int u, int v) {
            // Finding parents first using find() not parent[]
            int uParent = find(u);
            int vParent = find(v);

            if(uParent == vParent) {
                return;
            }

            if(size[uParent] > size[vParent]) {
                parent[vParent] = uParent;
                size[uParent] += size[vParent];
            } else if(size[uParent] < size[vParent]) {
                parent[uParent] = vParent;
                size[vParent] += size[uParent];
            } else {
                // any node can become parent
                parent[uParent] = vParent;
                size[vParent] += size[uParent];
            }
        }
    }
}