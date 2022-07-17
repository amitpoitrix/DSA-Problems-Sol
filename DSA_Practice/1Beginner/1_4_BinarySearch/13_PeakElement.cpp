#include<iostream>
#include<vector>
using namespace std;

// Lt: 162. Find Peak Element
// https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(), start = 0, end = n - 1;
        if(n == 1) return 0;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(mid > 0 && mid < n - 1){
                if(nums[mid] >= nums[mid - 1] && nums[mid] >= nums[mid + 1]) return mid;
                else if(nums[mid] < nums[mid + 1]) start = mid + 1;
                else end = mid - 1;
            }
            
            else if(mid == 0){
                if(nums[mid] > nums[mid+1]) return mid;
                else return mid + 1;
            }
            
            else if(mid == n - 1){
                if(nums[mid] > nums[mid-1]) return mid;
                else return mid - 1;
            }
        }
        return -1;
    }
};

int main(){
    return 0;
}