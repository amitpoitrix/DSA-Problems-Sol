/**
 * 769. Max Chunks To Make Sorted
 * Link: https://leetcode.com/problems/max-chunks-to-make-sorted/description/?envType=daily-question&envId=2024-12-19
 * 
 * 
 * Approach 1: Using Prefix Maximum and Suffix Minimum
 * Compute the prefix maximum and suffix minimum arrays to track the maximum and minimum values up to and from 
 * each index, respectively.
 * Identify chunk boundaries where the suffix minimum of the next part is greater than the prefix maximum of the 
 * current part.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(n)
 */

// max_from_right < min_from_left

// 0 1 2 3 4
// 4 3 2 1 0

// 0 1 2 3 4
// 1 0 2 3 4

// count = 4

class Solution1 {
    public int maxChunksToSorted(int[] arr) {
        // Approach 1: Using max from left side of subarray & min from right
        // side of the subarray
        int n = arr.length;
        
        int[] prefixMax = new int[n];
        prefixMax[0] = arr[0];
        for(int i = 1; i < n; i++) {
            prefixMax[i] = arr[i] > prefixMax[i-1] ? arr[i]: prefixMax[i-1];
        }

        int[] suffixMin = new int[n];
        suffixMin[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--) {
            suffixMin[i] = arr[i] < suffixMin[i+1] ? arr[i]: suffixMin[i+1];
        }        

        int maxChunks = 1;
        for(int i = 1; i < n; i++) {
            if(prefixMax[i-1] < suffixMin[i]) {
                maxChunks++;
            }
        }

        return maxChunks;
    }
}


/**
 * Approach 2: Using Cumulative Sum
 * Maintain two cumulative sums: one for the array values and another for the indices.
 * Identify chunk boundaries where the cumulative sum of array values equals the cumulative sum of indices.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

// 0 1 2 3 4
// 4 3 2 1 0

// 0 1 3 6  10
// 4 7 9 10 10

// ------------

// 0 1 2 3 4
// 1 0 2 3 4

// 0 1 3 6 10
// 1 1 3 6 10

class Solution2 {
    public int maxChunksToSorted(int[] arr) {
        int n = arr.length;

        // No need to maintain array we can use just variables
        int idxSum = 0;
        int cSum = 0;

        int maxChunks = 0;

        for(int i = 0; i < n; i++) {
            idxSum += i;
            cSum += arr[i];

            if(idxSum == cSum) {
                maxChunks++;
            }
        }

        return maxChunks;
    }
}


/**
 * Approach 3: Using Maximum Check
 * Track the maximum value encountered so far while iterating through the array.
 * Identify chunk boundaries where the maximum value equals the current index, indicating that all elements up to 
 * that point are in their correct positions.
 */

// 0 1 2 3 4
// 4 3 2 1 0
// 4 4 4 4 4

// 0 1 2 3 4
// 1 0 2 3 4
// 1 1 2 3 4

class Solution3 {
    public int maxChunksToSorted(int[] arr) {
        // Approach 3:
        int n = arr.length;

        int maxElement = 0;
        int maxChunks = 0;

        for(int i = 0; i < n; i++) {
            maxElement = Math.max(maxElement, arr[i]);

            if(maxElement == i) {
                maxChunks++;
            }
        }

        return maxChunks;
    }
}