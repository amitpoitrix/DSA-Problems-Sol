#include<bits/stdc++.h>
using namespace std;
// Sudoku Code - CM

bool isSafe(int mat[][9], int i, int j, int no){
    // checking for no. already there in row & col or not
    for (int k = 0; k < 9; k++){
        if(mat[k][j] == no || mat[i][k] == no){
            return false;
        }
    }

    // checking the no. if its already there in subgrid or not
    int sx = (i/3)*3;   // Start x of Subgrid
    int sy = (j/3)*3;   // Start y of Subgrid

    for (int x = sx; x < sx + 3; x++){
        for (int y = sy; y < sy + 3; y++){
            if(mat[x][y] == no){
                return false;
            }
        }
    }
    
    return true;
}

bool solveSudoku(int mat[][9], int i, int j, int n){
    // base case
    if(i == n){
        // print the solution
        for (int x = 0; x < n; x++){
            for (int y = 0; y < n; y++){
                cout << mat[x][y] << " ";
            }
            cout << endl;
        }
        cout << endl;

        return true;
    }

    // rec case
    // if we reaches end of a particular row
    if(j == n){
        return solveSudoku(mat, i+1, 0, n);
    }

    // if we encouner any prefilled value
    if(mat[i][j] != 0){
        return solveSudoku(mat, i, j+1, n);
    }

    // Now we'll decide which no. should be place at (i,j)
    for (int no = 1; no <= n; no++){
        if(isSafe(mat, i, j, no)){
            mat[i][j] = no;
            bool success = solveSudoku(mat, i, j+1, n);
            if(success){
                return true;
            }
        }
    }

    // Backtracking step
    mat[i][j] = 0;
    return false;
}

int main(){
    int n = 9;
    int mat[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9},
    };

    if(!solveSudoku(mat, 0, 0, n)){
        cout << "No Solution Exist !!!";
    }

    cout << endl;
    return 0;
}