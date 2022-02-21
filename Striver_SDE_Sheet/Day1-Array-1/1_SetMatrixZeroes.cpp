#include<iostream>
#include<vector>
// Striver SDE Sheet - Day1-Array-Part1
// Leetcode : 73. Set Matrix Zeroes

// 1. Brute Force Approach - We'll traverse whole matrix and if encounter 0 than we'll make its all corresponding row and columns as -1 apart from 0
// as it might affect other rows and columns
// TC - O(m * n) * O(m + n)
// SC - O(1)
// This Approach will give TLE + fail for -ve elements 
class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        for (int i = 0; i <= row - 1; i++){
            for (int j = 0; j <= col - 1; j++){

                if(matrix[i][j] == 0){
                    // Making entire row as -1 except 0
                    for (int r = i - 1; r >= 0; r--){
                        if(matrix[r][j] != 0)
                            matrix[r][j] = -1;
                    }

                    for (int r = i + 1; r <= row - 1; r++){
                        if(matrix[r][j] != 0)
                            matrix[r][j] = -1;
                    }
                    
                    // Making entire col as -1 except 0
                    for (int c = j - 1; c >= 0; c--){
                        if(matrix[i][c] != 0)
                            matrix[i][c] = -1;
                    }
                    
                    for (int c = j + 1; c <= col - 1; c++){
                        if(matrix[i][c] != 0)
                            matrix[i][c] = -1;
                    }
                }

            }
        }
        
        // Now we'll make -1 as 0
        for (int i = 0; i <= row - 1; i++){
            for (int j = 0; j <= col - 1; j++){
                if(matrix[i][j] == -1)
                    matrix[i][j] = 0;
            }
        }
        
    }
};


// Better Approach - Using 2 arrays of size row & col that will store the state of each rows & cols. After this we'll make that cell 0 if
// Any row state array or col state array contains 0
// TC - O(m * n) + O(m * n)
// SC - O(m) + O(n)
// ACCEPTED
class Solution1 {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        // Making row & col state and initializing it to -1 as we have to make it 0
        std::vector<int> rowState(row, -1);
        std::vector<int> colState(col, -1);
        // Populating the states
        for (int i = 0; i <= row - 1; i++){
            for (int j = 0; j <= col - 1; j++){
                if(matrix[i][j] == 0){
                    rowState[i] = 0;
                    colState[j] = 0;
                }
            }
        }
        
        // Making entire row & col to be 0
        for (int i = 0; i <= row - 1; i++){
            for (int j = 0; j <= col - 1; j++){
                if(rowState[i] == 0 || colState[j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
};


// Most Optimized Approach - Instead of taking 2 extra arrays for storing rowState & colState we'll use first col as rowState & first row as 
// colState. As mat[0][0] will common for both the states we'll keep extra variable col1 for another state. After first traversal we'll traverse
// again but in reverse order.
// TC - O(m * n)
// SC - O(1)
// ACCEPTED
class Solution3 {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        // Extra variable for 0th index of colState(0th row) & initialise it to true or 1 & rowState(0th col) will have matrix[0][0]
        int col1 = 1;   

        for (int i = 0; i <= row - 1; i++){
            // if in 0th col there is any element which is 0 than we'll store its state in colState extra variable
            if(matrix[i][0] == 0)
                col1 = 0;
            // Starting traversal from j = 1 as 0th col is being used as rowState
            for (int j = 1; j <= col - 1; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;   // rowState
                    matrix[0][j] = 0;   // colState
                }
            }
        }

        // Reverse Traversal
        for (int i = row - 1; i >= 0; i--){
            // Traversing from col - 1 to 1st col as 0th col is used for rowState
            for (int j = col - 1; j >= 1; j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }

            if(col1 == 0)
                matrix[i][0] = 0;
        }
    }
};


int main(){
    // Run on LEETCODE
    return 0;
}