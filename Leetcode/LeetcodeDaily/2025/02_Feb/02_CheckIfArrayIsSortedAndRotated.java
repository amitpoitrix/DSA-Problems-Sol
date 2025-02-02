/**
 * 1752. Check if Array Is Sorted and Rotated
 * Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/?envType=daily-question&envId=2025-02-02
 * 
 * 
 * Approach 1: Bruteforce Approach
 * We simulate all possible rotations of the array and check if any of them are sorted.
 * Shift elements and verify if the order remains sorted.
 * Inefficient due to repeatedly checking all rotations.
 * 
 * Complexity:
 * Time: O(n^2)
 * Space: O(n)
 */

class Solution1 {
    public boolean check(int[] nums) {
        // Approach 1: Bruteforce Approach
        // We'll take a normal array called sorted and keep on forming at each iteration
        // So the idea is we don't know how many times the given array is already sorted so we run outer loop from 
        // r = 0 to n-1 and using position of r we'll form sorted array and check whether sorted[] actually becomes 
        // sorted or not
        
        int n = nums.length;

        int[] sorted = new int[n];

        for(int r = 0; r < n; r++) {
            int idx = 0;

            // this inner for loop will store elements from [r, n-1]
            for(int i = r; i < n; i++) {
                sorted[idx] = nums[i];
                idx++;
            }

            // Now below inner for loop will store from [0, r-1]
            for(int i = 0; i < r; i++) {
                sorted[idx] = nums[i];
                idx++;
            }

            // Now we'll check whether sorted[] actually becomes sorted or not
            boolean isSorted = true;

            for(int i = 0; i < n - 1; i++) {
                if(sorted[i] > sorted[i+1]) {
                    isSorted = false;
                    break;
                }
            }

            if(isSorted == true) {
                return true;
            }
        }

        return false;
    }
}


/**
 * Approach 2: Better Approach still Bruteforce
 * We sort the original array and check if any rotation matches the sorted array.
 * Iterate through all rotations and compare with the sorted array.
 * Avoids unnecessary sorting but still checks multiple possibilities.
 * 
 * Complexity:
 * Time: O(n^2)
 * Space: O(n)
 */

class Solution2 {
    public boolean check(int[] nums) {
        // Approach 2: Slightly Better but still bruteforce
        // As we don't know no. of rotation original array is sorted so we'll keep on checking how many times its 
        // been rotated from outer loop r = 0 to n-1 and than check in inner for loop we'll keep on checking already 
        // sorted element with nums[(i + r) % n] if all elements matches than return true else false;

        int n = nums.length;

        int[] sorted = nums.clone();
        Arrays.sort(sorted);

        // Outer loop that traverses for rotation from 0 to n-1
        for(int r = 0; r < n; r++) {
            boolean isSorted = true;

            for(int i = 0; i < n; i++) {
                if(sorted[i] != nums[(i + r) % n]) {
                    isSorted = false;
                    break;
                }
            }

            if(isSorted) {
                return true;
            }
        }

        return false;
    }
}


/**
 * Approach 3: Optimised Approach
 * Count the number of times elements are out of order.
 * If this count is at most 1, the array can be a rotated sorted array.
 * Efficient as it avoids unnecessary rotations.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution3 {
    public boolean check(int[] nums) {
        // Approach 3: Optimised Approach
        // So the idea is if array is sorted and rotated than there should only we 1 peak i.e., nums[i] > nums[i+1] 
        // and if its more than that than its not sorted 

        int n = nums.length;

        int peak = 0;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[(i+1) % n]) {
                peak++;
            }
        }

        return peak <= 1;
    }
}