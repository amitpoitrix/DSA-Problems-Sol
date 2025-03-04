/**
 * 2161. Partition Array According to Given Pivot
 * Link: https://leetcode.com/problems/partition-array-according-to-given-pivot/description/?envType=daily-question&envId=2025-03-03
 * 
 * 
 * Approach 1: Using Extra Space
 * The idea is to divide elements into three separate lists based on their relation to the pivot—less than, 
 * equal to, and greater than. 
 * Then, concatenate them to form the final result.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(n)
 */

class Solution1 {
    public int[] pivotArray(int[] nums, int pivot) {
        // Approach 1: Using 3 arrays
        int n = nums.length;

        List<Integer> lessThan = new ArrayList<>();
        List<Integer> equalTo = new ArrayList<>();
        List<Integer> greaterThan = new ArrayList<>();

        for(int num: nums) {
            if(num < pivot) {
                lessThan.add(num);
            } else if(num > pivot) {
                greaterThan.add(num);
            } else {
                equalTo.add(num);
            }
        }

        int[] result = new int[n];
        int k = 0;  // pointer for kth element

        int i = 0;
        while(i < lessThan.size()){
            result[k] = lessThan.get(i);
            k++;
            i++;
        }

        i = 0;
        while(i < equalTo.size()) {
            result[k] = equalTo.get(i);
            k++;
            i++;
        }

        i = 0;
        while(i < greaterThan.size()) {
            result[k] = greaterThan.get(i);
            k++;
            i++;
        }

        return result;
    }
}


/**
 * Approach 2: Using Pointers Only
 * Instead of using separate lists, count the occurrences of elements less than and equal to the pivot to determine
 * their positions. 
 * Then, place them directly in the result array while iterating through nums.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(n)
 */
class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        // Approach 2: Using just 1 Array
        int n = nums.length;
        int[] result = new int[n];

        int lessThanCount = 0;  // for getting the starting pointer for filling the pivot element in resultant array
        int equalToCount = 0;   // for getting the starting pointer for filling the greater than pivot element array

        for(int i = 0; i < n; i++) {
            if(nums[i] < pivot) {
                lessThanCount++;
            } else if(nums[i] == pivot) {
                equalToCount++;
            }
        }

        int i = 0;
        int j = lessThanCount;
        int k = lessThanCount + equalToCount;

        for(int x = 0; x < n; x++) {
            if(nums[x] < pivot) {
                result[i] = nums[x];
                i++;
            } else if(nums[x] == pivot) {
                result[j] = nums[x];
                j++;
            } else {
                result[k] = nums[x];
                k++;
            }
        }

        return result;
    }
}


/**
 * Approach 3: Two-Pointer Approach
 * Utilize two pointers—one moving from the left to collect smaller values and another from the right to collect 
 * larger values. 
 * Finally, fill the remaining middle section with the pivot.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(n)
 */
class Solutio3 {
    public int[] pivotArray(int[] nums, int pivot) {
        // Approach 3: Using just 1 Array
        int n = nums.length;
        int[] result = new int[n];

        // pointer to traverse over original given array
        int i = 0;
        int j = n - 1;

        // pointers to traverse over result[] to fill it
        int x = 0;  
        int y = n - 1;
        while(i < n && j >= 0) {
            if(nums[i] < pivot) {
                result[x] = nums[i];
                x++;
            }
            
            if(nums[j] > pivot) {
                result[y] = nums[j];
                y--;
            }

            i++;
            j--;
        }

        while(x <= y) {
            result[x] = pivot;
            x++;
        }

        return result;
    }
}