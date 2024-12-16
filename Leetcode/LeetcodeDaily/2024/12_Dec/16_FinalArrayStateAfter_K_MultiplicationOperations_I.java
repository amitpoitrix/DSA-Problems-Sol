/**
 * 3264. Final Array State After K Multiplication Operations I
 * Link: https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/description/?envType=daily-question&envId=2024-12-16
 * 
 * 
 * Approach 1: Brute Force Approach
 * This approach iteratively scans the entire array to find the smallest element in each of the k iterations. 
 * Once found, the smallest element is multiplied by the given multiplier. This method directly modifies the input 
 * array without using additional data structures.
 * 
 * Complexity:
 * Time: O(k * n)
 * Space: O(1)
 */

class Solution1 {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        int n = nums.length;
        int smallestIdx = 0;

        // run while loop k times
        while(k-- > 0) {
            // find the smallest element idx and replace it with x * multiplier
            for(int i = 0; i < n; i++){
                if(nums[smallestIdx] > nums[i]) {
                    smallestIdx = i;
                }
            }

            nums[smallestIdx] *= multiplier;
            smallestIdx = 0;
        }

        return nums;
    }
}


/**
 * Approach 2: Using min Heap 
 * This approach uses a min-heap (priority_queue) to efficiently track the smallest element. Initially, all elements 
 * are added to the heap. In each iteration, the smallest element is extracted, updated by multiplying it with the 
 * multiplier, and then reinserted into the heap. This allows for efficient management of the smallest element.
 * 
 * Complexity:
 * Time: O(nlogn + klogn) ~ O(nlogn)
 * Space: O(n)
 */

class Solution2 {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        // Using minHeap
        int n = nums.length;

        // Step 1: Store elements and there idx oin minHeap
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

        // O(n * logn)
        for(int i = 0; i < n; i++) {
            minHeap.offer(new Pair(nums[i], i));
        }

        // Step 2: run while loop till k times and do the needful
        // O(k * logn)
        while(k-- > 0) {
            Pair p = minHeap.poll();

            nums[p.idx] *= multiplier;

            minHeap.offer(new Pair(nums[p.idx], p.idx));
        }

        return nums;
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