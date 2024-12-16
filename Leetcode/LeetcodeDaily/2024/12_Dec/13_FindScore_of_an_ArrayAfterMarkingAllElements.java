/**
 * 2593. Find Score of an Array After Marking All Elements
 * Link: https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/?envType=daily-question&envId=2024-12-13
 * 
 * 
 * Approach: Using minHeap
 */

class Solution {
    public long findScore(int[] nums) {
        int n = nums.length;

        // Edge Case
        if(n == 1) {
            return nums[0];
        }

        boolean[] visited = new boolean[n];

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

        // O(nlogn)
        for(int i = 0; i < n; i++) {
            minHeap.offer(new Pair(nums[i], i));
        }

        long score = 0;

        while(!minHeap.isEmpty()) {
            Pair p = minHeap.poll();

            // Only adding those element in score which is not marked
            if(!visited[p.idx]) {
                score += p.element;

                visited[p.idx] = true;

                if(p.idx == 0) {
                    visited[p.idx + 1] = true;
                } else if(p.idx == n - 1) {
                    visited[p.idx - 1] = true;
                } else {
                    visited[p.idx - 1] = true;
                    visited[p.idx + 1] = true;
                }
            }
        }

        return score;
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