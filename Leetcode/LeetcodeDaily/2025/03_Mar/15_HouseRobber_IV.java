/**
 * 2560. House Robber IV
 * Link: https://leetcode.com/problems/house-robber-iv/description/?envType=daily-question&envId=2025-03-15
 * 
 * Approach 1: Using Recursion
 * This approach explores all possible ways to rob exactly k houses while skipping adjacent ones. 
 * It recursively decides whether to take or skip a house.
 * 
 * Complexity:
 * Time: O(2^(n * k))
 * Space: O(n)
 */
class Solution1 {
    public int minCapability(int[] nums, int k) {
        // Approach 1: Using Recursion
        return solve(0, nums, k);
    }

    private int solve(int idx, int[] nums, int k) {
        // Base Case
        // 1. When k is 0
        if(k == 0) {
            return 0;
        }

        // Order of base case matters - when idx is out of bound
        if(idx >= nums.length) {
            // Invalid path or returning invalid value so as to not to consider this path
            return Integer.MAX_VALUE;
        }

        // Recursive Case
        // As we've to get max capability out of all houses
        int take = Math.max(nums[idx], solve(idx + 2, nums, k - 1));

        int notTake = solve(idx + 1, nums, k);

        // As we've to minimize the capability among all possible ways
        return Math.min(take, notTake);
    }
}


/**
 * Approach 2: Using Recursion + Memoization
 * Using memoization to avoid redundant calculations.
 * 
 * Complexity:
 * Time: O(n * k)
 * Space: O(n * k)
 */
class Solution2 {
    public int minCapability(int[] nums, int k) {
        // Approach 2: Using Recursion + Memoization
        int[][] dp = new int[nums.length + 1][k + 1];
        for(int[] row: dp) {
            Arrays.fill(row, -1);
        }

        return solve(0, nums, k, dp);
    }

    private int solve(int idx, int[] nums, int k, int[][] dp) {
        // Base Case
        // 1. When k is 0
        if(k == 0) {
            return 0;
        }

        // Order of base case matters - when idx is out of bound
        if(idx >= nums.length) {
            // Invalid path or returning invalid value so as to not to consider this path
            return Integer.MAX_VALUE;
        }

        if(dp[idx][k] != -1) {
            return dp[idx][k];
        }

        // Recursive Case
        // As we've to get max capability out of all houses
        int take = Math.max(nums[idx], solve(idx + 2, nums, k - 1, dp));

        int notTake = solve(idx + 1, nums, k, dp);

        // As we've to minimize the capability among all possible ways
        return dp[idx][k] = Math.min(take, notTake);
    }
}


/**
 * Approach 3: Using Binary Search on Answer
 * Instead of directly selecting houses, this approach uses binary search on the minimum capability required to rob 
 * k houses. 
 * It checks if it's possible to rob at most k houses with a given capability and adjusts the search range accordingly.
 * 
 * Complexity:
 * Time: O(nlogn)
 * Space: O(1)
 */

class Solution3 {
    public int minCapability(int[] nums, int k) {
        // Approach 3: using Binary Search on Answers(here capability)
        int n = nums.length;

        int left = Integer.MAX_VALUE;   // should have min value
        int right = Integer.MIN_VALUE;  // should have max value

        for(int num: nums) {
            left = Math.min(left, num);
            right = Math.max(right, num);
        }

        int minCapability = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(isPossible(mid, nums, k)) {
                minCapability = mid;
                right = mid - 1;    // As we want as min as possible
            } else {
                left = mid + 1;
            }
        }

        return minCapability;
    }

    private boolean isPossible(int midCapability, int[] nums, int k) {
        int houseCount = 0;

        for(int i = 0; i < nums.length; i++) {
            // Note: Here no need to check like whether we choose current house to steal or not as in the ques its already given that robber can steal from atleast k houses
            if(nums[i] <= midCapability) {
                houseCount++;
                i++;    // We steal from current house so directly moving (i + 2)th house
            }
        }

        return houseCount >= k;
    }
}