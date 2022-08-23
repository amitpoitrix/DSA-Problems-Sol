#include<bits/stdc++.h>
using namespace std;

// GFG: Sum of elements between k1'th and k2'th smallest elements
// https://practice.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/1

// Using Heap
// TC - O(nlogk)
// SC - O(k)
class Solution{
private:
    long long kthSmallest(long long A[], long long N, long long K){
        // Using Max Heap for Kth Smallest element
        priority_queue<long long> maxH;
        
        for(long long i = 0; i < N; i++){
            maxH.push(A[i]);
            
            if(maxH.size() > K){
                maxH.pop();
            }
        }
        
        return maxH.top();
    }

public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2){
        // Your code goes here
        long long first = kthSmallest(A, N, K1);
        long long second = kthSmallest(A, N, K2);
        
        long long sum = 0;
        for(long long i = 0; i < N; i++){
            if(A[i] > first && A[i] < second)
                sum += A[i];
        }
        
        return sum;
    }
};

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}