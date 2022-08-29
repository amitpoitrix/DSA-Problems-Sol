#include <bits/stdc++.h>
using namespace std;

// Codechef - GCDQ
// https://www.codechef.com/problems/GCDQ

int main() {
	// your code goes here
	int T;
	cin >> T;
	while(T--){
	    int N, Q;
	    cin >> N >> Q;
	    int arr[N];
        int forward[N];
        int backward[N];
	    for(int i = 1; i <= N; i++){
	        cin >> arr[i];
	    }
	    
	    forward[0] = backward[N+1] = 0;
	    
	    for(int i = 1; i <= N; i++){
	        forward[i] = __gcd(arr[i], forward[i-1]);
	    }
	    
	    for(int i = N; i >= 1; i--){
	        backward[i] = __gcd(arr[i], backward[i+1]);
	    }
	    
	    while(Q--){
	        int L, R;
	        cin >> L >> R;
	        
	        cout << __gcd(forward[L-1], backward[R+1]) << "\n";
	    }
	}
	
	return 0;
}
