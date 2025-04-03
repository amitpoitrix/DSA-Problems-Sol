/**
 * 2874. Maximum Value of an Ordered Triplet II
 * Link: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/description/?envType=daily-question&envId=2025-04-03
 * 
 * 
 * Approach 2: Using Space
 * 
 * As we've to maximise the triplet so we'll try to maintain nums[i] & nums[k] as max as possible for which we'll
 * maintain 2 arrays i.e., leftMax[] for arr[i] & rightMax[] for arr[k]
 * And than we'll traverse our input array with j pointer which will represent arr[j]
 * 
 * Complexity:
 * Time: O(n)
 * Sapce: O(n)
 */

class Solution2 {
    public long maximumTripletValue(int[] nums) {
        // Approach 2: Using Space
        int n = nums.length;

        int[] leftMax = new int[n];
        for(int i = 1; i < n; i++) {
            leftMax[i] = Math.max(leftMax[i-1], nums[i-1]);
        }

        int[] rightMax = new int[n];
        for(int k = n - 2; k >= 0; k--) {
            rightMax[k] = Math.max(rightMax[k+1], nums[k+1]);
        }

        long result = 0;
        for(int j = 0; j < n; j++) {
            result = Math.max(result, (long)(leftMax[j] - nums[j]) * rightMax[j]);
        }

        return result;
    }
}


/**
 * Approach 3: Without Space
 * 
 * As we've to maximise the triplet so we'll try to maintain nums[i] & nums[k] as max as possible without any space
 * After each traversal before moving to next element in next iteration we'll first compute maxDiff = maxi - nums[k] 
 * and than after this we'll maintaing maxi as nums[k] if its maximum
 * And than we'll traverse our input array with k pointer which will represent arr[k]
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution3 {
    public long maximumTripletValue(int[] nums) {
        // Approach 3: Without any space
        int n = nums.length;

        long result = 0;
        long maxi = 0;

        long maxDiff = 0;

        for(int k = 0; k < n; k++) {
            // Step 1: First compute triplet
            result = Math.max(result, maxDiff * nums[k]);

            // Step 2: Now compute maxDiff for next iteration
            maxDiff = Math.max(maxDiff, maxi - nums[k]);

            // Step 3: Now maintain maxi value
            maxi = Math.max(maxi, nums[k]);
        }

        return result;
    }
}