import java.util.*;

/*
 * 2554. Maximum Number of Integers to Choose From a Range I
 * Link: https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/description/?envType=daily-question&envId=2024-12-06
 * 
 * 
 * Approach: 
 * The goal is to find the maximum count of integers between 1 and n that can be included without exceeding a given maxSum 
 * while excluding the integers in a banned list.
 * 
 * Data Structure for Efficient Lookup:
 * A HashSet is used to store the banned numbers, enabling O(1) time complexity for checking if a number is banned.
 * 
 * Iterative Inclusion:
 * Iterate through all numbers from 1 to n. For each number:
 * Skip it if it is present in the banned set.
 * Check if adding the number to the current sum (sum) stays within the maxSum. If so Increment the count and update the sum.
 * Stop the process if the sum exceeds maxSum.
 * 
 * Greedy Approach:
 * The numbers are processed sequentially, ensuring the smallest possible numbers are added first to maximize the count.
 * This approach ensures optimal performance with a time complexity of O(n), as each number from 1 to n is processed once, 
 * and set lookups are O(1).
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(n)
 */

class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        Set<Integer> set = new HashSet<>();
        for(int element: banned) {
            set.add(element);
        }

        int sum = 0;
        int count = 0;
        for(int i = 1; i <= n; i++) {
            if(!set.contains(i)) {
                sum += i;
                count++;
                if(sum > maxSum) {
                    return count - 1;
                }
            }
        }

        return count;
    }
}