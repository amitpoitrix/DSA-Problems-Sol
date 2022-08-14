#include <bits/stdc++.h>
using namespace std;

// GFG: Count Inversions
// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

// Using Merge Sort
// TC - O(nlogn)
// SC - O(n)
class Solution{
private:
    // Merging two arrays
    long long int mergeSort(long long arr[], long long temp[], int left, int mid, int right){
        int i = left, j = mid, k = left;
        long long int inversionCount = 0;
        
        while((i <= mid - 1) && (j <= right)){
            if(arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else{
                temp[k++] = arr[j++];
                inversionCount += mid - i;
            }
        }
        
        while(i <= mid-1){
            temp[k++] = arr[i++];
        }
        
        while(j <= right){
            temp[k++] = arr[j++];
        }
        
        for(int x = left; x <= right; x++){
            arr[x] = temp[x];
        }
        
        return inversionCount;
    }

    long long int merge(long long arr[], long long temp[], int left, int right){
        int mid = 0;
        long long int inversionCount = 0;
        if(left < right){
            mid = left + (right - left) / 2;
            
            inversionCount += merge(arr, temp, left, mid);
            inversionCount += merge(arr, temp, mid + 1, right);
            
            inversionCount += mergeSort(arr, temp, left, mid + 1, right);
        }
        return inversionCount;
    }

public:
    long long int inversionCount(long long arr[], long long N){
        long long temp[N];
        long long inversionCount = merge(arr, temp, 0, N-1);
        return inversionCount;
    }
};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends