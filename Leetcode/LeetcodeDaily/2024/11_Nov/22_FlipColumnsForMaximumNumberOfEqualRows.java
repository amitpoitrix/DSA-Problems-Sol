import java.util.*;

/*
 * 1072. Flip Columns For Maximum Number of Equal Rows
 * Link: https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/description/?envType=daily-question&envId=2024-11-22
 * 
 * 
 * Approach: Row Matching with inverted
 * 
 * Logic: 
 * Compares each row in the matrix to a reference row (currRow) and its inverted version (where 0s are flipped to 1s and 1s to 0s). Counts how many rows match either of these.
 * 
 * Implementation:
 * For each row, create an inverted version.
 * Count rows in the matrix that match either the reference row or its inverted version.
 * Update the maximum count of matching rows.
 * 
 * Complexity:
 * Time: O(n * (m ^ 2)), as each row is compared with every other row.
 * Space: O(n), for storing the inverted row.
 * 
 * Advantage: Straightforward logic based on direct comparison of rows.
 */

class Solution1 {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        // Approach: Kind of tricky problem as simulation (BruteForce Approach) is not possible so its based on observation based problem

        // Here the Observation was the row having same values or there alternate value will boils down to equal rows when we change column wise value from 0 to 1 & vice-versa

        // Step 1: Traverse to each & every row of the matrix and find no. of rows similar to it along with its alternative & count the max rows
        int maxRows = 0;
        for(int[] row: matrix) {
            int[] inverseRow = new int[row.length];

            for(int j = 0; j < row.length; j++) {
                inverseRow[j] = 1 - row[j]; // so if its 1 than result is 0 else 1
            }

            int countRows = 0;
            for(int[] tempRow: matrix) {
                // Note: Use Arrays.equals(arr1, arr2) for comparison instead of "=="
                if(Arrays.equals(tempRow, row) || Arrays.equals(tempRow, inverseRow)) {
                    countRows++;
                }
            }

            maxRows = Math.max(maxRows, countRows);
        }

        return maxRows;
    }
}


/*
 * Approach 2: Row Patterns using unordered_map or HashMap
 * 
 * Logic: 
 * Encodes each row into a pattern ('s' for "same as the first column" and 'd' for "different from the first column"). 
 * Tracks the frequency of each pattern using a hash map.
 * 
 * Implementation:
 * Convert each row into a string pattern based on its relation to the first column.
 * Use a hash map to count occurrences of each pattern.
 * The maximum frequency gives the result.
 * 
 * Complexity:
 * Time: O(m * n), as each row is processed and stored once.
 * Space: O(m * n), for storing the patterns in the hash map.
 * 
 * Advantage: Efficient due to hashing and avoids redundant comparisons.
 */

 class Solution2 {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        // Approach 2: Using HashMap
        HashMap<String, Integer> map = new HashMap<>();
        
        for(int[] row: matrix) {
            StringBuffer sb = new StringBuffer();
            sb.append('s'); // as first element will always equals with itself

            for(int i = 1; i < row.length; i++) {
                if(row[0] == row[i]) {
                    sb.append('s');
                } else {
                    sb.append('d');
                }
            }

            // Adding frequency of each row value formed
            map.put(sb.toString(), map.getOrDefault(sb.toString(), 0) + 1);
        }

        int maxRows = 0;
        for(Map.Entry<String, Integer> e: map.entrySet()) {
            maxRows = Math.max(maxRows, e.getValue());
        }

        return maxRows;
    }
}