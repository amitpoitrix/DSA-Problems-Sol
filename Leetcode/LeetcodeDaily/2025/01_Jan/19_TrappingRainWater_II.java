/**
 * 407. Trapping Rain Water II
 * Link: https://leetcode.com/problems/trapping-rain-water-ii/description/?envType=daily-question&envId=2025-01-19
 * 
 * 
 * Approach: Using min-heap & BFS
 * The goal is to simulate how water would fill a landscape based on cell heights in a grid. 
 * Water flows from the boundary inward, filling lower cells first.
 * 
 * Intuition:
 * Boundary Cells: Water cannot flow past the boundary, so we start processing from the edges.
 * Flooding Inward: Water fills lower cells first, and the amount trapped depends on neighboring cell heights.
 * 
 * Why a Min-Heap?
 * A min-heap is used to always process the lowest height cell first:
 * Efficient Extraction: The heap allows quick access to the smallest height cell, ensuring correct flooding order.
 * Simulating Water Flow: After processing a cell, its lower neighbors are added to the heap with updated heights, 
 * ensuring proper water flow.
 * 
 * Complexity:
 * Time: O(m * n * log(m * n)), where m and n are grid dimensions.
 * Space: O(m * n) for the heap and visited array.
 * 
 * The min-heap ensures efficient processing of the grid, simulating water filling the landscape in the correct order.
 */


class Solution {
    private int[] dx = {0, 0, 1, -1};
    private int[] dy = {1, -1, 0, 0};

    public int trapRainWater(int[][] heightMap) {
        // Approach:
        // Step 1: Traverse the boundary cells & store them in minHeap {height, {coordinates}} and mark them as visited
        int row = heightMap.length;
        int col = heightMap[0].length;

        Queue<Triple> minHeap = new PriorityQueue<>(
            new Comparator<Triple> () {
                @Override
                public int compare(Triple t1, Triple t2) {
                    return Integer.compare(t1.height, t2.height);
                }
            }
        );

        boolean[][] visited = new boolean[row][col];

        // populating boundary columns
        for(int i = 0; i < row; i++) {
            minHeap.offer(new Triple(heightMap[i][0], i, 0));
            visited[i][0] = true;

            minHeap.offer(new Triple(heightMap[i][col - 1], i, col - 1));
            visited[i][col - 1] = true;
        }

        // populating boundary rows
        for(int j = 0; j < col; j++) {
            minHeap.offer(new Triple(heightMap[0][j], 0, j));
            visited[0][j] = true;

            minHeap.offer(new Triple(heightMap[row - 1][j], row - 1, j));
            visited[row - 1][j] = true;
        }


        // Step 2: Now get the min height element from top of minHeap and visit its unvisited nodes and than unvisited height 
        // is less than add there difference in totalWater and than add this univisted node with updated height beck in minHeap
        int totalWater = 0;

        while(!minHeap.isEmpty()) {
            Triple current = minHeap.poll();

            int height = current.height;
            int x = current.x;
            int y = current.y;

            // Now visiting all 4 directions
            for(int i = 0; i < 4; i++) {
                int newRow = x + dx[i];
                int newCol = y + dy[i];

                if(newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = true;
                    
                    // Water will only add if currentHeight is greater than neighbors one
                    totalWater += Math.max(height - heightMap[newRow][newCol], 0);

                    // Now while adding neighbor height it should be max(currentHeight, neightBorHeight) for correct calculation of water trapped
                    minHeap.offer(new Triple(Math.max(height, heightMap[newRow][newCol]), newRow, newCol));
                }
            }
        }

        return totalWater;
    }   

    static class Triple {
        int height;
        int x;
        int y;

        Triple(int height, int x, int y) {
            this.height = height;
            this.x = x;
            this.y = y;
        }
    }
}