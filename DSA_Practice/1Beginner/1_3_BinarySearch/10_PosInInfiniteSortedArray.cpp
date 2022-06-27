#include<iostream>
#include<vector>
using namespace std;

// Find position of an element in infinite sorted array
// https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/

class Solution{
private:
    int search(int start, int end, vector<int> &arr, int target){
        while(start <= end){
            int mid = start + (end - start)/2;
            if(target == arr[mid]) return mid;
            else if(target < arr[mid]) end = mid - 1;
            else start = mid + 1;
        }
        return -1;
    }

public:
    int findPos(vector<int> &arr, int target){
        int start = 0;
        int end = 1;
        while(target > arr[end]){
            start = end;
            end = 2 * end;
        }

        if(target == arr[end]) return end;
        
        return search(start, end, arr, target);
    }
};

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11};
    int target = 7;
    Solution obj;
    cout << obj.findPos(arr, target) << "\n";
    return 0;
}