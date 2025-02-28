/**
 * 873. Length of Longest Fibonacci Subsequence
 * Link: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/?envType=daily-question&envId=2025-02-27
 * 
 * Approach 1: Using Recursion
 * Store indices of array elements in a hashmap for quick lookup.
 * Iterate through all pairs (j, k) as potential last two elements of a Fibonacci-like subsequence.
 * Use recursion to find the longest valid sequence by checking if arr[k] - arr[j] exists before j.
 * Base case: If no valid preceding element exists, return 2 (since (j, k) itself is a sequence).
 * Track and return the maximum length found.
 * 
 * Complexity:
 * Time: O(n^2. logn)
 * Space: O(n)
 */

class Solution1 {
    public int lenLongestFibSubseq(int[] arr) {
        // Approach 1: Using Recursion
        // Map<Element, Idx>
        Map<Integer, Integer> map = new HashMap<>();
        
        int n = arr.length;
        for(int i = 0; i < n; i++) {
            map.put(arr[i], i);
        }

        int maxLength = 0;

        for(int j = 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                int result = solve(j, k, arr, map);

                if(result >= 3) {
                    maxLength = Math.max(maxLength, result);
                }
            }
        }

        return maxLength;
    }

    private int solve(int j, int k, int[] arr, Map<Integer, Integer> map) {
        int target = arr[k] - arr[j];

        if(map.containsKey(target) && map.get(target) < j) {
            int i = map.get(target);

            // +1 is for kth element which is part of subsequence
            return 1 + solve(i, j, arr, map);
        }

        return 2;   // Base Case when there is j & k only
    }
}


/**
 * Approach 2: Using Recursion + Memoization
 * 
 * Complexity:
 * Time: O(n^2)
 * Space: O(n^2)
 */

class Solution2 {
    public int lenLongestFibSubseq(int[] arr) {
        // Approach 2: Using Recursion + Memoization
        // Map<Element, Idx>
        Map<Integer, Integer> map = new HashMap<>();
        
        int n = arr.length;
        for(int i = 0; i < n; i++) {
            map.put(arr[i], i);
        }

        // Introducing Memo
        int[][] dp = new int[n][n];
        for(int[] row: dp) {
            Arrays.fill(row, -1);
        }

        int maxLength = 0;

        for(int j = 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                int result = solve(j, k, arr, map, dp);

                if(result >= 3) {
                    maxLength = Math.max(maxLength, result);
                }
            }
        }

        return maxLength;
    }

    private int solve(int j, int k, int[] arr, Map<Integer, Integer> map, int[][] dp) {
        if(dp[j][k] != -1) {
            return dp[j][k];
        }
        
        int target = arr[k] - arr[j];

        if(map.containsKey(target) && map.get(target) < j) {
            int i = map.get(target);

            // +1 is for kth element which is part of subsequence
            return dp[j][k] = 1 + solve(i, j, arr, map, dp);
        }

        return dp[j][k] = 2;   // Base Case when there is j & k only
    }
}


/**
 * Approach 3: Using Tabulation (Bottom Up)
 * This approach builds the solution iteratively using a 2D table t[j][k], where each entry stores the 
 * longest subsequence ending at (j, k). 
 * By iterating over all possible pairs and looking up previous elements efficiently, it constructs the 
 * solution in a structured manner.
 * 
 * Complexity:
 * Time: O(n^2)
 * Space: O(n^2)
 */

class Solution {
    public int lenLongestFibSubseq(int[] arr) {
        // Approach 3: Using Tabulation (Bottom Up)
        // Map<Element, Idx>
        Map<Integer, Integer> map = new HashMap<>();
        
        int n = arr.length;
        for(int i = 0; i < n; i++) {
            map.put(arr[i], i);
        }
        
        // dp[i][j] = largest length of subsequence till index i & j
        int[][] dp = new int[n][n];

        // Initialization every state with 2 as min length of subsequence ending with index i & j can be 2
        for(int[] row: dp) {
            Arrays.fill(row, 2);
        }   

        int maxLength = 0;

        for(int j = 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                int target = arr[k] - arr[j];

                if(map.containsKey(target) && map.get(target) < j) {
                    int i = map.get(target);

                    dp[j][k] = dp[i][j] + 1;

                    maxLength = Math.max(maxLength, dp[j][k]);
                }
            }
        }

        return maxLength < 3 ? 0: maxLength;
    }
}