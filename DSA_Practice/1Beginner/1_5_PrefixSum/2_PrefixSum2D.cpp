#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int arr[N][N];
int pf[N][N];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
            pf[i][j] = arr[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
        }
    }

    int q;
    cin >> q;
    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        // Approach 1: TC - O(n^2) + O(q * n^2) ~ O(n^3)
        // long long sum = 0;
        // for(int i = a; i<= c; i++){
        //     for(int j = b; j <= d; j++){
        //         sum += arr[i][j];
        //     }
        // }
        // cout << sum << "\n";

        // Approach 2: TC - O(N^2) + O(Q) ~ O(N^2)
        cout << pf[c][d] - pf[a-1][d] - pf[c][b-1] + pf[a-1][b-1] << "\n";
    }

    return 0;
}

// Input:
// 3
// 3 6 2
// 8 9 2
// 3 4 1
// 2
// 1 1 2 2
// 1 2 3 3