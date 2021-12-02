#include <iostream>
#include<string>
using namespace std;
// Print Encoding

void printEncoding(string str, string asf){
    // write your code here
    if(str.size() == 0){
        cout << asf << endl;
        return;
    }

    else if(str.size() == 1){
        char ch = str[0];
        if(ch == '0'){
            return;
        }
        else{
            int chv = ch - '0';
            char code = 'a' + chv - 1;  // Imp Part
            cout << asf + code << endl;     // or printEncoding(str, asf+code) but the 'str' size should reduce to ""
        }
    }

    else{
        // when there are more than 1 char
        // first one char
        char ch = str[0];
        string ros = str.substr(1);
        if(ch == '0'){
            return;
        }
        else{
            int chv = ch - '0';     // atoi(ch) == ch - '0' -> give int value
            char code = 'a' + chv - 1;
            printEncoding(ros, asf + code);
        }

        // First two char
        string ch12 = str.substr(0,2);
        string ros12 = str.substr(2);
        
        // stoi(string_var) & atoi(char_var) - convert string or char into int
        // to_string(int_var) - convert int into string
        if(stoi(ch12) <= 26){
            char code12 = 'a' + stoi(ch12) - 1;
            printEncoding(ros12, asf + code12);
        }
    }
}

int main(){
    string str;
    cin>>str;
    printEncoding(str,"");
    
}