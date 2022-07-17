#include<iostream>
#include<vector>
using namespace std;

// GFG: Order-Agnostic Binary Search
// https://www.geeksforgeeks.org/order-agnostic-binary-search/

// Iterative Approach
// TC - O(log(n))
// SC - O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1)
            return (nums[0] == target) ? 0 : -1;

        bool isAsc = nums[0] < nums[n-1];

        int start = 0;
        int end = nums.size() - 1;
        
        while(start <= end){
            int mid = start + (end - start)/2;
            
            if(target == nums[mid])
                return mid;
            
            if(isAsc == true){
                if(target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }

            else{
                if(target < nums[mid])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        
        return -1;
    }
};

int main(){
    return 0;
}