#include <iostream>
#include <vector>
// #include <cstring>
using namespace std;

vector<string> gss(string s){
    // write your code here
    // base case
    if(s.size() == 0){
        vector<string> ss;
        ss.push_back("");
        return ss;
    }

    // rec case
    // Expectation - abc - ["---","--c", "-b-", "-bc", "a--", "a-c", "ab-", "abc"]
    // faith - bc - ["--", "-c", "b-", "bc"]

    char ch = s[0]; // getting first char of a string
    string ros = s.substr(1); // getting rest of the string

    vector<string> result = gss(ros);   // recursive call

    vector<string> output;

    for (auto x : result){
        output.push_back((""+x));
    }
    
    for (auto x : result){
        output.push_back((ch+x));
    }

    return output;
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
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