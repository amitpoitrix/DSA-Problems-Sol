/*
 * 1574. Shortest Subarray to be Removed to Make Array Sorted
 * Link: https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/description/?envType=daily-question&envId=2024-11-15
 * 
 * 
 * Approach: 
 * 
 * The approach here aims to find the length of the shortest subarray that can be removed to make the entire array 
 * sorted.
 * 
 * Identify Sorted Right Subarray: Starting from the end of the array, find the rightmost sorted subarray by moving pointer j left until the elements stop being in non-decreasing order.
 * 
 * Edge Case:
 * Already Sorted: If j reaches 0, the array is already sorted, so return 0.
 * 
 * Iterate with Two Pointers: 
 * Use two pointers, i (starting from the left) and j (where the right sorted portion begins), to find the smallest 
 * subarray that can be removed. Increment i as long as it maintains an increasing order. For each i, adjust j 
 * forward until arr[j] greater than equal to arr[i], ensuring we maintain sorted order if we keep elements 
 * from 0 to i and from j onward.
 * 
 * Track Minimum Removal: 
 * Calculate the length of elements between i and j to be removed and keep track of the minimum length across 
 * all valid (i, j) combinations.
 * 
 * This two-pointer approach optimizes the solution by minimizing the removed subarray length while preserving 
 * sorted order
 * 
 * Complexities:
 * Time: O(n)
 * Space: O(1)
 * 
 */

class Solution {
    public int findLengthOfShortestSubarray(int[] nums) {
        // Approach: Using two pointers
        // Step 1: First find the position of j -> idx whose previous is greater than jth element
        int n = nums.length;
        int j = n - 1;
        while(j > 0 && nums[j - 1] <= nums[j]) {
            j--;
        }

        // We've to intialise minLength to be equal to j because of 2 edge case scenario
        // 1st when all the elements are sorted than minlenght of subarray to be removed should be 0 and j also contains 0 at that time
        // 2nd when elements are sorted in reverse order than j will remain at last position which signifies we need to remove n-1 elements
        int minLength = j;

        // Step 2: Traverse till ith element is less than or equal to its next element and will simulatneously compute the minLength so far
        int i = 0;
        // In the condition we're using nums[i] >= nums[i - 1] instead of nums[i] <= nums[i+1] because first condition is ensuring array is sortted till current ith index
        while(i < j && (i == 0 || nums[i] >= nums[i - 1])) {
            // if j is not at its correct position as compare to i than we'll move j
            while(j < n && nums[i] > nums[j]) {
                j++;
            }

            // we're not checking if(nums[i] <= nums[j]) because there is this possibility that j might be equal to n (out of bound)
            minLength = Math.min(minLength, j - i - 1);

            i++;
        }   

        return minLength;
    }
}

// 0 1 2 3  4 5 6 7 8
// 1 2 3 10 4 2 3 5
//        i         j

// i = 0
// j = 5

// 1st
// Now we've to move j till we've sorted array
// while(nums[i] > nums[j])
// 2nd
// nums[i] <= nums[j]
// minLength = j - i - 1; = 3