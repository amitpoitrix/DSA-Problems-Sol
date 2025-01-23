/**
 * 1765. Map of Highest Peak
 * Link: https://leetcode.com/problems/map-of-highest-peak/description/?envType=daily-question&envId=2025-01-22
 * 
 * 
 * Approach:
 * Thought Process:
 * If we use DFS than we might break the rule, as shown in diagram when we try to add height after incrementing by 1 when visiting new cell.
 * https://github.com/user-attachments/assets/8fe4df8e-7cce-4979-be6c-6d0469593363
 * 
 * If we use single BFS (i.e., start from single source i.e., water with height 0) than also we can’t build, As shown in the diagram yellow highlighted one difference is more than 1
 * https://github.com/user-attachments/assets/5883fc69-7b21-498f-a7be-34a3b5a69fe6
 * 
 * So we’ve to apply multi-source BFS starting from 0 height cell i.e., water
 * https://github.com/user-attachments/assets/11cb5245-b583-49ce-9921-db3d5983a5f4
 * https://github.com/user-attachments/assets/95a8b465-688f-477e-8fe1-b0554d5f9fe1
 * 
 * 
 * Another Example: Starting from multiple source
 * https://github.com/user-attachments/assets/c8d97618-3d7b-4826-8ba1-d5f065a13e5c
 * 
 * Summary:
 * The problem involves assigning heights to land cells such that the height increases with distance from the
 * nearest water cell. 
 * Since water cells are the starting points with height 0, we use Multi-Source BFS to propagate heights level 
 * by level. 
 * All water cells are added to the queue initially, and their neighbors are processed iteratively. 
 * At each step, unvisited neighboring cells are assigned a height incremented by 1 from the current cell. 
 * This ensures that heights are calculated in the order of increasing distance, guaranteeing correctness and 
 * efficiency.
 * 
 * Complexity:
 * Time: O(m * n)
 * Space: O(m * n)
 */


class Solution {
    private int[] dx = {0, 0, -1, 1};
    private int[] dy = {-1, 1, 0, 0};

    public int[][] highestPeak(int[][] isWater) {
        // Approach: Using multi-source BFS
        int m = isWater.length;
        int n = isWater[0].length;

        Queue<Pair> queue = new LinkedList<>();

        // Now adding all the source
        int[][] height = new int[m][n];
        for(int[] row: height) {
            Arrays.fill(row, -1);
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j] == 1) {
                    height[i][j] = 0;
                    queue.offer(new Pair(i, j));
                }
            }
        }

        // Now using Khandani BFS Template
        while(!queue.isEmpty()) {
            int size = queue.size();

            while(size-- > 0) {
                Pair p = queue.poll();

                int row = p.x;
                int col = p.y;

                // Now going to neighboring elements
                for(int i = 0; i < 4; i++) {
                    int newRow = row + dx[i];
                    int newCol = col + dy[i];

                    if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && height[newRow][newCol] == -1) {
                        height[newRow][newCol] = height[row][col] + 1;
                        queue.offer(new Pair(newRow, newCol));
                    }
                }
            }
        }

        return height;
    }

    static class Pair {
        int x;
        int y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}