/**
 * 2698. Find the Punishment Number of an Integer
 * Link: https://leetcode.com/problems/find-the-punishment-number-of-an-integer/description/?envType=daily-question&envId=2025-02-15
 * 
 * 
 * Approach 1: Using Recursion(Backtracking) - using string subsets
 * The key idea is to check if a squared number can be split into parts that sum up to the original number. 
 * We recursively explore all possible partitions of the squared number (as a string) and use memoization to 
 * optimize overlapping subproblems. 
 * If a valid partition exists, we add the squared number to the total punishment sum.
 * 
 * Complexity:
 * Time: O(n * 2^(log10(n^2)))
 * Space: O(log10(n^2) * n)
 */

class Solution {
    public int punishmentNumber(int n) {
        // Approach 1: Using Recursion (or Bactracking)
        int result = 0;

        for(int i = 1; i <= n; i++) {
            int sq = i * i;

            String square = Integer.toString(sq);

            if(check(0, 0, square, i) == true) {
                result += sq;
            }
        }

        return result;
    }

    private boolean check(int idx, int currSum, String square, int num) {
        // Base Case 1
        if(idx >= square.length()) {
            return currSum == num;
        }

        // Base Case 2
        if(currSum > num) {
            return false;
        }

        for(int j = idx; j < square.length(); j++) {
            int substring = square.substring(idx, j + 1);
            
            int subNum = Integer.parseInt(substring);

            if(check(j + 1, currSum + subNum, square, num) == true) {
                return true;
            }
        }

        return false;
    }
}


/**
 * Approach 2: 
 * Instead of treating the squared number as a string, this approach directly extracts and sums digit groups from 
 * the number itself. 
 * It tries different segmentations by dividing the number into parts (units, tens, hundreds, etc.) and recursively 
 * checks if any combination adds up to the original number. 
 * This method reduces space complexity while maintaining the same recursive structure.
 * 
 * Complexity:
 * Time: O(n * 2^(log10(n^2)))
 * Space: O(log10(n^2) * n)
 */

class Solution2 {
    public int punishmentNumber(int n) {
        // Approach 2: Using Recursion (or Bactracking) - without substring
        int result = 0;

        for(int i = 1; i <= n; i++) {
            int sq = i * i;

            if(check(0, sq, i) == true) {
                result += sq;
            }
        }

        return result;
    }

    private boolean check(int currSum, int sq, int num) {
        // Base Case 1
        if(sq == 0) {
            return currSum == num;
        }

        // Base Case 2
        if(currSum > num) {
            return false;
        }

        // Looping till 10000 because num can max reach from 1<= n <= 1000, 10000 for n = 1000 it's square will give 7 digit no.
        for(int i = 10; i <= 10000; i *= 10) {
            if(check(currSum + (sq % i), sq / i, num) == true) {
                return true;
            }
        }

        return false;
    }
}