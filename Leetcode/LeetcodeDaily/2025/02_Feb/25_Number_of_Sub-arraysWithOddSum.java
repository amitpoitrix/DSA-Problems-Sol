/**
 * 1524. Number of Sub-arrays With Odd Sum
 * Link: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/?envType=daily-question&envId=2025-02-25
 * 
 * 
 * Approach:
 * The idea is to use a prefix sum to track cumulative sums efficiently. 
 * Instead of checking each subarray individually, we count how many prefix sums are odd or even.
 * 
 * If the current prefix sum is even, the number of valid subarrays is equal to the count of odd prefix sums encountered so far.
 * If the prefix sum is odd, the valid subarrays count is derived from the even prefix sums seen previously.
 * This approach helps us count odd-sum subarrays efficiently in O(n) time using additional space for prefix sums.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

// Ex: 1
//   0 1 2
//   1 3 5
// 0 1 4 9
//         i

// evenCount = 1 + 1
// oddCount = 1 + 1

// result = 1 + 1 + 2 = 4

class Solution {
    private int mod = (int)(1e9 + 7);

    public int numOfSubarrays(int[] arr) {
        // Approach 2: As subarray is there so using Prefix
        int n = arr.length;

        // So the approach is to count the no. of odd & even prefixSum and whenever encounter current
        // prefixSum as odd than add evenCount to totalCount else when current prefixSum is even than add oddcount
        // to totalCount

        int totalCount = 0;

        int evenCount = 1;  // Due to initial value of prefixSum i.e., 0
        int oddCount = 0;
        
        int prefixSum = 0;

        for(int num: arr) {
            prefixSum += num;

            if(prefixSum % 2 == 0) {
                // current prefixSum is even
                totalCount = (totalCount + oddCount) % mod;
                evenCount++;
            } else {
                // current prefixSum is odd
                totalCount = (totalCount + evenCount) % mod;
                oddCount++;
            }
        }

        return totalCount % mod;
    }
}