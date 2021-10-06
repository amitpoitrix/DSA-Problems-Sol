#include<bits/stdc++.h>
using namespace std;
// DSA450 : Max Sum where no 2 elements are adjacent

int FindMaxSum(int arr[], int n){
    int sumOdd=0, sumEven =0;
    for (int i = 0; i < n; i++){
        if(i&1){
            sumOdd += arr[i];
        }
        else{
            sumEven += arr[i];
        }
    }

    return sumOdd>sumEven?sumOdd:sumEven;
}

int main(){
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(int);

    cout << FindMaxSum(arr, n);

    cout << endl;
    return 0;
}