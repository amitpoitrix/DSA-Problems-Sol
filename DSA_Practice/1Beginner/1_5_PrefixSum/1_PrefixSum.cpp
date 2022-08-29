#include<bits/stdc++.h>
using namespace std;

// Declaring array globally of max size N (10^5) 
const int N = 1e5 + 10;
int a[N];   // While declaring array globally it's element is initialise to 0
int pf[N];

int main(){
    int n;
    cin >> n;
    // 1 - based indexing of array
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        // Computing prefix sum outside query
        pf[i] = pf[i-1] + a[i]; // Becoz of 1 based indexing no need to handle pf[0] case as its already 0
    }

    // query is similar to testcase
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;

        // Approach 1: TC - O(n) + O(n * q) ~ O(n^2)
        // long long sum = 0;
        // for(int i = l; i <= r; i++){
        //     sum += a[i];
        // }
        // cout << sum << "\n";

        // Approach 2: TC - O(N) + O(Q) ~ O(N)
        cout << pf[r] - pf[l-1] << "\n";
    }

    return 0;
}

// Input
// 6
// 3 6 2 8 9 2
// 4
// 2 3
// 4 6
// 1 5
// 3 6