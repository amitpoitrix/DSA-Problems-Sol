/**
 * 1780. Check if Number is a Sum of Powers of Three
 * Link: https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/?envType=daily-question&envId=2025-03-04
 * 
 * 
 * Approach 1: Using School Math
 * 
 * The idea is to find the highest power of 3 that is ≤ n.
 * Keep subtracting the largest possible power of 3 from n.
 * If n can be reduced to 0 without using the same power twice, return true; otherwise, return false.
 * 
 * Complexity:
 * Time: O(logn)
 * Space: O(1)
 */

class Solution1 {
    public boolean checkPowersOfThree(int n) {
        // Approach 1:
        // Step 1: First find max power of 3 from 0 whose overall value is greater than n
        int power = 0;
        while(Math.pow(3, power) <= n) {
            power++;
        }

        // Step 2: After getting power than try to minimize n at each recursive step till it 
        // become 0 and at any moment, n is again greater than 3^power than return false as we 
        // can't represent n in the sum of distinct power of 3
        while(n > 0) {
            if(n >= Math.pow(3, power)) {
                n -= Math.pow(3, power);
            }

            // Now if again n is greater than 3^power than return false
            if(n >= Math.pow(3, power)) {
                return false;
            }

            power--;
        }

        return true;
    }
}


/**
 * Approach 2: Using Ternary Representation:
 * 
 * Convert n to base 3 (ternary).
 * If any digit in the ternary representation is 2, return false (since we can only use 0 or 1 powers of 3).
 * Otherwise, return true.
 * 
 * Complexity:
 * Time: O(logn)
 * Space: O(1)
 */

class Solution2 {
    public boolean checkPowersOfThree(int n) {
        // Approach 2: Using Ternary Operation (Similar to Binary one)

        // Means dividing n by 3 and writing remainder in reverse order
        // Similar to finding Binary Representation of Decimal number
        // 12 by 3 = (0 * 3^3) + (1 * 3^2) + (1 * 3^1) (0 * 3^0)

        while(n > 0) {
            if(n % 3 == 2) {
                return false;
            }

            n /= 3;
        }

        return true;
    }
}


/**
 * Approach 3: Using Take and Not Take (Recursion):
 * 
 * Explore two choices at each step: either take the current power of 3 or skip it.
 * If n becomes 0 in any recursive path, return true.
 * If no valid combination is found, return false.
 * This approach mimics the subset sum problem and is less efficient.
 * 
 * Complexity:
 * Time: O(2^(logn))
 * Space: O(logn)
 */

class Solution3 {
    public boolean checkPowersOfThree(int n) {
        // Approach 3: Using Recursion
        
        // solve(num, power = 0)
        return solve(n, 0);
    }

    private boolean solve(int n, int power) {
        // Base Case
        // 1. When n becomes 0
        if(n == 0) {
            return true;
        }

        // 2. when 3^power is greater than n
        if(Math.pow(3, power) > n) {
            return false;
        }

        boolean taken = solve(n - (int)Math.pow(3, power), power + 1);
        boolean notTaken = solve(n, power + 1);

        return taken || notTaken;
    }
}