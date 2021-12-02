#include<iostream>
using namespace std;
// Calculate first occurence using recursion

int firstIndex(int arr[], int idx, int x, int n){
    // write your code here
    if(idx == n)
        return -1;
    
    // Expectation
    if(arr[idx] == x)
        return idx;
    else{
        int fiisa = firstIndex(arr, idx+1, x, n);
        return fiisa;
    }
}

int main()
{
    int n;
    cin >> n;
    int d;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> d;
    int p = firstIndex(arr, 0, d, n);
    cout << p << endl;
}