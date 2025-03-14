/**
 * 2529. Maximum Count of Positive Integer and Negative Integer
 * Link: https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/description/?envType=daily-question&envId=2025-03-12
 * 
 * Approach 1: Bruteforce Approach
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution1 {
    public int maximumCount(int[] nums) {
        int n = nums.length;

        int pos = 0;
        int neg = 0;

        for(int num: nums) {
            if(num > 0) {
                pos++;
            } else if(num < 0) {
                neg++;
            }
        }

        return Math.max(pos, neg);
    }
}


/**
 * Approach 2: Using Streams in Java
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution2 {
    public int maximumCount(int[] nums) {
        // Approach 2: Using Streams in Java
        // As count() gives result in long bydefault so typecasting it to (int)
        int pos = (int)Arrays.stream(nums).filter(num -> num > 0).count();

        int neg = (int)Arrays.stream(nums).filter(num -> num < 0).count();

        return Math.max(pos, neg);
    }
}


/**
 * Approach 3: Using Streams in Java
 * 
 * Using lower_bound approach of binary search to find first 0 idx which will give count of -ve no.
 * And (nums.length - first positive integer idx) will give count of +ve no.
 * 
 * Complexity:
 * Time: O(logn)
 * Space: O(1)
 */

class Solution3 {
    public int maximumCount(int[] nums) {
        // Approach 2: Using Binary Search
        int n = nums.length;

        // Using lower_bound in binary search

        // And (n - firstPosIntIdx) will give count of +ve no.'s
        int firstPosIntIdx = lowerBoundForPos(nums);

        // firstZeroIdx will give count of -ve numbers
        int firstZeroIdx = lowerBoundForZero(nums);

        return Math.max(firstZeroIdx, n - firstPosIntIdx);
    }

    private int lowerBoundForZero(int[] nums) {
        int left = 0;
        int right = nums.length - 1;

        // Note: Always assign it as n
        int firstZeroIdx = nums.length;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] >= 0) {
                firstZeroIdx = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return firstZeroIdx;
    }

    private int lowerBoundForPos(int[] nums) {
        int left = 0;
        int right = nums.length - 1;

        // Note: Always assign it as n
        int firstPosIntIdx = nums.length;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] > 0) {
                firstPosIntIdx = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return firstPosIntIdx;
    }
}