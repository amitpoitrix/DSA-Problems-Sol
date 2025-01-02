/**
 * 1639. Number of Ways to Form a Target String Given a Dictionary
 * Link: https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/?envType=daily-question&envId=2024-12-29
 * 
 * 
 * Approach: Using DP(Memoization)
 * 
 * The solution uses dynamic programming with memoization to calculate the number of ways to form the target string from 
 * columns of words. 
 * A freq table precomputes character frequencies for each column. 
 * The recursive function solve(i, j) considers two choices: skip the current column or use it to match target[i]. 
 * Results are stored in a DP table t[i][j] to avoid redundant computations, with modular arithmetic ensuring results 
 * fit within bounds. 
 * This approach efficiently handles overlapping subproblems and large inputs.
 * 
 * Complexity:
 * Time: O(26 * n) ~ O(n)
 * Space: O(26 * n) ~ O(n)
 */

class Solution {
    private final int MOD = (int)1e9 + 7;

    public int numWays(String[] words, String target) {
        // Approach 1: Using Memoization
        int n = words[0].length();

        // Character frequency of n columns - should be of type long
        long[][] freq = new long[26][n];

        for(int col = 0; col < n; col++) {
            for(String word: words) {
                char ch = word.charAt(col);
                freq[ch - 'a'][col]++;
            }
        }

        int[][] dp = new int[n][target.length()];
        for(int[] row: dp) {
            Arrays.fill(row, -1);
        }

        return solve(0, 0, freq, n, target, dp) % MOD;
    }

    private int solve(int i, int j, long[][] freq, int n, String target, int[][] dp) {
        // Base Case: Here order of base case matters
        // 1st: Check if target is formed if yes return 1 from here
        if(j == target.length()) {
            return 1;
        }

        // 2nd: Now here check for out of bound conditions for each word
        if(i >= n) {
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j] % MOD;
        }

        // Recursive Case
        int notTaken = solve(i + 1, j, freq, n, target, dp) % MOD;

        // Here we're matching the target character with freqChar formed from words[]
        char targetChar = target.charAt(j);
        // Here freq[targetChar - 'a'][i] is in long so I took the MOD, than MOD of whole multiplication and than typecast to int
        int taken = (int)(((freq[targetChar - 'a'][i] % MOD) * solve(i + 1, j + 1, freq, n, target, dp)) % MOD);

        return dp[i][j] = (notTaken + taken) % MOD;
    }
}


// a c c a
// b b b b
// c a c a

// t = aba