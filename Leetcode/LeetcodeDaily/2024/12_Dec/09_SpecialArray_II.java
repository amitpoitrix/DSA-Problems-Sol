import java.util.*;

/*
 * 3152. Special Array II
 * Link: https://leetcode.com/problems/special-array-ii/description/?envType=daily-question&envId=2024-12-09
 * 
 * 
 * Approach 1: Using Cumulative Sum
 * 
 * Idea: Use a prefix cumulative sum to count violating indices where two consecutive elements have the same 
 * parity.
 * 
 * Steps:
 * Create a cumSum array where cumSum[i] stores the total count of violating indices from the start to index i.
 * For each query, check if there are any violating indices in the range [start+1, end] by calculating the 
 * difference: cumSum[end] - cumSum[start].
 * If the difference is zero, the subarray is special.
 * 
 * Complexity:
 * Time: O(n + m)
 * Space: O(n + m)
 */

// nums = [4,3,1,6]
// queries = [[0,2],[2,3]]


// 0 1 2 3
// 4 3 1 6
// 0 0 1 1
// using prefixCount

 class Solution1 {
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        // Using prefix count
        int n = nums.length;
        int[] prefixCount = new int[n];

        for(int i = 1; i < n; i++) {
            if(nums[i - 1] % 2 == nums[i] % 2) {
                // means we don't have a parity
                prefixCount[i] = prefixCount[i - 1] + 1;
            } else {
                prefixCount[i] = prefixCount[i - 1];
            }
        }

        int m = queries.length;
        boolean[] answer = new boolean[m];

        for(int i = 0; i < m; i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            if(prefixCount[end] - prefixCount[start] == 0) {
                answer[i] = true;
            }
        }

        return answer;
    }
}


/*
 * Approach 2: Using Two Pointers
 * 
 * Idea: For each index i, precompute the rightmost index j such that the subarray [i, j] is special.
 * 
 * Steps:
 * Use two pointers, i and j, to iterate through nums. Expand j until a violating index is found or the 
 * array ends.
 * Store the rightmost valid index for each i in validRightMostIdx.
 * For each query, check if the queried range [start, end] lies completely within [start, validRightMostIdx[start]].
 */

// nums = [4,3,1,6]
// queries = [[0,2],[2,3]]

// 0 1 2 3
// 4 3 1 6
//       i
//       j

// nextValidIdx
// 1 1 3 3
// 0 1 2 3

 class Solution2 {
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int n = nums.length;

        int i = 0;
        int j = 0;

        int[] nextValidIdx = new int[n];

        while(i < n) {
            if(j < i) {
                j = i;
            }

            while(j + 1 < n && (nums[j] % 2) != (nums[j + 1] % 2)) {
                j++;
            }

            nextValidIdx[i] = j;
            i++;
        }

        int m = queries.length;
        boolean[] answer = new boolean[m];

        for(int k = 0; k < m; k++) {
            int start = queries[k][0];
            int end = queries[k][1];

            if(nextValidIdx[start] >= end) {
                answer[k] = true; 
            }
        }

        return answer;
    }
}


/*
 * Approach 3: Using Binary Search
 * 
 * Idea: Use a list of violating indices and perform a binary search to determine if any violating index 
 * exists within the query range.
 * 
 * Steps:
 * Identify and store all violating indices (where consecutive elements have the same parity) in a sorted list vi.
 * For each query, use binary search to check if any violating index exists in the range [start+1, end].
 * If no violating index is found, mark the subarray as special.
 */

// nums = [4,3,1,6]
// queries = [[0,2],[2,3]]

// 0 1 2 3
// 4 3 1 6
 
// Maintain a list of violatingIdx[] = [2]

class Solution3 {
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int n = nums.length;

        List<Integer> violatingIdx = new ArrayList<>();
        for(int i = 1; i < n; i++) {
            if(nums[i - 1] % 2 == nums[i] % 2) {
                violatingIdx.add(i);
            }
        }

        // Now this violatingIdx will be in sorted form so we just search using Binary Search if range[start, end] contains any of the violatingIdx
        int m = queries.length;
        boolean[] answer = new boolean[m];

        for(int i = 0; i < m; i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            if(isSpecial(violatingIdx, start + 1, end)) {
                answer[i] = true;
            }
        }

        return answer;
    }

    private boolean isSpecial(List<Integer> violatingIdx, int start, int end) {
        int left = 0;
        int right = violatingIdx.size() - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(violatingIdx.get(mid) > end) {
                right = mid - 1;
            } else if(violatingIdx.get(mid) < start) {
                left = mid + 1;
            } else {
                return false;
            }
        }

        return true;
    }
}