#include<bits/stdc++.h>
using namespace std;

vector<string> kpc = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

vector<string> getKpc(string str){
    // base case 
    if(str.size() == 0){
        vector<string> b;
        b.push_back("");
        return b;
    }

    // rec case
    char ch = str[0];   // Getting first char of string
    string ros = str.substr(1);     // In order to get rest of the string

    vector<string> rres = getKpc(ros);  // rec function

    vector<string> result;

    string val = kpc[ch - '0'];     // i.e., ch-48 as '0' -> 48  getting string at particular index from global vector<string>

    for (int i = 0; i < val.size(); i++){
        char ch2 = val[i];
        for (auto x : rres){
            result.push_back(ch2 + x);
        }
    }
    return result;
}


int main(){
    string s;
    cin >> s;
    vector<string> ans = getKpc(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}