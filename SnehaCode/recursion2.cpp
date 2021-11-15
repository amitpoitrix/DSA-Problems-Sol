#include <iostream>
using namespace std;
int count(int x){
    if(x == 0 || x < 0){
        return x;
    }
    int cnt = cnt + count(x/10);
    return cnt;
}
int main(){
    int x;
    cout<<"enter a number";
    cin>>x;
    cout<<count(x);
    cout << endl;
}