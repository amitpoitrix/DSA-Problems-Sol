/**
 * 2551. Put Marbles in Bags
 * Link: https://leetcode.com/problems/put-marbles-in-bags/description/?envType=daily-question&envId=2025-03-31
 * 
 * Similar Questions:
 * https://leetcode.com/problems/array-partition/ - Yahoo | Amazon | Adobe
 * https://leetcode.com/problems/find-the-value-of-the-partition/
 * https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/ - Google | Adobe | eBay
 * 
 * Approach: 
 * Using Pattern: Sorting + Partition + Pairing(Greedy)
 * 
 * Initialize n as the size of the weights array.
 * Create a array pairWeights of size n - 1 to store sums of adjacent pairs.
 * Iterate over weights:
    * For each pair of adjacent elements, store their sum in pairWeights.
 * Sort the pairWeights array in ascending order.
 * Initialize answer as 0 to store the difference between max and min sums.
 * Iterate over the first and last k - 1 elements of pairWeights:
    * Add the difference between the largest k - 1 sums and smallest k - 1 sums to answer.
 * Return answer as the result.
 * 
 * Complexity:
 * Time: O(nlogn)
 * Space: O(n)
 */

class Solution {
    public long putMarbles(int[] weights, int k) {
        // Approach: Sorting + Partition + Pairing
        int n = weights.length;

        long[] pairSum = new long[n - 1];

        for(int i = 0; i < n - 1; i++) {
            pairSum[i] = (long)weights[i] + 1L + weights[i + 1];
        }

        Arrays.sort(pairSum);

        long min = 0;
        long max = 0;
        for(int i = 0; i < k - 1; i++) {
            min += pairSum[i];

            max += pairSum[n - 2 - i];
        }

        return max - min;
    }
}