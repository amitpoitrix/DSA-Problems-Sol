#include <iostream>
using namespace std;
int power(int x,int n){
    if (n==0){
        return 1;
    }
    int so=power(x,n-1);
    int output=x*so;
    return output;

}
int main(){
    int x ,n;
    cout<<"enter value of x"<<endl;
    cin>>x;

    cout<<"enter value of n"<<endl;
    cin>>n;

    cout<<power(x,n);


}

    