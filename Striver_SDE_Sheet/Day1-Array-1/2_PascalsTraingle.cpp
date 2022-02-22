#include<iostream>
#include<vector>
// Striver SDE Sheet - Day1-Array-Part1
// Leetcode : 118. Pascal's Triangle
// 3 types of Ques can be asked from Pascal's Traingle
// 1st Find Pascals Triangle at particular row & col compute (row - 1) C (col - 1) for 1 based indexing & it'll take O(n) time

// 2nd Find the nth row of Pascal's Traingle
// Tc - O(n)
class Solution12{
public:
    std::vector<int> nthRowPascalTraingle(int row){
        // 0 based indexing
        std::vector<int> res(row + 1);
        // nCo = 1
        res[0] = 1;

        // Computing for nC1, nC2..... nCn but in O(n)
        for (int i = 1; i <= row ; i++){
            res[i] = (res[i - 1] * (row - i + 1)) / i;
        }
        
        return res;
    }
};

// 3rd Return the Pascals Triangle
// TC - O(m * n)
// SC - O(m * n)
class Solution3 {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> triangle(numRows);

        for (int i = 0; i <= numRows - 1; i++){
            // Resizing each row to no. of column
            triangle[i].resize(i + 1);
            // Making first and last col of each row to be 1
            triangle[i][0] = triangle[i][i] = 1;
            // from 2nd row(0 based indexing) j traversal will run
            for (int j = 1; j <= i - 1; j++){
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }

        return triangle;     
    }
};

int main(){
    // run on LEETCODE for Solution3

    Solution12 obj;
    
    for (auto x : obj.nthRowPascalTraingle(4)){
        std::cout << x << " ";
    }

    return 0;
}