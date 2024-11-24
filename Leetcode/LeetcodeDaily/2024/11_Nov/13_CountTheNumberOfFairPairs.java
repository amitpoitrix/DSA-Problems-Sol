import java.util.*;

/*
 * 2563. Count the Number of Fair Pairs
 * Link: https://leetcode.com/problems/count-the-number-of-fair-pairs/description/?envType=daily-question&envId=2024-11-13
 * 
 * Approach 1: BruteForce Approach (TLE)
 * Simple Simulation
 * 
 * Complexities:
 * Time: O(n^2)
 * Space: O(1)
 */

 class Solution1 {
    public long countFairPairs(int[] nums, int lower, int upper) {
        long count = 0;

        int n = nums.length;

        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                int sum = nums[i] + nums[j];

                if(sum >= lower && sum <= upper) {
                    count++;
                }
            }
        }

        return count;
    }
}


/*
 * Approach 2:
 * 
 * The approach involves sorting the nums array first to make pair searching easier. For each element nums[i],
 * we calculate two indices:
 * leftIdx using a lowerBound function to find the first index where elements are not less than lower - nums[i].
 * rightIdx using an upperBound function to find the first index where elements exceed upper - nums[i].
 * The difference between these indices, adjusted by i, gives the count of valid pairs (i, j) for the current i. 
 * Summing up these counts across all i provides the total number of fair pairs within the specified range. 
 * This approach leverages binary search for efficient pair counting.
 * 
 * Complexities:
 * Time: O(nlogn)
 * Space: O(1)
 */

 class Solution2 {
    public long countFairPairs(int[] nums, int lower, int upper) {
        // Using BinarySearch lower_bound & upper_bound
        // In order to count the no. of pairs whose sum is within the range [lower, upper] is nothing but 
        // finding the no. of pairs whose sum is less than lower (lets say x pairs) and no. of pairs whose 
        // sum is less than or equal to upper (lets say y pairs). Now the no. of pairs are (x - y) whose pair 
        // sum will be within the range [lower, upper]

        // Now for finding no. of pairs(x) whose sum is less than lower can be view as if we're at ith idx than 
        // we can just find no. of elements which are less than (lower - nums[i]) that can be achieve through 
        // lower_bound(i + 1, n - 1, target) where target is (lower - nums[i])

        // same goes with finding y no. of pairs i.e., no. of pairs whose sum is less than or equal to upper
        // can be view as no. of elements less than or equal to (upper - nums[i]) which can be achieve through 
        // upper_bound(i + 1, n - 1, target) where target is (upper - nums[i])

        // We can sort the array even though it is being mentioned in the question that i < j but it doesn't
        //  matter because either you do sum as nums[i] + nums[j] or nums[j] + nums[i]

        // Step 1: Sort the Array
        Arrays.sort(nums);

        // Step 2: Traverse over given array and find the lower_bound & upper_bound than find the no. of pairs
        int n = nums.length;

        long countPairs = 0;

        for(int i = 0; i < n; i++) {
            int idx = lowerBound(i + 1, n - 1, lower - nums[i], nums);
            int x = idx - 1 - i;

            // we're considering upper_bound because what if upper - nums[i] is 12 and thare is multiple 
            // occurence of 12 than we should consider the last position of 12 which will be given by upper_bound
            idx = upperBound(i + 1, n - 1, upper - nums[i], nums);
            int y = idx - 1 - i;

            countPairs += (y - x);
        }

        return countPairs;
    }

    private int lowerBound(int start, int end, int target, int[] nums) {
        int lowerBoundIdx = end + 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(nums[mid] >= target) {
                lowerBoundIdx = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return lowerBoundIdx;
    }

    private int upperBound(int start, int end, int target, int[] nums) {
        int upperBoundIdx = end + 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(nums[mid] > target) {
                upperBoundIdx = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return upperBoundIdx;
    }
}


/*
 * Approach 3: Using counting pairs equal to target after sorting using two pointers
 * 
 * Complexities:
 * Time: O(nlogn)
 * Space: O(1)
 */

 class Solution3 {
    public long countFairPairs(int[] nums, int lower, int upper) {
        // Approach 3: Using counting pairs equal to target after sorting using two pinters
        // Step 1: Sort the array
        Arrays.sort(nums);

        // Step 2: Difference btw no. of pairs of sum(upper) - sum(lower - 1)
        return solver(nums, upper) - solver(nums, lower - 1);
    }

    private long solver(int[] nums, int target) {
        int n = nums.length;

        int left = 0;
        int right = n - 1;

        long countPairs = 0;

        // As we won't pairs so we won't consider left <= right condition as 1 single element can't be treated 
        // as pair of elements
        while(left < right) {
            if(nums[left] + nums[right] <= target) {
                countPairs += (right - left);
                left++;
            } else {    
                right--;
            }
        }

        return countPairs;
    }
}