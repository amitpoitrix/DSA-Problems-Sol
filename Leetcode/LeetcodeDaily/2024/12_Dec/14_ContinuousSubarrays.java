/**
 * 2762. Continuous Subarrays
 * Link: https://leetcode.com/problems/continuous-subarrays/description/?envType=daily-question&envId=2024-12-14
 * 
 * 
 * Approach: Using Sliding Window + Heaps
 * Idea:
 * Use two heaps (priority_queue) to track the smallest and largest elements in the current sliding window.
 * Min-heap tracks the smallest element, and max-heap tracks the largest element.
 * 
 * Process:
 * Expand the window by incrementing j and adding nums[j] to both heaps.
 * Check the difference between the largest (maxHeap.peek()) and smallest (minHeap.peek()) elements.
 * If the difference exceeds 2, shrink the window by incrementing i.
 * Remove elements from the heaps that are no longer part of the window (indices less than or equal to i).
 * Add the number of valid subarrays ending at j to the result.
 * 
 * Complexity:
 * Time: O(nlogn)
 * Space: O(n)
 */

class Solution {
    public long continuousSubarrays(int[] nums) {
        // Using Sliding Window + Heap
        int n = nums.length;

        // Step 1: First insert all the elements in maxHeap and minHeap
        Queue<Pair> minHeap = new PriorityQueue<>(
            new Comparator<Pair> () {
                @Override
                public int compare(Pair p1, Pair p2) {
                    if(p1.element == p2.element) {
                        return Integer.compare(p1.idx, p2.idx);
                    }
                    return Integer.compare(p1.element, p2.element);
                }
            }
        );

        Queue<Pair> maxHeap = new PriorityQueue<>(
            new Comparator<Pair> () {
                @Override
                public int compare(Pair p1, Pair p2) {
                    if(p1.element == p2.element) {
                        return Integer.compare(p1.idx, p2.idx);
                    }
                    return Integer.compare(p2.element, p1.element);
                }
            }
        );

        // Step 2: Now using Sliding Window find the count of continuous subarrays
        long result = 0;

        int i = 0;
        int j = 0;

        while(j < n) {
            // Adding the ith elements in heaps
            minHeap.offer(new Pair(nums[j], j));
            maxHeap.offer(new Pair(nums[j], j));

            // making window valid
            while(maxHeap.peek().element - minHeap.peek().element > 2) {
                // Note: use while instead of if
                while(maxHeap.peek().idx <= i) {
                    maxHeap.poll();
                }

                while(minHeap.peek().idx <= i) {
                    minHeap.poll();
                }

                i++;
            }

            // counting the subarray
            result += (j - i + 1);
            j++;
        }

        return result;
    }

    static class Pair {
        int element;
        int idx;

        Pair(int element, int idx) {
            this.element = element;
            this.idx = idx;
        }
    }
}

// 1. For counting the no. of subarrays

// [1]
// total subarray = 1 (i.e., [1])

// [1, 2]
// total subarray = 1 + 2 = 3 (i.e., [1], [1, 2], [2])

// [1,2,3]
// total subarray = 3 + 3 = 6 (i.e., [1], [1, 2], [2], [1, 2, 3], [2, 3], [3])

// so every time a new element is added in the array the count of subarray is being
// increased by its length (j - i + 1)


// 2. Condition for subarray to be continuous (i.e., Valid Window)

// Absolute difference between max element & min element in the subarray should 
// not exceed 2
