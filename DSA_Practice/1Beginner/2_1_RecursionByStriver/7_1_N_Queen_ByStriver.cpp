#include<iostream>
#include<vector>
using namespace std;
// Recursion By Striver : 51. N-Queens

// Approch 1 : Using Recursion & extra function TC - O(n^2)
class Solution {
private:
    bool isSafe(int row, int col, std::vector<std::string> &board, int n){
        // As we are placing queen in new col & row than we have to check 
        // only 3 directions i.e., leftRow, upwardDiagonal & downwardDiagonal
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

    void calcNQueen(int col, vector<vector<string>> &ans, vector<string> &board, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                calcNQueen(col + 1, ans, board, n);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;  // 3D [vector][vector][string]
        vector<string> board(n);  // 2D [vector][string]

        string s(n, '.');
        for (int i = 0; i < n; i++){
            board[i] = s;
        }

        calcNQueen(0, ans, board, n);
        return ans;
    }
};

// Approach 2 : Using Recursion & HashMap - optimized
class Solution2{
private:
    void calcNQueens(int col, vector<vector<string>> &ans, vector<string> &board, int n, vector<int> &leftRow, 
    vector<int> &upwardDiagonal, vector<int> &downwardDiagonal){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++){
            if(leftRow[row] == 0 && downwardDiagonal[col + row] == 0 && upwardDiagonal[n - 1 + col - row] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                downwardDiagonal[col + row] = 1;
                upwardDiagonal[n - 1 + col - row] = 1;
                calcNQueens(col + 1, ans, board, n, leftRow, upwardDiagonal, downwardDiagonal);
                upwardDiagonal[n - 1 + col - row] = 0;
                downwardDiagonal[col + row] = 0;
                leftRow[row] = 0;
                board[row][col] = '.';
            }   
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++){
            board[i] = s;
        }
        // Declaring HashMap
        vector<int> leftRow(n,0), upwardDiagonal(2 * n -1, 0), downwardDiagonal(2 * n -1, 0);
        calcNQueens(0, ans, board, n, leftRow, upwardDiagonal, downwardDiagonal);
        return ans;
    }
};


int main(){
    int n = 4;

    Solution2 obj;
    for (auto x : obj.solveNQueens(n)){
        for (auto y : x){
            for (auto z : y){
                std::cout << z << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    return 0;
}