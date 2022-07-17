#include<iostream>
#include<vector>
using namespace std;

// Find Element in sorted array having min difference(absolute) with given(key) element

class Solution{
public:
    int minDiff(vector<int> &arr, int key){
        int n = arr.size(), start = 0, end = n - 1;
        if(key < arr[start]) return arr[start];
        if(key > arr[end]) return arr[end];

        while(start <= end){
            int mid = start + (end - start)/2;
            if(key == arr[mid]) return arr[mid];
            else if(key < arr[mid]) end = mid - 1;
            else start = mid + 1;
        }
        if(abs(arr[start] - key) < abs(arr[end] - key))
            return arr[start];
        return arr[end];
    }
};

int main(){
    vector<int> arr = {3,8,10,15};
    int key = 1;
    Solution obj;
    cout << obj.minDiff(arr, key) << "\n";
    return 0;
}