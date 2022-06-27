#include<iostream>
#include<vector>
using namespace std;

// Lt: 704. Binary Search
// https://leetcode.com/problems/binary-search/

// Iterative Approach
// TC - O(log(n)); to the base 2
// SC - O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        
        while(start <= end){
            int mid = start + (end - start)/2;
            
            if(target == nums[mid])
                return mid;
            
            else if(target < nums[mid])
                end = mid - 1;
            
            else
                start = mid + 1;
        }
        
        return -1;
    }
};

// Recursive Approach
// TC - O(log(n))
// SC - O(log(n))
class Solution {
private:
    int recursiveBS(int start, int end, vector<int> &nums, int &target){
        if(start <= end){
            int mid = start + (end - start)/2;
            
            if(target == nums[mid])
                return mid;
            
            else if(target < nums[mid])
                return recursiveBS(start, mid - 1, nums, target);
        
            return recursiveBS(mid + 1, end, nums, target);
        }
        
        return -1;
    }
    
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        
        return recursiveBS(start, end, nums, target);
    }
};

int main(){
    return 0;
}