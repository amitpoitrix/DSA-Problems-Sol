/**
 * 2503. Maximum Number of Points From Grid Queries
 * Link: https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/description/?envType=daily-question&envId=2025-03-28
 * YT: https://www.youtube.com/watch?v=XBd9vO4N0Js
 * 
 * Approach 1: Using DFS - TLE
 * For each query, we perform a DFS traversal starting from the top-left corner and count how many cells can be 
 * reached with a value less than the query value.
 * Uses recursive DFS to explore all possible paths from the start cell for each query. 
 * It counts reachable cells with a value smaller than the query but, again, recalculates everything from scratch 
 * for each query.
 * 
 * Complexity:
 * Time: O(Q * M * N)
 * Space: O(Q) + O(M * N)
 */

class Solution1 {
    private int[] dx = {0, 0, -1, 1};
    private int[] dy = {1, -1, 0, 0};

    public int[] maxPoints(int[][] grid, int[] queries) {
        int m = grid.length;
        int n = grid[0].length;

        int q = queries.length;

        int[] points = new int[q];

        for(int i = 0; i < q; i++) {
            if(queries[i] <= grid[0][0]) {
                continue;
            }

            boolean[][] visited = new boolean[m][n];
            points[i] = dfs(0, 0, grid, queries[i], visited);
        }

        return points;
    }

    private int dfs(int row, int col, int[][] grid, int query, boolean[][] visited) {
        if(row < 0 || row >= grid.length || col < 0 || col >= grid[0].length || visited[row][col] || query <= grid[row][col]) {
            return 0;
        }

        visited[row][col] = true;
        int points = 1; // for current coordinates

        for(int i = 0; i < 4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            points += dfs(newRow, newCol, grid, query, visited);
        }

        return points;
    }
}


/**
 * Approach 2: MinHeap + Sorting
 * 
 * Sort the queries and attach each query with there original idx to not to loose there original idx.
 * Take minHeap<element, coordinates> to get min value first which is less than current query and if it is than 
 * increment point for current index by 1 and add its neighbour element with its coordinates in the queue and run 
 * this while loop till this queue is empty.
 * After this while loop add the cumulative points at approriate idx in answer array.
 * 
 * Complexity:
 * Time: O(Q * log(M * N))
 * Space: O(M * N)
 */

class Solution {
    private int[] dx = {-1, 1, 0, 0};
    private int[] dy = {0, 0, -1, 1};

    public int[] maxPoints(int[][] grid, int[] queries) {
        int q = queries.length;
        int[][] sortedQuery = new int[q][2];

        for(int i = 0; i < q; i++) {
            sortedQuery[i][0] = queries[i];
            sortedQuery[i][1] = i;
        }
        
        // sorting based on ascending order of element
        Arrays.sort(sortedQuery, (a, b) -> a[0] - b[0]);

        Queue<Triple> minHeap = new PriorityQueue<>(
            new Comparator<Triple>() {
                @Override
                public int compare(Triple a, Triple b) {
                    return Integer.compare(a.element, b.element);
                }
            }
        );

        minHeap.offer(new Triple(grid[0][0], 0, 0));

        int m = grid.length;
        int n = grid[0].length;

        boolean[][] visited = new boolean[m][n];
        visited[0][0] = true;
        
        int[] answer = new int[q];
        int points = 0;

        // O(Q * log(M * N))
        for(int i = 0; i < q; i++) {
            int currentQuery = sortedQuery[i][0];
            int idx = sortedQuery[i][1];

            while(!minHeap.isEmpty()) {
                if(currentQuery <= minHeap.peek().element) {
                    break;
                }

                points++;
                Triple t = minHeap.poll(); // O(log(M * N))
                
                int element = t.element;
                int row = t.x;
                int col = t.y;

                for(int j = 0; j < 4; j++) {
                    int newRow = row + dx[j];
                    int newCol = col + dy[j];

                    if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !visited[newRow][newCol]) {
                        visited[newRow][newCol] = true;
                        minHeap.offer(new Triple(grid[newRow][newCol], newRow, newCol)); // O(log(M * N))
                    }
                }
            }

            answer[idx] = points;
        }

        return answer;
    }

    static class Triple {
        int element;
        int x;
        int y;

        Triple(int element, int x, int y) {
            this.element = element;
            this.x = x;
            this.y = y;
        }
    }
}