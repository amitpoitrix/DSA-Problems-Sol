#include <iostream>
using namespace std;
void print(int x){
    // base case 
    if(x == 1){
        cout << x << " ";
        return;
    }

    // rec case
    
    print(x-1);
    cout << x << " ";
}
int main(){
    int x;
    cout<<"enter a number;"<<endl;
    cin>>x;
    print(x);
    cout << endl;

}