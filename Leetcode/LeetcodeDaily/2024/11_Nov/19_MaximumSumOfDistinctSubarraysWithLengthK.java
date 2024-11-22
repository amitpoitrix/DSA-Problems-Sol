/*
 * 2461. Maximum Sum of Distinct Subarrays With Length K
 * Link: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/?envType=daily-question&envId=2024-11-19
 * 
 * 
 * The solution uses the sliding window technique combined with a HashSet to find the maximum sum of a subarray 
 * of size k while ensuring that all elements in the subarray are unique.
 * 
 * Two Pointers:
 * Use two pointers i (start) and j (end) to define the current window.
 * 
 * HashSet for Uniqueness:
 * Maintain a HashSet to track unique elements in the current window.
 * 
 * Window Expansion:
 * Incrementally add nums[j] to the current window.
 * If nums[j] already exists in the HashSet, shrink the window from the left (i++) until the duplicate is removed.
 * 
 * Window Size Check:
 * When the window size equals k, calculate the sum and update the maximum result.
 * Then shrink the window from the left to explore other possibilities.
 * 
 * Sliding Mechanism:
 * Keep sliding the window until j traverses the entire array.
 * This approach ensures an O(n) time complexity due to the efficient sliding of the window and HashSet operations.
 */

import java.util.*;

class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        int n = nums.length;

        long result = 0;
        long currentSum = 0;

        int left = 0;
        int right = 0;

        HashSet<Integer> set = new HashSet<>();

        while(right < n) {
            int currentElement = nums[right];

            // If window is invalid than we'll make it valid by moving left pointer trowards right
            while(set.contains(currentElement) && left < n) {
                int removeElement = nums[left];

                currentSum -= removeElement;
                set.remove(removeElement);

                left++;
            }

            // Now its valid
            currentSum += currentElement;
            set.add(currentElement);        

            // Now check if window is of size k
            if(right - left + 1 == k) {
                result = Math.max(result, currentSum);
                
                // After we got the result we need to move left pointer
                currentSum -= nums[left];
                set.remove(nums[left]);
                left++;
            }

            right++;
        }

        return result;
    }
}