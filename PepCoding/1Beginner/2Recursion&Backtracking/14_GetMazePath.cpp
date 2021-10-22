#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    // base case
    if(sr == dr && sc == dc){
        vector<string> base;
        base.push_back("");
        return base;
    }

    // rec case
    vector<string> hpaths;
    vector<string> vpaths;

    if(sc < dc){
        hpaths = getMazePaths(sr, sc+1, dr, dc);
    }

    if(sr < dr){
        vpaths = getMazePaths(sr+1, sc, dr, dc);
    }

    vector<string> result;

    for (auto x : hpaths){
        result.push_back("h" + x);
    }

    for (auto y : vpaths){
        result.push_back("v" + y);
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
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}