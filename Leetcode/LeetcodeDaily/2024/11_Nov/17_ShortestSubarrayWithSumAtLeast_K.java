import java.util.*;

/*
 * 209. Minimum Size Subarray Sum
 * Similar Question: https://leetcode.com/problems/minimum-size-subarray-sum/description/
 * Only the difference is this ques only have nums which belongs to +ve integers
 * 
 * Approach: Using Sliding Window
 */

 class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length;

        int left = 0;
        int right = 0;

        int currentSum = 0;
        int minLength = Integer.MAX_VALUE;

        while(right < n) {
            currentSum += nums[right];

            while(currentSum >= target) {
                minLength = Math.min(minLength, right - left + 1);

                // for future possibility
                currentSum -= nums[left];
                left++;
            }

            right++;
        }

        return minLength == Integer.MAX_VALUE ? 0: minLength;
    }
}


/**
 * 0 1 2 3 4 5
 * 2 3 1 2 4 3
 *         i
 *             j
 * 
 * target = 7
 * 
 * currentSum = 7
 * minLength = j - i + 1 = 2
 * 
 */

 
 /* 
 * 862. Shortest Subarray with Sum at Least K
 * Link: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/submissions/1459496952/?envType=daily-question&envId=2024-11-17
 * 
 * 
 * Approach: 
 * 
 * The approach to solving the Shortest Subarray with Sum at Least K problem uses a combination of cumulative sum 
 * and a monotonic deque to efficiently find the smallest subarray with a sum greater than or equal to K.
 * 
 * Steps:
 * Cumulative Sum: Calculate the cumulative sum of the array. 
 * cumulativeSum[i] stores the sum of elements from the start of the array to index i.
 * Monotonic Deque: Use a deque to keep track of indices of the cumulative sum array in a way that maintains 
 * increasing order of cumulative sums. This helps identify subarrays with sums greater than or equal to K.
 * 
 * Checking for valid subarrays:
 * For each new element, check if the difference between the current cumulative sum and any previously seen 
 * cumulative sum is at least K. If so, update the result (the length of the subarray).
 * 
 * Maintain the deque such that only indices with relevant cumulative sums are kept, ensuring the deque remains 
 * in increasing order of cumulative sums.
 * 
 * Return Result: After processing all elements, the smallest valid subarray length is returned. If no such 
 * subarray is found, return -1.
 */

class Solution1 {
    public int shortestSubarray(int[] nums, int k) {
        // Approach: As its look like sliding window ques (due to subarray and k)
        // but its not because of -ve elements
        // So for that we gonna use Monotonic Deqeu as we need to maintain Monotonic
        // increasing order in order to get minLength of subarray
        int n = nums.length;

        int minLength = (int)1e9;

        // Step 1: Maintain a cumulativeSum[] of size n 
        long[] cumulativeSum = new long[n];

        // Step 2: Create a Deque to store idx of cumulativeSum so far in Monotonic
        // increasing order in order to get the minLength
        Deque<Integer> dq = new ArrayDeque<>();

        // Step 3: Now while traversing at each array do the following
        for(int i = 0; i < n; i++) {
            // (i) First compute cumulativeSum till jth idx
            if(i == 0) {
                cumulativeSum[i] = nums[i];
            } else {
                cumulativeSum[i] = cumulativeSum[i-1] + nums[i];
            }

            // (ii) Check if its greater than k(target) if yes than store its length if
            // its minimum
            if(cumulativeSum[i] >= k) {
                minLength = Math.min(minLength, i + 1); // i - j + 1 so here j = 0 so i + 1
            }

            // (iii) Now check for smaller subarray if there sum is greater than k using
            // using cumulativeSum
            while(!dq.isEmpty() && cumulativeSum[i] - cumulativeSum[dq.peekFirst()] >= k) {
                minLength = Math.min(minLength, i - dq.peekFirst());

                // Now removing idx from front of deque for further possibility of getting smallest subarray
                dq.pollFirst();
            }

            // (iv) Now we gonna add current idx j in deque but before that make sure deque
            // is maintaining monotonic stack order 
            while(!dq.isEmpty() && cumulativeSum[i] <= cumulativeSum[dq.peekLast()]) {
                dq.pollLast();
            }

            dq.offerLast(i);
        }

        return minLength == (int)1e9 ? -1: minLength;
    }
}

// 0   1. 2. 3. 4
// 84 -37 37 40 95 
// k = 167

// cumulativeSum[]
// 84 47 84 124 219

// Deque
// 1. 2 3 4 