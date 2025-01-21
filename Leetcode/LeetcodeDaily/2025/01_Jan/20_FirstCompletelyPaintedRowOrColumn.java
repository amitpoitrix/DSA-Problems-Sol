/**
 * 2661. First Completely Painted Row or Column
 * Link: https://leetcode.com/problems/first-completely-painted-row-or-column/description/?envType=daily-question&envId=2025-01-20
 * 
 * 
 * Approach 1: Bruteforce Approach 
 * Intuition: After painting each cell, check if the entire row or column is completely painted.
 * Thought Process: This approach uses nested loops to repeatedly check the state of rows and columns, leading to high 
 * time complexity due to redundant checks.
 * 
 * Complexity:
 * Time: O(m * n * (m + n))
 * Space: O(m * n)
 */

class Solution1 {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        // Approach 1: Brute Force Approach
        // Step 1: Store current matrix element & its position(coordinates) in map
        Map<Integer, Pair> map = new HashMap<>();

        int m = mat.length;
        int n = mat[0].length;

        for(int i = 0; i < m; i++) {    // TC - O(m * n)
            for(int j = 0; j < n; j++) {
                map.put(mat[i][j], new Pair(i, j));
            }
        }

        // Step 2: Traverse over given arr and paint the arr[i] in mat by getting its coordinates from map\
        for(int i = 0; i < arr.length; i++) {   // O(m * n)
            int val = arr[i];

            Pair p = map.get(val);
            int row = p.x;
            int col = p.y;

            // Painting the current matrix element (i.e., making it -ve)
            mat[row][col] *= -1;

            if(isRowPainted(mat, row) || isColPainted(mat, col)) {  // o(m * n * (m + n))
                return i;
            }
        }

        return -1;
    }

    private boolean isRowPainted(int[][] mat, int row) {
        for(int j = 0; j < mat[0].length; j++) {
            // if there is any element in entire row which is not painted
            if(mat[row][j] > 0) {
                return false;
            }
        }

        return true;
    }

    private boolean isColPainted(int[][] mat, int col) {
        for(int i = 0; i < mat.length; i++) {
            // if there is any element in entire col which is not painted
            if(mat[i][col] > 0) {
                return false;
            }
        }

        return true;
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


/**
 * Approach 2: Better Approach
 * Intuition: Track the count of painted cells in each row and column to avoid redundant checks.
 * Thought Process: By maintaining separate counters for rows and columns, the algorithm efficiently determines when 
 * a row or column is fully painted.
 * 
 * Complexity:
 * Time: O(m * n)
 * Space: O(m * n) + O(m) + O(n)
 */

class Solution2 {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        // Approach 2: Better Approach
        // Step 1: Store current matrix element & its position(coordinates) in map
        Map<Integer, Pair> map = new HashMap<>();

        int m = mat.length;
        int n = mat[0].length;

        for(int i = 0; i < m; i++) {    // TC - O(m * n)
            for(int j = 0; j < n; j++) {
                map.put(mat[i][j], new Pair(i, j));
            }
        }

        // Step 2: Traverse over given arr and paint the arr[i] in mat by getting its coordinates from map
        // and check for entire row painted or entire column painted or not
        // Now instead of traversing each row or column for each element separately we gonna use variable that will keep track for whether each entire row is painted or not OR each entire col painted or not
        // for each row variable we'll maintain rowPaint[] & for each col, colPaint[]
        int[] rowPaint = new int[m];
        int[] colPaint = new int[n];

        for(int i = 0; i < arr.length; i++) {   // O(m * n)
            int val = arr[i];

            Pair p = map.get(val);
            int row = p.x;
            int col = p.y;

            // Painting the current matrix element
            rowPaint[row]++;
            colPaint[col]++;

            if(rowPaint[row] == n || colPaint[col] == m) { // O(1)
                return i;
            }
        }

        return -1;
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


/**
 * Approach 3: Optimised Approach
 * 
 * Intuition: Precompute the last occurrence index for all cells in a row or column and determine the earliest completion.
 * Thought Process: This approach leverages a mapping of values to their indices in the array, enabling efficient
 * computation of when a row or column is completely painted without iterative checks.
 * 
 * Complexity:
 * Time: O(m * n)
 * Space: O(m * n)
 */

class Solution3 {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        // Approach 3: Optimised Approach
        // Step 1: Store reverse mapping means {element -> idx} from arr[]
        Map<Integer, Integer> revMap = new HashMap<>();

        for(int i = 0; i < arr.length; i++) {
            revMap.put(arr[i], i);
        }

        // Step 2: Check each row one by one and find the maxIdx from map where each row is painted and keep on tracking minIdx so far which is the firstIdx to paint entire row
        // Similarly for each col one by one
        int m = mat.length;
        int n = mat[0].length;

        int minIdx = Integer.MAX_VALUE;

        // Checking row one by one
        for(int row = 0; row < m; row++) {

            // Getting max idx by traversing each row
            int maxIdx = Integer.MIN_VALUE;
            for(int col = 0; col < n; col++) {

                int val = mat[row][col];
                int idx = revMap.get(val);

                maxIdx = Math.max(maxIdx, idx);
            }

            // fetching min idx so far after fetching maxIdx for each row one by one
            minIdx = Math.min(minIdx, maxIdx);
        }

        // Checking col one by one
        for(int col = 0; col < n; col++) {

            // Getting max idx by traversing each col
            int maxIdx = Integer.MIN_VALUE;
            for(int row = 0; row < m; row++) {

                int val = mat[row][col];
                int idx = revMap.get(val);

                maxIdx = Math.max(maxIdx, idx);
            }

            // fetching min idx so far after fetching maxIdx for each col one by one
            minIdx = Math.min(minIdx, maxIdx);
        }

        return minIdx;
    }
}