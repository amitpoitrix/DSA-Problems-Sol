#include<iostream>
using namespace std;

int arraySum(int array[], int n){
    // base case
    if(n <= 0){
        return 0;
    }
    // recursive case
    return array[n - 1] + arraySum(array, n-1);
}

int main(){
    int n;
    cin >> n;
    int array[n];

    for (int i = 0; i < n; i++){
        cin >> array[i];
    }
    
    cout << arraySum(array, n);

    return 0;
}