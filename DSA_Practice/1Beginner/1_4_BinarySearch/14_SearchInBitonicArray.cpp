#include<iostream>
#include<vector>
using namespace std;

// Find an element in Bitonic array
// https://www.geeksforgeeks.org/find-element-bitonic-array/

class Solution{
public:
    int peakBitonic(int start, int end, vector<int> &arr){
        int n = arr.size();
        while(start <= end){
            int mid = start + (end - start)/2;
            if(mid > 0 && mid < n - 1){
                if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return mid;
                else if(arr[mid] < arr[mid + 1]) start = mid + 1;
                else end = mid - 1;
            }
            else if(mid == 0){
                if(arr[mid] > arr[mid + 1]) return mid;
                else return mid+1;
            }
            else if(mid == n - 1){
                if(arr[mid] > arr[mid - 1]) return mid;
                else mid - 1;
            }
        }
        return -1;
    }

    int search(int start, int end, vector<int> &arr, int target, bool isAsc){
        int n = arr.size();
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] == target) return mid;
            if(isAsc){
                if(target < arr[mid]) end = mid - 1;
                else start = mid + 1;
            }
            else{
                if(target < arr[mid]) start = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;
    }

public:
    int searchBitonic(vector<int> &arr, int target){
        int n = arr.size(), start = 0, end = n - 1;
        if(n == 1) 
            return (arr[0] == target) ? 0: -1;

        int idx = peakBitonic(start, end, arr);
        if(arr[idx] == target) 
            return idx;

        int first = search(start, idx - 1, arr, target, true);
        if(first != -1) 
            return first;
        return search(idx, end, arr, target, false);
    }
};

int main(){
    vector<int> arr = {5, 6, 7, 8, 9, 10, 3, 2, 1};
    int target = 9;
    Solution obj;
    cout << obj.searchBitonic(arr, target) << "\n";
    return 0;
}