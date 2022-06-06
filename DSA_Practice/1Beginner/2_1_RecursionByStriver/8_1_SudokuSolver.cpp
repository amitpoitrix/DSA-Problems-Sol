#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
// Recursion by Striver : Leetcode 37. Sudoku Solver
// https://leetcode.com/problems/sudoku-solver/

// Using Recursion
class Solution {
private:
    bool isValid(int row, int col, vector<vector<char>> &board, char c){
        for (int i = 0; i < 9; i++){
            if(board[row][i] == c)
                return false; 

            if(board[i][col] == c)
                return false;

            if(board[3 * (row/3) + (i/3)][3 * (col/3) + (i % 3)] == c)
                return false;
        }
        return true;
    }

    // Recursive function
    bool solve(vector<vector<char>> &board){
        for (int row = 0; row < 9; row++){
            for (int col = 0; col < 9; col++){
                if(board[row][col] == '.'){

                    for (char c = '1'; c <= '9'; c++){
                        if(isValid(row, col, board, c)){
                            board[row][col] = c;
                            if(solve(board) == true)
                                return true;
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
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};


// Leetcode 36. Valid Sudoku - Imp 
// https://leetcode.com/problems/valid-sudoku/

// Here whatever the cell is filled in 9 x 9 sudoku we just have to check whether there position is valid or not
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // creating 3 hashset array[] (kind of adjacency list) for row, col & 3x3 square box
        unordered_set<char> rowSet[board.size()];   // [] is used not ()
        unordered_set<char> colSet[board.size()];
        unordered_set<char> squareSet[board.size()];

        for (int row = 0; row < board.size(); row++){
            for (int col = 0; col < board[0].size(); col++){
                // check only already filled cell
                if(board[row][col] != '.'){

                    char c = board[row][col];
                    // to get the 3 x 3 square box pos which is from 0 to 8 i.e., total 9
                    int sPos = (row/3) * 3 + (col/3);
                    // if c is already present in any of the 3 hashset than return false 
                    if(rowSet[row].count(c) || colSet[col].count(c) || squareSet[sPos].count(c))
                        return false;
                    // else insert that c in all 3 hashset
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