/**
 * 2466. Count Ways To Build Good Strings
 * Link: https://leetcode.com/problems/count-ways-to-build-good-strings/description/?envType=daily-question&envId=2024-12-30
 * 
 * 
 * Approach: Using recursion + Memoization
 * 
 * Uses recursion to explore all possible string lengths.
 * Memoization is applied to avoid recomputing results for the same lengths, storing intermediate results in a dp[]
 * Time complexity is reduced by reusing precomputed values.
 * Suitable for smaller ranges of low to high due to recursion overhead.
 * 
 * Recursion Tree: https://github.com/user-attachments/assets/2e4ccecb-33e7-4336-9f1e-be85ade2f989
 */

class Solution {
    private int MOD = (int)(1e9 + 7);

    public int countGoodStrings(int low, int high, int zero, int one) {
        // Approach: Recursion + Memoization
        int[] dp = new int[high + 1];
        Arrays.fill(dp, -1);

        return solve(0, low, high, zero, one, dp);
    }

    private int solve(int idx, int low, int high, int zero, int one, int[] dp) {
        // Base Case
        if(idx > high) {
            return 0;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        // Recursive Case
        int isOne = 0;
        if(idx >= low) {
            isOne = 1;
        }

        int appZero = solve(idx + zero, low, high, zero, one, dp) % MOD;
        int appOne = solve(idx + one, low, high, zero, one, dp) % MOD;

        return dp[idx] = (isOne + appZero + appOne) % MOD;
    }
}