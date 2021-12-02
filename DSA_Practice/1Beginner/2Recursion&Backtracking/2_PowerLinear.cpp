#include<iostream>
using namespace std;
// Power linear approach

int power(int x,int n){
   // write your code here
   // base case
    if(n == 0)
        return 1;

   // rec case
   int xnm1 = power(x, n-1);    // faith
   int xn = x * xnm1;   // meeting expectation using faith
   return xn;
}

int main(){
    int n,x; cin>>x>>n;
    cout<<power(x,n);
    cout << endl;
}
