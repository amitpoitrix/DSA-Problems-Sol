#include <iostream>
using namespace std;
int main(int argc, char **argv){
    int t;
    cin >> t;
 
    //write your code here
    while(t--){
        int n;
        cin >> n;
        if(n == 0 || n == 1)
            cout << "not prime" << endl;
        else if(n == 2)
            cout << "prime" << endl;
        else{
            int i;
            for (i = 3; i < n; i++){
                if(n%i == 0){
                    cout << "not prime"<< endl;
                    break;
                }
            }
            if(i == n)
                cout << "prime" << endl;
        }
    }
}