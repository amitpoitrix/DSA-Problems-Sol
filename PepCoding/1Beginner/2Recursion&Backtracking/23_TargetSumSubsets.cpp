#include<bits/stdc++.h>
using namespace std;

// set is the subset
// sos is sum of subset
// tar is target
void printTargetSumSubsets(vector<int> arr, int idx, string set, int sos, int tar) {
  //write your code here
    // base case
    if(idx == arr.size()){
        if(sos == tar){
            cout << set << "." << endl;
        }
        return;
    }

    // rec case
    printTargetSumSubsets(arr, idx + 1, set + to_string(arr[idx]) + ", ", sos + arr[idx], tar);
    printTargetSumSubsets(arr, idx + 1, set, sos, tar);
}


int main() {
    int n;
    cin >> n;
    vector<int> arr(n); // size of vector should be specify first or else it'll return segmentation fault
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int tar;
    cin >> tar;
    printTargetSumSubsets(arr, 0, "", 0, tar);
    return 0;
}