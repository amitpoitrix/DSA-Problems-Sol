#include <bits/stdc++.h>
using namespace std;


int main(){
    int a = 1;
    int b = 1;

    if(max(a, b) == a)
        cout << "a :" << min(a, b) << "\n";
    else if(min(a, b) == b)
        cout << "b :" << min(a, b) << "\n";

    return 0;
}
