/*
 * 1861. Rotating the Box
 * Link: https://leetcode.com/problems/rotating-the-box/description/?envType=daily-question&envId=2024-11-23
 * 
 * Approach:
 * Transpose the 2D array to swap rows with columns.
 * Reverse each row in the transposed matrix to rotate the box 90 degrees clockwise.
 * 
 * Gravity Logic:
 * Use a lastPos pointer to track the lowest available position for stones in each column.
 * Iterate from the bottom to the top, moving stones directly without scanning upward.
 * 
 * Efficiency:
 * Gravity is applied in O(n × m), avoiding redundant upward scans.
 */

class Solution {
    public char[][] rotateTheBox(char[][] box) {
        int rows = box.length;
        int cols = box[0].length;

        char[][] result = new char[cols][rows];

        // Step 1: Rotate the box by 90 degree
        // 1.1: First find the transpose(taking row from 1st matrix and store it as column in 2nd matrix) of matrix
        for(int i = 0; i < cols; i++) {
            for(int j = 0; j < rows; j++) {
                result[i][j] = box[j][i];
            }
        }

        // 1.2: Now reverse each and every row 
        for(int i = 0; i < cols; i++) {
            // traversing till half the column length to reverse each row
            for(int j = 0; j < rows / 2; j++) {
                char temp = result[i][j];
                result[i][j] = result[i][rows - j - 1];
                result[i][rows - j - 1] = temp;
            }
        }

        // Step 2: Do the simulation given in the ques
        // 2.1: Traversing column by column from bottom to top
        for(int j = 0; j < rows; j++) {
            // 2.2: At each column, we'll initilise lastEmptyPosition as last row and keep on changing based on encountering stones or obstacles
            int lastPos = cols - 1;
            for(int i = cols - 1; i >= 0; i--) {
                if(result[i][j] == '#') {
                    result[i][j] = '.';
                    result[lastPos][j] = '#';
                    lastPos--;
                } else if(result[i][j] == '*') {
                    lastPos = i - 1;
                }
            }
        }

        return result;
    }
}