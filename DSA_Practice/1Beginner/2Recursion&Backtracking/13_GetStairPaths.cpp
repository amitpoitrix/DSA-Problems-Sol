#include<bits/stdc++.h>
using namespace std;

vector<string> getStairPath(int n){
    // base case
    if(n == 0){
        vector<string> base;
        base.push_back("");
        return base;
    }
    else if(n < 0){
        vector<string> baseN;
        return baseN;
    }

    // rec case
    // Expectation - to get the path from (n -> 0)
    // Faith - to get the path from (n-1 -> 0), (n-2 -> 0) & (n-3 -> 0) as we can make jump of 1, 2 & 3
    vector<string> paths1 = getStairPath(n-1); // 1 jump
    vector<string> paths2 = getStairPath(n-2); // 2 jump.
    vector<string> paths3 = getStairPath(n-3); // 3 jump

    vector<string> result;

    for (auto x : paths1){
        result.push_back("1"+x);
    }
    
    for (auto x : paths2){
        result.push_back("2"+x);
    }

    for (auto x : paths3){
        result.push_back("3"+x);
    }

    return result;
}

int main(){
    int n;
    cin >> n;

    vector<string> rres = getStairPath(n);

    int cnt = 0;
    cout << "[";
    for (auto x : rres){
        if(cnt != rres.size()-1)
            cout << x << ", ";
        else
            cout << x;
        cnt++;
    }
    cout << "]";

    cout << endl;
    return 0;
}