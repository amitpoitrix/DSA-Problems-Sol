/**
 * 689. Maximum Sum of 3 Non-Overlapping Subarrays
 * Link: https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/?envType=daily-question&envId=2024-12-28
 * 
 * Complexity:
 * Time: O(n); Each state is computed at most once due to memoization, so the total number of subproblems is O((n - k + 1) * 4)
 * Space: O(n); The dp table has dimensions (n - k + 1) x 4
 */


class Solution {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        // Approach 2: Using DP - Memoization
        // Step 1: First compute subarray sum till k size for each ith idx till size (n - k + 1)
        int n = nums.length;

        int[] preSubarraySum = new int[n - k + 1];

        int i = 0;
        int j = 0;
        int windowSum = 0;

        while(j < n) {
            windowSum += nums[j];

            // when window size matches than add the result and move left pointer i.e., i
            if(j - i + 1 == k) {
                preSubarraySum[i] = windowSum;

                // Moving i pointer
                windowSum -= nums[i];
                i++;
            }

            j++;
        }

        // Step 2: Now Recursively computing max subarray sum idx 
        int[] result = new int[3];

        // Step 3: We gonna memoize helper() recursive function
        int[][] dp = new int[n - k + 1][4];
        for(int[] row: dp) {
            Arrays.fill(row, -1);
        }

        solve(0, 3, k, preSubarraySum, result, dp);

        return result;
    }

    private void solve(int idx, int count, int k, int[] preSubarraySum, int[] result, int[][] dp) {
        // Base Case
        if(count == 0 || idx >= preSubarraySum.length) {
            return;
        }

        // Recursive case
        int takeIdx = preSubarraySum[idx] + helper(idx + k, count - 1, k, preSubarraySum, dp);
        int nonTakeIdx = helper(idx + 1, count, k, preSubarraySum, dp);

        if(takeIdx >= nonTakeIdx) {
            result[3 - count] = idx;

            solve(idx + k, count - 1, k, preSubarraySum, result, dp);
        } else {
            solve(idx + 1, count, k, preSubarraySum, result, dp);
        }
    }

    private int helper(int idx, int count, int k, int[] preSubarraySum, int[][] dp) {
        // Base Case
        if(count == 0 || idx >= preSubarraySum.length) {
            return 0;
        }

        if(dp[idx][count] != -1) {
            return dp[idx][count];
        }

        // Recursive Case
        int take = preSubarraySum[idx] + helper(idx + k, count - 1, k, preSubarraySum, dp);
        int nonTake = helper(idx + 1, count, k, preSubarraySum, dp);

        return dp[idx][count] = Math.max(take, nonTake);
    }
}