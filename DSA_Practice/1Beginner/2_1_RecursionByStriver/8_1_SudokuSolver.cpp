#include<iostream>
#include<vector>
#include<unordered_set>
// Recursion by Striver : Leetcode 37. Sudoku Solver

// Using Recursion
class Solution {
private:
    bool isValid(int row, int col, std::vector<std::vector<char>> &board, char c){
        for (int i = 0; i < 9; i++){
            // Condn 1 : Row should have unique elements from 1-9
            if(board[row][i] == c)
                return false; 

            // Condn 2 : Col should have unique elements from 1-9
            if(board[i][col] == c)
                return false;

            // Condn 3 : Each 9 3 x 3 box should have unique elements from 1-9
            if(board[3 * (row/3) + (i/3)][3 * (col/3) + (i % 3)] == c)
                return false;
        }
        
        return true;
    }

    // Recursive function
    bool solve(std::vector<std::vector<char>> &board){
        for (int row = 0; row < 9; row++){
            for (int col = 0; col < 9; col++){

                if(board[row][col] == '.'){

                    for (char c = '1'; c <= '9'; c++){
                        if(isValid(row, col, board, c)){
                            board[row][col] = c;
                            // Recursive Call
                            if(solve(board) == true)
                                return true;
                            // If return is false than empty the cell while backtracking otherwise don't
                            else
                                board[row][col] = '.';
                        }
                    }
                    
                    return false;
                }
            }
        }
        
        return true;
    }

public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        solve(board);
    }
};


// Leetcode 36. Valid Sudoku - Imp 

// Here whatever the cell is filled in 9 x 9 sudoku we just have to check whether there position is valid or not
class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Taking 3 2D 9 x 9 matrix
        std::unordered_set<char> rowSet[board.size()];
        std::unordered_set<char> colSet[board.size()];
        std::unordered_set<char> squareSet[board.size()];

        for (int row = 0; row < board.size(); row++){
            for (int col = 0; col < board[0].size(); col++){

                if(board[row][col] != '.'){

                    char c = board[row][col];
                    int sPos = (row/3) * 3 + (col/3);   // to get the 3 x 3 square box No. which is from 0 to 8 i.e., total 9

                    if(rowSet[row].count(c) || colSet[col].count(c) || squareSet[sPos].count(c))
                        return false;
                    
                    rowSet[row].insert(c);
                    colSet[col].insert(c);
                    squareSet[sPos].insert(c);                
                }
                
            }
        }
        
        return true;
    }
};

int main(){
    

    return 0;
}