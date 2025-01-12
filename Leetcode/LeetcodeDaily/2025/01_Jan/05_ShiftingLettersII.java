/**
 * 2381. Shifting Letters II
 * Link: https://leetcode.com/problems/shifting-letters-ii/description/?envType=daily-question&envId=2025-01-05
 * 
 * 
 * Approach:
 * This solution efficiently handles multiple range-based character shifts on a string using a difference array 
 * technique:
 * Difference Array Construction:
 * A diff array is initialized to record the net effect of all shifts at each position.
 * For each range [start, end] in shifts:
 * If the shift direction is forward (1), increment diff[start] and decrement diff[end + 1] (if within bounds).
 * If the direction is backward (0), decrement diff[start] and increment diff[end + 1] (if within bounds).
 * 
 * Prefix Sum Calculation:
 * The diff array is converted into a cumulative prefix sum, which gives the net shift effect for each character in 
 * the string.
 * 
 * Apply Shifts to the String:
 * For each character in the string:
 * Calculate the effective shift by taking diff[i] % 26 (to handle wrap-around within the alphabet).
 * Adjust negative shifts to positive by adding 26.
 * Apply the shift to the character using modular arithmetic to ensure the result stays within valid alphabetic 
 * bounds.
 * 
 * Complexity:
 * Time: O(n + m); where n is the length of string & m is the length of shifts
 * Space: O(n)
 */

class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        // Approach: Using Difference Array

        // Step 1: First computing diff[]
        int n = s.length();
        int[] diff = new int[n];

        for(int i = 0; i < shifts.length; i++) {
            int startIdx = shifts[i][0];
            int endIdx = shifts[i][1];
            int x = shifts[i][2] == 0 ? -1: 1;

            diff[startIdx] += x;

            if(endIdx + 1 < n) {
                diff[endIdx + 1] -= x;
            }
        }

        // Step 2: Now finding the cumulative array
        for(int i = 1; i < n; i++) {
            diff[i] += diff[i-1];
        }

        // Step 3: Now forming the resultant string
        StringBuilder result = new StringBuilder();

        for(int i = 0; i < n; i++) {
            int shift = diff[i] % 26;

            if(shift < 0) {
                shift += 26;
            }

            char ch = (char) ((((s.charAt(i) - 'a') + shift) % 26) + 'a');
            result.append(ch);
        }

        return result.toString();
    }
}