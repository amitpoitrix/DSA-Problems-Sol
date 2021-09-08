#include<bits/stdc++.h>
using namespace std;

// int maxSumSubarray(vector<int> A) {
//     int cs = 0;
//     int ms = 0;
//     for (int i = 0; i < A.size(); i++){
//         cs += A[i];
//         if(cs < 0)
//             cs = 0;  // Assuming all -ve sum as 0
//         ms = max(ms, cs);
//     }
//     return ms;
// }

int maxSumSubarray(vector<int> A) {
    // For checking the -ve elements sum which is nothing but an -ve element close to 0 and if any +ve element occur than apply kadane's algo
    bool f =true;
    int rr=INT_MIN;
    for(auto x : A){
        if(x >0 ) f = false;
        if(x > rr) rr = x;
    }
    if(f) return rr;
    
    int ms = 0;
    int cs  = 0;
    
    int arraySize = A.size();
    for (int i = 0; i < arraySize; i++) {
        cs = cs + A[i];
        if (cs < A[i]) {
            cs = A[i];
        }
        ms = max(ms, cs);
    }
    return ms;
    
}


int main(){
    vector<int> arr = {-5,-1,1,-2,-1};
    int sum = maxSumSubarray(arr);
    cout << "Largest Subarray Sum = " << sum;

    cout << endl;
    return 0;
}