#include <iostream>
using namespace std;

void printPermutations(string str, string asf){
    // write your code here
    // base case
    if(str.size() == 0){
        cout << asf << endl;
        return;
    }

    // rec case
    for (int i = 0; i < str.size(); i++){
        char ch = str[i];
        string strLeft = str.substr(0,i);
        string strRight = str.substr(i+1);
        string ros = strLeft + strRight;
        printPermutations(ros, asf + ch);
    }
    
}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
    
}