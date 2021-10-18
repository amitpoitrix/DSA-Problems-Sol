#include <iostream>
using namespace std;

void display(int arr[], int idx, int n){
    // write your code here
    // rec case
    if(idx == n)
        return;

    // base case
    // Expectation
    display(arr, idx+1, n);     // faith
    cout << arr[idx] << endl;   // faith
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    display(arr, 0, n);
}
