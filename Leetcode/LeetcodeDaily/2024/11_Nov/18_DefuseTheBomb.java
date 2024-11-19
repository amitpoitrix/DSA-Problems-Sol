/*
 * Link: https://leetcode.com/problems/defuse-the-bomb/description/?envType=daily-question&envId=2024-11-18
 * 
 *  Approach 1: BruteForce Approach: Normal Simluation
 * 
 * -ve index -> circular -> (index + n) % n
 * +ve index -> circular -> index % n
 */

class Solution {
    public int[] decrypt(int[] code, int k) {
        // Optimised Approach: Sliding Window (fixed size)

        // Step 1: Handle the case when k == 0
        int n = code.length;
        int[] result = new int[n];

        if(k == 0) {
            return result;
        }

        // Step 2: Now based on value of k we'll assign value(position) to two pointers
        // representing starting and ending of fixed window size
        int i = -1;
        int j = -1;

        if(k > 0) {
            i = 1;
            j = k;
        } else if(k < 0) {
            i = n - Math.abs(k);
            j = n - 1;
        }

        // Step 3: First we'll calculate the sum from [i, j] and than we'll move our 
        // window to get the sum for next set of indexes
        int windowSum = 0;
        for(int x = i; x <= j; x++) {
            windowSum += code[x];
        }
        result[0] = windowSum;

        for(int x = 1; x < n; x++) {
            windowSum -= code[i % n];
            i++;

            j++;
            windowSum += code[j % n];

            result[x] = windowSum;
        }

        return result;
    }
}


/*
 * Approach 2: Using Sliding Window
 * 
 * Handle Special Case: If k is 0, the result is a vector of zeros, as no decryption is needed.
 *
 * Define Initial Window:
 * When k greater than 0, the initial window starts from index 1 to k.
 * When k less than 0, the window starts near the end of the array, accounting for the negative shift.
 * 
 * Calculate Initial Window Sum:
 * The windowSum is initialized as the sum of elements in the specified window (i to j).
 * 
 * Sliding Window Logic:
 * Traverse the array using a sliding window approach.
 * For each position, update the windowSum by subtracting the element that goes out of the window (i) and 
 * adding the element that enters the window (j + 1).
 * Adjust indices i and j in a circular manner using modulo operations.
 * 
 * Store Results:
 * Store the windowSum for each index in the result vector.
 */

class Solution1 {
    public int[] decrypt(int[] code, int k) {
        // Optimised Approach: Sliding Window (fixed size)

        // Step 1: Handle the case when k == 0
        int n = code.length;
        int[] result = new int[n];

        if(k == 0) {
            return result;
        }

        // Step 2: Now based on value of k we'll assign value(position) to two pointers
        // representing starting and ending of fixed window size
        int i = -1;
        int j = -1;

        if(k > 0) {
            i = 1;
            j = k;
        } else if(k < 0) {
            i = n - Math.abs(k);
            j = n - 1;
        }

        // Step 3: First we'll calculate the sum from [i, j] and than we'll move our 
        // window to get the sum for next set of indexes
        int windowSum = 0;
        for(int x = i; x <= j; x++) {
            windowSum += code[x];
        }
        result[0] = windowSum;

        for(int x = 1; x < n; x++) {
            windowSum -= code[i % n];
            i++;

            j++;
            windowSum += code[j % n];

            result[x] = windowSum;
        }

        return result;
    }
}