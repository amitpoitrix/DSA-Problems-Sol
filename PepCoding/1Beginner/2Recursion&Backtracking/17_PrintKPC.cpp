#include <iostream>
using namespace std;
// Print KPC

// This Recursive Method Approach is called level n option approach
string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
// OR vector<string> codes = {"", "", ""};

void printKPC(string ques, string asf){
    // write your code here
    // base case
    if(ques.size() == 0){
        cout << asf << endl;
        return;
    }

    // rec case
    char ch = ques[0];
    string roq = ques.substr(1);

    string charfromch = codes[ch - '0'];

    for (int i = 0; i < charfromch.size(); i++){
        char cho = charfromch[i];
        printKPC(roq, asf + cho);
    }

}

int main(){
    string str;
    cin >> str;
    printKPC(str, "");
}