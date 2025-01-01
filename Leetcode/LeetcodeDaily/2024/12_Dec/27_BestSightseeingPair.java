/**
 * 1014. Best Sightseeing Pair
 * Link: https://leetcode.com/problems/best-sightseeing-pair/description/?envType=daily-question&envId=2024-12-27
 * 
 * 
 * Approach 1: Bruteforce Approach
 * This approach iterates through all pairs of indices i and j (i less than j) to calculate the score for each pair 
 * and keeps track of the maximum score. It uses nested loops, making it inefficient for large inputs.
 * 
 * Complexity:
 * Time: O(n^2)
 * Space: O(n)
 */

class Solution1 {
    public int maxScoreSightseeingPair(int[] values) {
        // Approach 1: Bruteforce Approach
        int n = values.length;

        int maxScore = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                maxScore = Math.max(maxScore, values[i] + i + values[j] - j);
            }
        }

        return maxScore;
    }
}


/**
 * Approach 2: Optimised Approach - Using Extra Space
 * 
 * This approach precomputes an auxiliary array vec to store the maximum value of values[i] + i up to each index i. 
 * It then iterates over the array to compute the maximum score using values[j] - j and the precomputed values from vec. 
 * This reduces the number of iterations but uses extra space.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(n)
 */

class Solution2 {
    public int maxScoreSightseeingPair(int[] values) {
        // Approach 2: Optimised Approach
        int n = values.length;

        int[] maxLeftScore = new int[n];
        maxLeftScore[0] = values[0] + 0;

        for(int i = 1; i < n; i++) {
            maxLeftScore[i] = Math.max(maxLeftScore[i-1], values[i] + i);
        }

        int maxScore = 0;
        for(int j = 1; j < n; j++) {
            maxScore = Math.max(maxScore, maxLeftScore[j-1] + values[j] - j);
        }

        return maxScore;
    }
}


/**
 * Approach 3: Optimised Approach - Using O(1) Space
 * 
 * This is the most optimized approach. 
 * It uses a single variable maxLeftScore to keep track of the maximum value of values[i] + i encountered so far. 
 * For each index j, it computes the score using values[j] - j and updates the result. 
 * This approach efficiently computes the result in a single pass.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution3 {
    public int maxScoreSightseeingPair(int[] values) {
        // Approach 3: Optimised Approach - No need of extra array
        int n = values.length;

        int maxLeftScore = values[0] + 0;   // to store max (values[i] + i)
        int maxScore = 0;

        for(int j = 1; j < n; j++) {
            maxScore = Math.max(maxScore, maxLeftScore + values[j] - j);

            if(values[j] + j > maxLeftScore) {
                maxLeftScore = values[j] + j;
            }
        }

        return maxScore;
    }
}