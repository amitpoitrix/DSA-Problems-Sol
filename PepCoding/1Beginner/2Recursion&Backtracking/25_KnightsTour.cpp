#include<bits/stdc++.h>
using namespace std;

//function to display the 2-d array
void display(vector<vector<int>>& chess) {
  for (int i = 0; i < chess.size(); i++) {
    for (int j = 0; j < chess.size(); j++) {
      cout << chess[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void printKnightsTour(vector<vector<int>>& chess, int n, int r, int c, int upcomingMove) {
  //write your code here
    // base case
    if(r < 0 || c < 0 || r >= chess.size() || c >= chess[0].size() || chess[r][c] > 0){
        return;
    }

    if(upcomingMove == chess.size() * chess[0].size()){
        chess[r][c] = upcomingMove;
        display(chess);
        chess[r][c] = 0;
        return;
    }

    // rec case
    chess[r][c] = upcomingMove;
    printKnightsTour(chess, n, r-2, c+1, upcomingMove + 1);
    printKnightsTour(chess, n, r-1, c+2, upcomingMove + 1);
    printKnightsTour(chess, n, r+1, c+2, upcomingMove + 1);
    printKnightsTour(chess, n, r+2, c+1, upcomingMove + 1);
    printKnightsTour(chess, n, r+2, c-1, upcomingMove + 1);
    printKnightsTour(chess, n, r+1, c-2, upcomingMove + 1);
    printKnightsTour(chess, n, r-1, c-2, upcomingMove + 1);
    printKnightsTour(chess, n, r-2, c-1, upcomingMove + 1);
    chess[r][c] = 0;    // Becoz we're backtracking i.e., We're checking all possible combinations/solutions
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> chess(n, vector<int> (n));
    int row,col;
    cin >> row;
    cin >> col;
    printKnightsTour(chess, n, row, col, 1);
}