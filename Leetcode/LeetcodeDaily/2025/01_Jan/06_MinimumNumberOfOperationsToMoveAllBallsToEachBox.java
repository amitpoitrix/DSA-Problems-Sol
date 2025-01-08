/**
 * 1769. Minimum Number of Operations to Move All Balls to Each Box
 * Link: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/?envType=daily-question&envId=2025-01-06
 * 
 * 
 * Approach 1: Brute Force Using HashSet
 * 
 * This approach identifies the positions of all boxes containing balls and stores them in a HashSet. 
 * For each box, the distances to all the positions in the set are calculated and summed to determine the total 
 * moves required.
 * 
 * Complexity:
 * Time: O(n^2)
 * Space: O(n)
 */

class Solution1 {
    public int[] minOperations(String boxes) {
        // Approach 1: Brute Force Approach
        int n = boxes.length();

        // Step 1: Set to store the idx of boxes having one ball
        Set<Integer> set = new HashSet<>();
        for(int i = 0; i < n; i++) {
            if(boxes.charAt(i) == '1') {
                set.add(i);
            }
        }

        // Step 2: Now computing answer[]
        int[] answer = new int[n];
        
        for(int i = 0; i < n; i++) {
            // Now iterating over boxes having ball idx i.e., set
            for(int setIdx: set) {
                answer[i] += Math.abs(i - setIdx);
            }
        }

        return answer;
    }
}


/**
 * Approach 2: Optimal Using Cumulative Sum
 * 
 * This approach uses cumulative sums to calculate the moves. 
 * It first computes the moves required for all balls to the left of each box, then calculates the moves for 
 * all balls to the right, combining the results for the final answer.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution2 {
    public int[] minOperations(String boxes) {
        // Approach 2: Optimised Approach
        int n = boxes.length();
        int[] answer = new int[n];

        int cumVal = 0;
        int cumValSum = 0;

        // first Left to right
        for(int i = 0; i < n; i++) {
            answer[i] = cumValSum;
            if(boxes.charAt(i) == '1') {
                cumVal++;
            }
            cumValSum += cumVal;
        }

        // Now right to left
        cumVal = 0;
        cumValSum = 0;
        for(int i = n - 1; i >= 0; i--) {
            answer[i] += cumValSum;
            if(boxes.charAt(i) == '1') {
                cumVal++;
            }
            cumValSum += cumVal;
        }


        return answer;
    }
}

// 0 1 2 3 4 5
// 0 0 1 0 1 1

// 11 8 5 4 3 4

// first L to R
// 0 0 1 1 2 3

// Now R to L
// 3 3 3 2 2 1

// using variable
// L to R
// cumVal = 3
// cumValSum = 7 (cumValSum += cumVal)
// R to L
// cumVal = 3
// cumValSum = 11