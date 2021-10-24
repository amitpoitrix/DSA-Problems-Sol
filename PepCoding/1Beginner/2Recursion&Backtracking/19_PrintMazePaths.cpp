#include <iostream>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf){
    // write your code here
    // smart base case 
    if(sr > dr || sc > dc)
        return;
    else if(sr == dr && sc == dc){
        cout << psf << endl;
        return;
    }

    // stupid rec case
    printMazePaths(sr, sc+1, dr, dc,psf + "h");
    printMazePaths(sr+1, sc, dr, dc,psf + "v");
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    printMazePaths(0, 0, n - 1, m - 1, "");
}