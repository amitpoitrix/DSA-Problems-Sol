#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    // base case LLT
    if(n == 1)
        return 1;

    // rec case HLT
    int fnm1 = factorial(n-1);  // faith
    int fn = n * fnm1;  // Expectation
    return fn;
}

int main(){
    int n;
    cin >> n;
    cout << factorial(n);

    cout << endl;
    return 0;
}