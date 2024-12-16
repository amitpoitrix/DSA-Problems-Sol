/**
 * 2558. Take Gifts From the Richest Pile
 * Link: https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/?envType=daily-question&envId=2024-12-12
 * 
 * Approach: Using maxHeap
 * 
 * Complexity:
 * Time: O(klogn) + O(nlogn) ~ O(nlogn)
 * Space: O(1)
 */

class Solution {
    public long pickGifts(int[] gifts, int k) {
        int n = gifts.length;

        Queue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        // O(nlogn): storing n elements and each element is taking O(logn) time for insertion
        for(int num: gifts) {
            maxHeap.offer(num);
        }

        while(k-- > 0) {
            int element = maxHeap.poll();

            maxHeap.offer((int)Math.sqrt(element));
        }

        long result = 0;
        while(!maxHeap.isEmpty()) {
            result += maxHeap.poll();
        }

        return result;
    }
}