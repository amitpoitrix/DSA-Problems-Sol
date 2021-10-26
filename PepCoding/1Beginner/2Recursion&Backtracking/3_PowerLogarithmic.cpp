#include<iostream>
using namespace std;
// Power Logarithmic - Optimized Approach

int powerLogarithmic(int x,int n){
    // write your code here
    // base case
    if(n == 0)
        return 1;

    // rec case
    int xnb2 = powerLogarithmic(x, n/2);
    int xn = xnb2 * xnb2;
    if(n%2 ==1)
        xn = x * xn;
    return xn;
}

int main(){
    int x,n; cin>>x>>n;
    cout<<powerLogarithmic(x,n);
}