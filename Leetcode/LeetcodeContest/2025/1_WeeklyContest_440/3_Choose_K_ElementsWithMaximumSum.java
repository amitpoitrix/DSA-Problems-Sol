/**
 * 3478. Choose K Elements With Maximum Sum
 * Link: https://leetcode.com/problems/choose-k-elements-with-maximum-sum/description/
 * 
 * YT: https://www.youtube.com/watch?v=c-hV30Ffj6o&t=1728s
 * 
    Optimised Approach: Main challenge is how to do this in less than O(n^2)

    The problem is for every ith element we need to find all the j indices which is less than 
    ith element in nums1[]
    
    So the idea is to sort the nums1[] which will give all the elements less than ith elements to 
    its LHS
    
    But what about the initial index which was associated to nums2[] for getting the max value
    
    So for this we'll pair the element with it original index and store them in 
    new array[] Pair<element, originalIdx>
    
    Now while computing max sum of elements we'll again have to traverse from ith element to 
    0th element
    
    Now to avoid this we can store the nums2[j] element with the above array[] so its element 
    type will be <element, originalIdx(i.e., j), nums2[j]>
    
    And we'll make use of variable which will store the sum from 0th idx (kind of cumulative sum)
    But we need sum of top k elements
    
    So for this we'll maintain minHeap and whenever its size becomes greater than k we'll remove
    the element so the remaining element in the heap will always be top k element and also 
    whatever element we're removing from minHeap needs to be remove from that sum variable as 
    well, in this way we'll get top k msum in O(1)
    
    Edge Case: if element is same as previous one than its result will also be same as previous
 *
 *
 * Complexity:
 * Time: O(nlogn + nlogk)
 * Space: O(n)
 */



class Solution {
    public long[] findMaxSum(int[] nums1, int[] nums2, int k) {       
        int n = nums1.length;

        // Array<element, originalIdx>
        int[][] triple = new int[n][2];

        for(int i = 0; i < n; i++) {
            triple[i][0] = nums1[i];
            triple[i][1] = i;
        }

        // Now sort based on element 
        Arrays.sort(triple, (a, b) -> a[0] - b[0]); // O(nlogn)

        long[] result = new long[n];

        Queue<Long> minHeap = new PriorityQueue<>();

        long cumulativeSum = 0;

        // Now we'll traverse over triple[] array
        for(int i = 0; i < n; i++) {    // O(n)
            int originalIdx = triple[i][1];

            // Edge Case: if element is same as previous one than its result will also be same
            if(i > 0 && triple[i - 1][0] == triple[i][0]) {
                result[originalIdx] = result[triple[i-1][1]];
            } else {
                result[originalIdx] = cumulativeSum;
            }

            // for next Iteration
            cumulativeSum += (long)nums2[originalIdx];
            minHeap.offer((long)nums2[originalIdx]);

            if(minHeap.size() > (long)k) {  // O(nlogk)
                long removeElement = minHeap.poll();
                cumulativeSum -= removeElement;
            }
        }

        return result;
    }
}