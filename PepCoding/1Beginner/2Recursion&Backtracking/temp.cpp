#include <iostream>
#include <vector>
using namespace std;

void Permute(string s, int i = 0){
    // BASE CASE
    if (i == s.length() - 1){
        cout << s << endl;
        return;
    }
    
    // Rec case
    for (int j = i; j < s.length(); j++){
        swap(s[i], s[j]);
        Permute(s, i + 1);
        swap(s[i], s[j]);
    }
}

int main(){
    string str;
    cin >> str;
    Permute(str, 0);
    
    return 0;
}