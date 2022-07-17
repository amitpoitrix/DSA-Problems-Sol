#include<iostream>
#include<vector>
using namespace std;

// Find the index of first 1 in an infinite sorted array of 0s and 1s
// https://www.geeksforgeeks.org/find-index-first-1-infinite-sorted-array-0s-1s/

class Solution{
private:
    int firstOccurrence(int start, int end, vector<int> &arr){
        int res = end;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] == 1){
                res = mid;
                end = mid - 1;
            }
            else if(arr[mid] < 1) 
                start = mid + 1;
        }
        return res;
    }

public:
    int posOfFirstOne(vector<int> &arr){
        // First find out fix size array containing target
        int n = arr.size(), start = 0, end = 1;
        while(arr[end] < 1){
            start = end;
            end = 2 * end;
        }

        // Now applying First Occurrence of BS
        return firstOccurrence(start, end, arr); 
    }
};

int main(){
    vector<int> arr = {0,0,0,0,0,0,0,1,1,1,1,1,1};
    Solution obj;
    cout << obj.posOfFirstOne(arr) << "\n";
    return 0;
}