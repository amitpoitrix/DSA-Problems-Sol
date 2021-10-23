#include <iostream>
using namespace std;
// Print Subsequence

void printSS(string ques, string ans){
    // write your code here
    // base case
    if(ques.size() == 0){
        cout << ans << endl;
        return;
    }

    // rec case
    char ch = ques[0];
    string ros = ques.substr(1);

    printSS(ros, ans + ch);
    printSS(ros, ans + "");
}

int main(){
    string str;
    cin >> str;
    printSS(str, "");
}