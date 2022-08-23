#include <bits/stdc++.h>
using namespace std;

// GFG: K closest elements
// https://practice.geeksforgeeks.org/problems/k-closest-elements3619/1

// Using Binary Search - As elements are already sorted
// TC - O(logn)
// SC - O(K)
class Solution{   
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        vector<int> res;
        
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = idx - 1;
        int right = idx + (arr[idx] == x);
        
        while(k--){
            int a = +1e9;
            int b = +1e9;
            
            if(left >= 0)
                a = abs(arr[left] - x);
            if(right < n)
                b = abs(arr[right] - x);
            
            if(min(a, b) == b)
                res.push_back(arr[right++]);
            else
                res.push_back(arr[left--]);
        }
        
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}