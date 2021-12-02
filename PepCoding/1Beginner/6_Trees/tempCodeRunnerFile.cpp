#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int, int> mp;
    mp[1] = 2;
    mp[2] = 4;

    mp.insert({5,7});

    for (auto x : mp){
        cout << x.first << " -> " << x.second << endl;
    }
    

    cout << endl;
    return 0;
}