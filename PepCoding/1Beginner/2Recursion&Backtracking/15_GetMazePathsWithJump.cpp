#include<iostream>
#include<vector>
using namespace std;
// Get Maze Paths with Jumps - so here we can have a jump of J1, J2, J3 and so on...

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePathsWithJumps(int sr, int sc, int dr, int dc) {
    // base case
    if(sr == dr && sc == dc){
        vector<string> base;
        base.push_back("");
        return base;
    }
    else if(sr > dr || sc > dc){
        vector<string> base;
        return base;
    }
    
    // rec case
    vector<string> result;

    // Horizontal Jump
    for (int j = 1; j <= dc-sc; j++){
        vector<string> hpaths = getMazePathsWithJumps(sr, sc+j, dr, dc);
        for (string x : hpaths){
            result.push_back("h" + to_string(j) + x);   // to_string(2) - this function will convert 2 as int to string i.e., "2"
        }
    }

    // vertical Jump
    for (int j = 1; j <= dr-sr; j++){
        vector<string> vpaths = getMazePathsWithJumps(sr+j, sc, dr, dc);
        for (string y : vpaths){
            result.push_back("v" + to_string(j) + y);
        }
    }
    
    // diagonal Jump
    for (int j = 1; j <= dr-sr && j <= dc-sc; j++){
        vector<string> dpaths = getMazePathsWithJumps(sr+j, sc+j, dr, dc);
        for (string z : dpaths){
            result.push_back("d" + to_string(j) + z);
        }
    }
    
    return result;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}

int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePathsWithJumps(0,0,n-1,m-1);

    display(ans);

    return 0;
}