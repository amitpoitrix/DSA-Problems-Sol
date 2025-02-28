/**
 * 1092. Shortest Common Supersequence 
 * Link: https://leetcode.com/problems/shortest-common-supersequence/description/?envType=daily-question&envId=2025-02-28
 * 
 * 
 * Approach 1: Using Tabulation
 * We follow the same approach as we did during Print LCS. We follow the DP table of Bottom Up Approach.  
 * The given code implements a dynamic programming approach to find the shortest common supersequence of two strings, 
 * `s1` and `s2`. 
 * The algorithm initializes a 2D array `dp` to store the lengths of the shortest common supersequence for substrings 
 * of `s1` and `s2`. 
 * It iterates through both strings, filling up the array based on whether characters match or not. 
 * After populating the array, it reconstructs the shortest common supersequence by tracing back through the array, 
 * appending characters from `s1` and `s2` accordingly. 
 * Finally, it returns the constructed shortest common supersequence.
 * 
 * Complexity:
 * Time: O(m * n)
 * Space: O(m * n)
 */

class Solution1 {
    public String shortestCommonSupersequence(String str1, String str2) {
        // Approach 1: SCS using Tabulation (Bottom Up)
        int m = str1.length();
        int n = str2.length();

        int[][] dp = new int[m + 1][n + 1];

        // Using Tabulation (Bottom Up)
        for(int i = 0; i < m + 1; i++) {
            for(int j = 0; j < n + 1; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = i + j;   // means either 0 + j OR i + 0
                } else if(str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + Math.min(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        // Now in order to find the SCS string
        StringBuilder sb = new StringBuilder();

        int i = m;
        int j = n;

        while(i > 0 && j > 0) {
            // Note: Match the character instead of length dp[i-1][j] == dp[i][j-1]
            if(str1.charAt(i - 1) == str2.charAt(j - 1)) {
                sb.append(str1.charAt(i - 1));
                i--;
                j--;
            } else {
                if(dp[i - 1][j] < dp[i][j - 1]) {
                    sb.append(str1.charAt(i - 1));
                    i--;
                } else {
                    sb.append(str2.charAt(j - 1));
                    j--;
                }
            }
        }

        // Now adding the remaining one
        while(i > 0) {
            sb.append(str1.charAt(i - 1));
            i--;
        }

        while(j > 0) {
            sb.append(str2.charAt(j - 1));
            j--;
        }

        return sb.reverse().toString();
    }
}


/**
 * Approach 2: Using Memoization
 */

class Solution2 {
    public String shortestCommonSupersequence(String str1, String str2) {
        // Approach 2: SCS using Memoization (Top Down)
        int m = str1.length();
        int n = str2.length();

        int[][] dp = new int[m + 1][n + 1];
        for(int[] row: dp) {
            Arrays.fill(row, -1);
        }

        // Using Memoization (Top Down)
        // Helps in populating dp[][]
        int scs = solve(str1, str2, m, n, dp);

        // Now in order to find the SCS string
        StringBuilder sb = new StringBuilder();

        int i = m;
        int j = n;

        while(i > 0 && j > 0) {
            // Note: Match the character instead of length dp[i-1][j] == dp[i][j-1]
            if(str1.charAt(i - 1) == str2.charAt(j - 1)) {
                sb.append(str1.charAt(i - 1));
                i--;
                j--;
            } else {
                if(dp[i - 1][j] < dp[i][j - 1]) {
                    sb.append(str1.charAt(i - 1));
                    i--;
                } else {
                    sb.append(str2.charAt(j - 1));
                    j--;
                }
            }
        }

        // Now adding the remaining one
        while(i > 0) {
            sb.append(str1.charAt(i - 1));
            i--;
        }

        while(j > 0) {
            sb.append(str2.charAt(j - 1));
            j--;
        }

        return sb.reverse().toString();
    }

    private int solve(String str1, String str2, int m, int n, int[][] dp) {
        // Base Case
        if(m == 0 || n == 0) {
            return dp[m][n] = m + n;   // 0 + n OR m + 0
        }

        if(dp[m][n] != -1) {
            return dp[m][n];
        }

        // Recursive Case
        if(str1.charAt(m - 1) == str2.charAt(n - 1)) {
            return dp[m][n] = 1 + solve(str1, str2, m - 1, n - 1, dp);
        } else {
            return dp[m][n] = 1 + Math.min(solve(str1, str2, m, n - 1, dp), solve(str1, str2, m - 1, n, dp));
        }
    }
}