/*
 * 1975. Maximum Matrix Sum
 * Link: https://leetcode.com/problems/maximum-matrix-sum/description/?envType=daily-question&envId=2024-11-24
 * 
 * Approach:
 * The approach to solve the problem involves the following steps:
 * Iterate Through the Matrix:
 * Traverse each element in the matrix, calculate the absolute value of each element, and add it to the total sum.
 * 
 * Count Negative Elements:
 * Keep track of the count of negative numbers in the matrix (countNegatives).
 * 
 * Track the Smallest Absolute Value:
 * Identify the smallest absolute value in the matrix (smallestAbsoluteValue) to handle cases where an odd 
 * number of negatives makes the maximum sum adjustment necessary.
 * 
 * Handle the Negativity Parity:
 * If the count of negative numbers is even, all elements can be made positive, so the result is simply the total sum.
 * If the count is odd, one element must remain negative, so subtract twice the smallest absolute value from the 
 * total sum to minimize the negative impact.
 * This ensures the matrix sum is maximized while adhering to the rules.
 */

class Solution {
    public long maxMatrixSum(int[][] matrix) {
        int n = matrix.length;

        long sum = 0;
        int countNeg = 0;
        int smallestElement = Math.abs(matrix[0][0]);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                sum += Math.abs(matrix[i][j]);
                if(matrix[i][j] < 0) {
                    countNeg++;
                }

                if(Math.abs(matrix[i][j]) < smallestElement) {
                    smallestElement = Math.abs(matrix[i][j]);
                }
            }
        }

        if(countNeg % 2 != 0) {
            // means odd no. of -ve elements
            sum -= (2 * smallestElement);
        }

        return sum;
    }
}