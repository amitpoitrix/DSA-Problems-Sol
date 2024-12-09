/*
 * 1760. Minimum Limit of Balls in a Bag
 * Link: https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/?envType=daily-question&envId=2024-12-07
 * 
 * 
 * Approach:
 * The problem is solved using binary search on the possible values of the maximum ball size (mid). The goal is to minimize 
 * the largest size of any ball after performing at most maxOperations splits.
 * 
 * Define the Search Range:
 * The smallest possible ball size is 1, and the largest is the maximum value in the nums array (max(nums)).
 * 
 * Binary Search:
 * For each midpoint (mid) in the range, check if it's possible to make all ball sizes ≤ mid using at most maxOperations.
 * 
 * Helper Method (isPossible):
 * For each ball, calculate the number of operations needed to reduce its size to ≤ mid.
 * If the total operations exceed maxOperations, mid is not feasible.
 * 
 * Update Search Range:
 * If mid is feasible, try smaller values (r = mid - 1) to minimize the result.
 * Otherwise, increase mid (l = mid + 1) to find a feasible solution.
 * 
 * Result:
 * The smallest feasible mid is the answer.
 * 
 * 
 * Complexity:
 * Time: O(nlogn)
 * Space: O(n)
 */

class Solution {
    public int minimumSize(int[] nums, int maxOperations) {
        // Using Binary Search as we've to minimise the maximum penalty possible
        int left = 1;

        int right = 0;
        for(int num: nums) {
            right = Math.max(right, num);
        }

        int result = right; // As of now right is having max penalty

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(isPossible(mid, nums, maxOperations)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }

    private boolean isPossible(int penalty, int[] nums, int maxOperations) {
        int countOperations = 0;

        for(int num: nums) {
            if(num % penalty == 0) {
                // In case of completely divisible by penalty we need to do -1 because it'll divide into 2 groups of equal
                // size which comprise to 1 operations
                countOperations += ((num / penalty) - 1);
            } else {
                countOperations += (num / penalty);
            }
        }

        return countOperations <= maxOperations;
    }
}