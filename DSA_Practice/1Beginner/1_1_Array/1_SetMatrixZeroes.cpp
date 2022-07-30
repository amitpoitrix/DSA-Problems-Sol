#include<iostream>
#include<vector>
using namespace std;

// Lt: 73. Set Matrix Zeroes
// https://leetcode.com/problems/set-matrix-zeroes/

// Optimised Approach
// TC - O(n * m) + O(n + m)
// SC - O(n) + O(m))
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        // Take 2 dummy arrays
        vector<int> dummyRow(row, -1), dummyCol(col, -1);
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                // Marking both dummy ith & jth idx to be 0
                if(matrix[i][j] == 0){
                    dummyRow[i] = 0;
                    dummyCol[j] = 0;
                }
            }
        }
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                // If either of the ith or jth dummy array is 0 assign (i, j) to 0
                if(dummyRow[i] == 0 || dummyCol[j] == 0)
                    matrix[i][j] = 0;
            }
        }
        
    }
};

// Most Optimized Approach
// TC - O(n * m)
// SC - O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int col0 = 1;   // for 0th idx of Row Dummy Array(i.e, 0th idx of 0th col)
        
        // Traversing Top to bottom, Left to Right
        for(int i = 0; i < row; i++){
            if(matrix[i][0] == 0) // If any element of 0th col has value 0 make col0 to be 0
                col0 = 0;   
            for(int j = 1; j < col; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // Traversing Backward: Bottom to top, Right to left
        for(int i = row-1; i >= 0; i--){
            for(int j = col-1; j >= 1; j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if(col0 == 0)   // Marking every element of 0th col(or Row Dummy Array) to be 0 if col0 is 0
                matrix[i][0] = 0;
        }
        
    }
};

int main(){
    return 0;
}