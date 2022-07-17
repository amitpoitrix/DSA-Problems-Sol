#include<iostream>
#include<vector>
using namespace std;

// 1st Approach
// TC - 2 * O(logn)
// SC - O(1)
class Solution {
private:
    // Getting the idx of min element
    int minElementIdx(int start, int end, vector<int> &nums){
        int n = nums.size();
        while(start <= end){
            int mid = start + (end - start)/2;
            int prev = (mid - 1 + n) % n;
            int next = (mid + 1) % n;
            
            if(nums[mid] <= nums[prev] && nums[mid] <= nums[next]) return mid;
            if(nums[0] <= nums[mid]) start = mid + 1;
            else end = mid - 1;
        }
        return 0;
    }
    
    // Normal Binary Search
    int search(int start, int end, vector<int> &nums, int target){
        while(start <= end){
            int mid = start + (end - start)/2;
            if(target == nums[mid]) return mid;
            else if(target <= nums[mid]) end = mid - 1;
            else start = mid + 1;
        }
        return -1;
    }
    
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int minIdx = minElementIdx(0, n-1, nums);
        if(target == nums[minIdx])
            return minIdx;
        
        if(minIdx == 0)
            return search(0, n-1, nums, target);
        else if(nums[0] <= target)
            return search(0, minIdx - 1, nums, target);
        else
            return search(minIdx, n - 1, nums, target);
        
        return -1;
    }
};

// 2nd Approach
// TC - O(logn)
// SC - O(1)
class Solution2{    
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), start = 0, end = n - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(target == nums[mid]) return mid;
            else if(nums[start] <= nums[mid]){
                if(target >= nums[start] && target < nums[mid]) end = mid - 1;
                else start = mid + 1;
            }
            else{
                if(target > nums[mid] && target <= nums[end]) start = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;
    }
};

int main(){
    return 0;
}