#include<iostream>
#include<vector>
// Leetcode : 52. N-Queens II
// Count no. of N Queen possible

// Approach 1 : Using Recursion & extra function
class Solution {
private:
    bool isSafe(int row, int col, std::vector<std::string> &board, int n){
        // As we are placing queen in new col & row than we have to check only 3 directions i.e., leftRow, upwardDiagonal & downwardDiagonal
        int dupRow = row;
        int dupCol = col;

        // checking leftRow
        while (col >= 0){
            if(board[row][col] == 'Q')
                return false;

            col--;
        }

        // Checking upwardDiagonal
        row = dupRow;
        col = dupCol;
        while (row >= 0 && col >= 0){
            if(board[row][col] == 'Q')
                return false;
            
            row--;
            col--;
        }
        
        // Checking downwardDiagonal
        row = dupRow;
        col = dupCol;
        while (row < n && col >= 0){
            if(board[row][col] == 'Q')
                return false;

            row++;
            col--;
        }
        
        return true;
    }

    void calcNQueen(int col, int &count, std::vector<std::string> &board, int n){
        if(col == n){
            count++;
            return;
        }

        for (int row = 0; row < n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                calcNQueen(col + 1, count, board, n);
                board[row][col] = '.';
            }
        }
    }

public:
    int totalNQueens(int n) {
        int count = 0;
        std::vector<std::string> board(n);
        std::string s(n, '.');
        for (int i = 0; i < n; i++){
            board[i] = s;
        }

        calcNQueen(0, count, board, n);
        return count;
    }
};


// Approach 2 : Using Recursion & HashMap
class Solution2 {
private:
    void calcNQueens(int col, int &count, int n, std::vector<int> &leftRow, std::vector<int> &upwardDiagonal, 
    std::vector<int> &downwardDiagonal){
        if(col == n){
            count++;
            return;
        }

        for (int row = 0; row < n; row++){
            if(leftRow[row] == 0 && downwardDiagonal[col + row] == 0 && upwardDiagonal[n - 1 + col - row] == 0){
                leftRow[row] = 1;
                downwardDiagonal[col + row] = 1;
                upwardDiagonal[n - 1 + col - row] = 1;
                calcNQueens(col + 1, count, n, leftRow, upwardDiagonal, downwardDiagonal);
                upwardDiagonal[n - 1 + col - row] = 0;
                downwardDiagonal[col + row] = 0;
                leftRow[row] = 0;
            }   
        }
    }
    
public:
    int totalNQueens(int n) {
        int count = 0;
        // Declaring HashMap
        std::vector<int> leftRow(n,0), upwardDiagonal(2 * n -1, 0), downwardDiagonal(2 * n -1, 0);
        calcNQueens(0, count, n, leftRow, upwardDiagonal, downwardDiagonal);
        return count;
    }
};

int main(){
    int n = 10;

    Solution obj;
    std::cout << obj.totalNQueens(n);

    return 0;
}