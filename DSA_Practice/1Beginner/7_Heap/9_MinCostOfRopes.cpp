#include <bits/stdc++.h>
using namespace std;

// GFG: Minimum Cost of ropes
// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

// Using heap
// TC - O(nlogn)
// SC - O(n)
class Solution{
public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>> minH;
        
        // Inserting all elements of arr[] in minH
        for(int i = 0; i < n; i++){
            minH.push(arr[i]);
        }
        
        long long cost = 0;
        while(minH.size() >= 2){
            long long first = minH.top();
            minH.pop();
            long long second = minH.top();
            minH.pop();
            
            cost += first + second;
            
            minH.push(first + second);
        }
        
        return cost;
    }
};

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}