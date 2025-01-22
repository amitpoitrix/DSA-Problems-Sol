/**
 * 2017. Grid Game
 * Link: https://leetcode.com/problems/grid-game/description/?envType=daily-question&envId=2025-01-21
 * 
 * 
 * Diagram:
 * https://github.com/user-attachments/assets/d6256917-7847-4996-8ed5-1b9b2881db05
 * 
 * 
 * Approach:
 * The problem involves two robots, Robot1 and Robot2, navigating through a 2D grid. Robot1 moves first and selects a column 
 * in the grid, while Robot2 moves afterward and tries to minimize the remaining sum in the second row of the grid. 
 * The goal is to minimize the sum that Robot2 has to deal with after Robot1 has made its move.
 * 
 * Thought Process:
 * Initial Setup: The sum of all elements in the first row (firstRowRemainSum) is calculated at the start. 
 * This helps track the remaining sum for Robot1's strategy.
 * 
 * Iterative Strategy: For each column, Robot1 "takes" that column by subtracting the value from firstRowRemainSum. 
 * This simulates Robot1's choice.
 * 
 * Robot2's Best Response: After Robot1's choice, Robot2 attempts to minimize the remaining sum in the second row by selecting
 * the best possible outcome (max between remaining sums of the first and second rows).
 * 
 * Tracking the Minimum: The goal is to track the minimum possible sum for Robot2 by updating minimizedRobot2Sum at each step.
 * 
 * Approach:
 * Accumulation: The sum of the first row is accumulated at the start, and then progressively updated as Robot1 moves.
 * 
 * Max/Min Operations: For each column, the maximum of the remaining sum of the first row and the accumulated sum of the 
 * second row is calculated, and the minimum of these values is tracked.
 * 
 * Efficiency: The algorithm processes each column once, resulting in a time complexity of O(col), where col is the number 
 * of columns in the grid.
 * 
 * 
 * Complexity:
 * Time: O(col)
 * Space: O(1)
 */

class Solution {
    public long gridGame(int[][] grid) {
        // Approach:
        // Here there is just 2 rows with n columns, so in order to minimize grid[i][j]
        // for robot2 by robot1, robot1 needs to decide at which column it should move
        // down and than he's only allowed to move right.
        // so deciding factor is at which column robot1 is going to move down so for
        // this we'll precompute prefix sum of row_0 and keep on subtracting current
        // grid[i][j] element while traversing, meanwhile before going to next column
        // we'll maintain 2nd row sum using current grid[i][j] than gonna contribute in
        // the path sum for robot2 while choosing max path sum optimally

        int n = grid[0].length;

        long firstRowRemSum = 0;    // precompute prefix sum of row_0
        for(int element: grid[0]) {
            firstRowRemSum += element;
        }

        long secondRowRemSum = 0;   // will come from current element before going to next col

        long robotTwoMaxSum = Long.MAX_VALUE; // Here robot1 will try to minise this

        for(int col = 0; col < n; col++) {
            firstRowRemSum -= grid[0][col];

            long robotTwoCurrentPath = Math.max(firstRowRemSum, secondRowRemSum);

            robotTwoMaxSum = Math.min(robotTwoMaxSum, robotTwoCurrentPath);

            secondRowRemSum += grid[1][col];
        }

        return robotTwoMaxSum;
    }
}