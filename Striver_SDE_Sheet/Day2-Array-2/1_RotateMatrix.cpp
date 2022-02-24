#include<iostream>
#include<vector>
#include<algorithm>
// Striver SDE Sheet - Day2-Array-Part2
// Leetcode : 48. Rotate Image
// Here we have to rotate the image by 90 degree in-place(i.e., we can modify the input matrix)

// BruteForce Approach - Take each row elements and place it in another matrix column(backward)
// TC - O(m * n)
// SC - O(m * n)
// As we are using Extra matrix which is not recommended
class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<std::vector<int>> newMatrix(m, std::vector<int>(n, 0));

        // Inserting the elements into new Matrix
        for (int i = 0; i <= m-1; i++){
            for (int j = 0; j <= n-1; j++){
                newMatrix[j][n - 1 - i] = matrix[i][j];
            }
        }
        
        // Inserting back the elements from newMatrix to original matrix
        for (int i = 0; i <= m - 1; i++){
            for (int j = 0; j <= n - 1; j++){
                matrix[i][j] = newMatrix[i][j];
            }
        }      
    }
};

// Optimized Method - First we'll transpose the matrix and then we'll reverse the order of each row of elements 
class Solution1 {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Transposing a Matrix
        for (int i = 0; i <= m - 1; i++){
            // traversing j from 0 to i - 1
            for (int j = 0; j <= i - 1; j++){
                std::swap(matrix[j][i], matrix[i][j]);
            }
        }
        
        for (int i = 0; i <= m - 1; i++){
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};


int main(){

    return 0;
}