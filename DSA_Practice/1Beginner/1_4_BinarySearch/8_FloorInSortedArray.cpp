#include<iostream>
using namespace std;

// Floor in a Sorted Array
// https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1/

class Solution{
public:
    int findFloor(long long int arr[], int N, long long int x) {
        int start = 0;
        int end = N - 1;
        int res = -1;

        while(start <= end){
            int mid = start + (end - start)/2;

            if(x == arr[mid]) 
                return mid;

            else if(arr[mid] < x){
                res = mid;
                start = mid + 1;
            }

            else 
                end = mid - 1;
        }
        return res;
    }
};

// Another Approach - Using concept of Favourable and UnFavourable Sorted Search Space
class Solution2{
public:
    int findFloor(long long int arr[], int N, long long int x) {
        int l = 0;
        int h = N - 1;

        while(l <= h){
            int mid = l + (h - l)/2;
            
            if(arr[mid] <= x)
                l = mid + 1;
        
            else 
                h = mid - 1;
        }
        
        return h;
    }
};

int main(){
    return 0;
}