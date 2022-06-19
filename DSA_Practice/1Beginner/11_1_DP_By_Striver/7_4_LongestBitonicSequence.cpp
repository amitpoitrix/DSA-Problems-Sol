#include<iostream>
#include<vector>
using namespace std;
// DP by Striver: DP 46. Longest Bitonic Subsequence | LIS

class Solution{
public:
    int longestBitonicSequence(vector<int>& arr, int n) {
        // computing lis from left to right i.e., dp1
        vector<int> dp1(n, 1);
        for(int idx = 0; idx < n; idx++){
            for(int prev_idx = 0; prev_idx < idx; prev_idx++){
                if(arr[idx] > arr[prev_idx] && dp1[idx] < 1 + dp1[prev_idx])
                    dp1[idx] = 1 + dp1[prev_idx];
            }
        }
        
        // computing lis from right to left i.e., dp2
        int maxi = 0;
        vector<int> dp2(n, 1);
        for(int idx = n-1; idx >= 0; idx--){
            for(int prev_idx = n-1; prev_idx > idx; prev_idx--){
                if(arr[idx] > arr[prev_idx] && dp2[idx] < 1 + dp2[prev_idx])
                    dp2[idx] = 1 + dp2[prev_idx];
            }
            // Computing Longest Bitonic Subsequence
            maxi = max(maxi, dp1[idx] + dp2[idx] - 1);
        }

        return maxi;
    }
};

int main(){
    return 0;
}
