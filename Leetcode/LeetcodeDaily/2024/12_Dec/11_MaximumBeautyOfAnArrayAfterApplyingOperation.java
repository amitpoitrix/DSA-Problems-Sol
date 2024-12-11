/**
 * 2779. Maximum Beauty of an Array After Applying Operation
 * Link: https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/?envType=daily-question&envId=2024-12-11
 * 
 * 
 * Approach 1: Sorting + Converting to Intervals and Using Queue
 * 
 * Idea: Convert each number in the array to a range [num - k, num + k] and determine the maximum overlapping ranges.
 * 
 * Steps:
 * sort the given array first and than Generate ranges
 * Use a queue to track overlapping ranges dynamically.
 * Update the maximum count of overlapping intervals
 */

class Solution1 {
    public int maximumBeauty(int[] nums, int k) {
        int n = nums.length;

        Arrays.sort(nums);

        int maxLength = 0;
        Queue<Pair> queue = new LinkedList<>();

        for(int num: nums) {
            Pair p = new Pair(num - k, num + k);

            if(queue.isEmpty()) {
                queue.offer(p);
            } else {
                Pair startPair = queue.peek();
                while(!queue.isEmpty() && startPair.second < p.first) {
                    queue.poll();
                    startPair = queue.peek();
                }

                queue.offer(p);
            }

            maxLength = Math.max(maxLength, queue.size());
        }

        return maxLength;
    }

    static class Pair {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}

// Optimised Syntax - Instead of maintaining Pair we're just maintaining queue of (nums + k)
class Solution2 {
    public int maximumBeauty(int[] nums, int k) {
        int n = nums.length;

        Arrays.sort(nums);

        int maxLength = 0;
        Queue<Integer> queue = new LinkedList<>();

        for(int num: nums) {
            while(!queue.isEmpty() && queue.peek() < num - k) {
                queue.poll();
            }

            queue.offer(num + k);

            maxLength = Math.max(maxLength, queue.size());
        }

        return maxLength;
    }
}


/**
 * Approach 2: Sorting and Binary Search
 * 
 * Idea: For each number, find the farthest number within a valid range [num, num + (2 * k)] using binary search.
 * 
 * Steps:
 * Sort the array.
 * For each number, use a binary search to find the upper bound of the valid range.
 * Compute the size of the range and update the maximum.
 * 
 * Complexity:
 * Time: O(nlogn) (sorting and binary search).
 * Space: O(1) (in-place operations).
 */

class Solution3 {
    public int maximumBeauty(int[] nums, int k) {
        int n = nums.length;

        Arrays.sort(nums);

        int maxLength = 0;

        for(int i = 0; i < n; i++) {
            maxLength = Math.max(maxLength, binarySearch(i, nums, k) - i + 1);
        }

        return maxLength;
    }

    // finding farthest idx (y) for given idx (x) using binary search
    private int binarySearch(int idx, int[] nums, int k) {
        int left = 0;
        int right = nums.length - 1;

        int result = 0;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] <= nums[idx] + 2 * k) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
}


/**
 * Approach 3: Using Sorting + Sliding Window
 * 
 * Idea: Use two pointers to maintain a sliding window of numbers that fit within the range [nums[i],nums[i]+2×k].
 * 
 * Steps:
 * Sort the array.
 * Use two pointers to expand and shrink the window dynamically.
 * Track the maximum window size.
 */

class Solution {
    public int maximumBeauty(int[] nums, int k) {
        // Using Sorting + Sliding Window
        int n = nums.length;

        Arrays.sort(nums);

        int maxLength = 0;

        int i = 0;
        int j = 0;
        while(i < n) {
            while(j < n && nums[j] <= nums[i] + 2 * k) {
                j++;
            }

            maxLength = Math.max(maxLength, j - i);
            i++;
        }

        return maxLength;
    }
}