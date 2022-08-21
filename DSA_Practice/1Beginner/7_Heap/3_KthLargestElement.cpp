#include <bits/stdc++.h>
using namespace std;

// k largest elements
// https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1

class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // Kth Largest Element requires Min Heap
	    priority_queue<int, vector<int>, greater<int>> minH;
	    
	    for(int i = 0; i < n; i++){
	        minH.push(arr[i]);
	        if(minH.size() > k)
	            minH.pop();
	    }
	    
	    vector<int> res;
	    while(!minH.empty()){
	        res.push_back(minH.top());
	        minH.pop();
	    }
	    
	    sort(res.begin(), res.end(), greater<int>());
	    
	    return res;
	}

};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}