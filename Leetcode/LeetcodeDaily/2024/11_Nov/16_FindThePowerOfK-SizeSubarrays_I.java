import java.util.*;

/*
 * Link: https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/?envType=daily-question&envId=2024-11-16
 * 
 * 
 * Approach 1: BruteForce Approach
 * 
 * We'll take 2 pointers (i & j) and travel till (n-k+1) and keep on checking whether subarrays [i, j] 
 * are consecutive and is in increasing order or not
 */

class Solution1 {
    public int[] resultsArray(int[] nums, int k) {
        // Approach: Brute Force Approach
        
        // Step 1: Have a resultant array of size (n - k + 1) and initilise it to -1
        int n = nums.length;

        int[] result = new int[n - k + 1];
        Arrays.fill(result, -1);

        // Step 2: We'll take 2 pointers (i & j) and travel till n-k+1 and keep on 
        // checking whether subarrays [i, j] are consecutive and in increasing order
        // or not
        for(int i = 0; i < n - k + 1; i++) {
            if(isConsecutive(i, i + k - 1, nums)) {
                result[i] = nums[i + k - 1];
            }
        }

        return result;
    }

    // This function check whether given subarray range [i, j] is consecutive and in ascending order or not
    private boolean isConsecutive(int i, int j, int[] nums) {
        for(int k = i + 1; k <= j; k++) {
            if(nums[k - 1] + 1 != nums[k]) {
                return false;
            }
        }

        return true;
    }
}


/*
 * Approach 2: Optimised Approach - Using Sliding Window
 * 
 * The solution identifies the last element of every subarray of size k that contains strictly consecutive 
 * integers in an input array nums. It uses a sliding window technique:
 * 
 * Initialization:
 * Create a result array of size (n - k + 1) initialized with -1.
 * Use a count variable to track the length of the current sequence of consecutive integers.
 * 
 * Preprocess the First Window:
 * Iterate through the first k elements and check if each element is one more than the previous one.
 * Update count accordingly and mark the result if the window contains exactly k consecutive elements.
 * 
 * Sliding Window:
 * Slide the window by advancing pointers i (start) and j (end).
 * For each new element, check if it continues the consecutive sequence.
 * Update the result array at position i if the sequence meets the condition.
 * 
 * Return the Result:
 * Return the result array, where valid positions have the last element of a consecutive sequence, and 
 * invalid ones remain -1.
 */


class Solution2 {
    public int[] resultsArray(int[] nums, int k) {
        // Approach: Optimised Approach - Using Sliding Window
        
        // Step 1: Have a resultant array of size (n - k + 1) and initilise it to -1
        int n = nums.length;

        int[] result = new int[n - k + 1];
        Arrays.fill(result, -1);

        // Step 2: Here we'll keep track of no. of consecutive elements so far. First we'll compute consecutive 
        // elements for 1st window & and if consecutive elements condition doesn't satisfy than we'll reset 
        // our counter to 1 and if its equals to k than we'll assign power array to 0th idx of resultant 
        // array as nums[k-1]
        int consecutiveCounter = 1;

        for(int i = 1; i < k; i++) {
            if(nums[i - 1] + 1 == nums[i]) {
                consecutiveCounter++;
            } else {
                consecutiveCounter = 1;
            }
        }

        if(consecutiveCounter == k) {
            result[0] = nums[k - 1];
        }

        // Step 3: After computing it for first window we'll start computing power array for rest of
        // the windows 
        int left = 1;   // As first window has already been computed
        int right = k;

        while(right < n) {
            if(nums[right - 1] + 1 == nums[right]) {
                consecutiveCounter++;
            } else {
                consecutiveCounter = 1;
            }

            if(consecutiveCounter >= k) {
                result[left] = nums[right];
            }

            left++;
            right++;
        }

        return result;
    }
}


/*
 * Approach 3: Optimised Approach - using Monotonic Deque
 * 
 * The approach uses a monotonic deque to efficiently process the array in a sliding window manner. Here's a summary:
 * 
 * Deque Properties:
 * The deque stores consecutive numbers within the window in a monotonic order.
 * If a new element is not consecutive to the last deque element, the deque is cleared.
 * 
 * Result Computation:
 * If the deque contains exactly k elements at the end of a window, the last element (due to the monotonic property) 
 * is added to the result.
 * Otherwise, -1 is added if the deque size is less than k.
 * 
 * Efficiency: By using a deque to store and update window elements, the solution ensures that each element is 
 * added and removed at most once, leading to an O(n) time complexity.
 */

 class Solution3 {
    public int[] resultsArray(int[] nums, int k) {
        // Approach: Optimised Approach - Using Monotonic Deque
        
        // Step 1: Have a resultant array of size (n - k + 1) and initilise it to -1
        int n = nums.length;

        int[] result = new int[n - k + 1];
        Arrays.fill(result, -1);

        Deque<Integer> dq = new ArrayDeque<>();
        
        // Step 2: First preprocess for first window
        for(int i = 0; i < k; i++) {
            if(!dq.isEmpty() && dq.peekLast() + 1 != nums[i]) {
                dq.clear();
            }

            dq.offerLast(nums[i]);
        }

        if(dq.size() == k) {
            result[0] = nums[k - 1];
        }

        // Step 3: As first window has already been processed so both pointers will start as follows
        int left = 1;
        int right = k;

        while(right < n) {
            if(!dq.isEmpty() && dq.peekLast() + 1 != nums[right]) {
                dq.clear();
            }
            
            dq.offerLast(nums[right]);

            if(dq.size() >= k) {
                result[left] = nums[right]; // or dq.peekLast();
            }

            left++;
            right++;
        }

        return result;
    }
}