#include<iostream>
using namespace std;
// Print maze paths with jump

void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
    // write your code here
    // Stupid base case
    if(sr == dr && sc == dc){
        cout << psf << endl;
        return;
    }

    // smart rec case
    // for horizontal
    for (int i = 1; i <= dc-sc; i++){
        printMazePaths(sr, sc+i, dr, dc, psf + "h" + to_string(i));
    }

    // for vertical
    for (int i = 1; i <= dr-sr; i++){
        printMazePaths(sr+i, sc, dr, dc, psf + "v" + to_string(i));
    }

    // for diagonal
    for (int i = 1; i <= dc-sc && i <= dr-sr; i++){
        printMazePaths(sr+i, sc+i, dr, dc, psf + "d" + to_string(i));
    }
    
}

int main() {
    int n ;
    int m ;cin>>n>>m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}