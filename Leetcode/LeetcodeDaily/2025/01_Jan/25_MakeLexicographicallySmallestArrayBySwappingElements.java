/**
 * 2948. Make Lexicographically Smallest Array by Swapping Elements
 * Link: https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/?envType=daily-question&envId=2025-01-25
 * 
 * 
 * Approach 1: Bruteforce Approach
 * Thought Process and Intuition: The brute force approach revolves around iteratively making the array 
 * lexicographically smaller by swapping elements. 
 * At each index, the algorithm tries to find the smallest valid number (based on the limit constraint) in the 
 * remaining portion of the array and swaps it with the current number. 
 * This process is repeated until no smaller valid number can be found for the current position. 
 * 
 * The intuition is straightforward: repeatedly bring the smallest possible valid element to the front, one 
 * position at a time, until the array is sorted as desired.
 * 
 * 
 * Complexity:
 * Time: O(n^3)
 * Space: O(1)
 */

// limit = 2

// 1 3 5 8 9
//          i j

class Solution1 {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        // Approach 1: Bruteforce Approach
        int n = nums.length;

        for(int i = 0; i < n; i++) {
            // Now we've to start checking again from same ith pointer after swap
            while(true) {
                boolean isSwapped = false;

                for(int j = i + 1; j < n; j++) {
                    // find those jth element which is smaller than ith element & there difference is less than equal to limit
                    if(nums[j] < nums[i] && Math.abs(nums[j] - nums[i]) <= limit) {
                        swap(nums, i, j);
                        isSwapped = true;
                        break;
                    }
                }

                if(!isSwapped) {
                    // Now we need to increase ith pointer
                    break;
                }
            }
        }

        return nums;
    }

    private void swap(int[] nums, int idx1, int idx2) {
        int temp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = temp;
    }
}


/**
 * Approach 2: Better Approach
 * Thought Process and Intuition: This approach leverages sorting to preprocess the numbers and group them 
 * based on the limit constraint. 
 * After sorting, numbers that differ by at most limit are placed in the same group. 
 * 
 * The intuition is that sorting helps identify groups of numbers that can be swapped without violating the 
 * limit constraint. 
 * Using maps and LinkedList, the algorithm ensures that each group maintains its smallest unused element,
 * which can be efficiently used to construct the final lexicographically smallest array.
 * 
 * 
 * Complexity:
 * Time: O(nlogn)
 * Space: O(n)
 */

class Solution2 {
    public int[] lexicographicallySmallestArray(int[] vec, int limit) {
        // Approach 2: 
        // Step 1: First we'll sort the entire array and than form the grouping using maps
        int n = vec.length;

        // Maintain original vec[] as it'll help when forming resultant[] using groupToList Map
        int[] nums = vec.clone(); 

        Arrays.sort(nums);
        
        // Map for numbering of groups
        Map<Integer, LinkedList<Integer>> groupToList = new HashMap<>();

        // Map for finding which elements belongs to which group
        Map<Integer, Integer> numToGroup = new HashMap<>();

        int groupNum = 0;
        groupToList.put(groupNum, new LinkedList<>());
        groupToList.get(groupNum).add(nums[0]); // Add element at last of LinkedList - O(1)

        numToGroup.put(nums[0], groupNum);

        for(int i = 1; i < n; i++) {
            if(Math.abs(nums[i] - nums[i-1]) > limit) {
                // Now we need to change the group
                groupNum++;
                groupToList.put(groupNum, new LinkedList<>());
            }

            groupToList.get(groupNum).add(nums[i]); // Add element at last of LinkedList - O(1)
            numToGroup.put(nums[i], groupNum);
        }

        // Step 2: Than join those groups to form final array
        int[] result = new int[n];

        for(int i = 0; i < n; i++) {
            // First find the group to which nums[i] belongs
            int originalValue = vec[i]; // Note: Taking group value from original array vec not from clone one
            int group = numToGroup.get(originalValue);

            // Than add the smallest element of that group element
            result[i] = groupToList.get(group).pollFirst();  // remove & return from first
        }

        return result;
    }
}