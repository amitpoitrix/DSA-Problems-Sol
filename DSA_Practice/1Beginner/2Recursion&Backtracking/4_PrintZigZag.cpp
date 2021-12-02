#include<iostream>
using namespace std;
// Print Zig Zag

void pzz(int n){
    // write your code here
    if(n == 0)
        return;
    
    cout << n << " ";   // Pre n
    pzz(n-1);           // Left Call
    cout << n << " ";   // In n
    pzz(n-1);           // Right Call
    cout << n << " ";   // Post n
}

int main(){
    int n; cin>>n;
    pzz(n);
}
