#include<iostream>
#include<vector>
#include<algorithm>
// Striver SDE Sheet - Day1-Array-Part1
// Leetcode : 31. Next Permutation

// Approach 1 : Get all the permuations and Sort them in ascending order and get the next permuation of Given Input no.

// Approach 2 : In C++ there is an inbuilt function called next_permutation
class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        // Inbuilt function
        std::next_permutation(nums.begin(), nums.end());
        // print
        std::cout << nums[0] << nums[1] << nums[2];
    }
};

// Approach 3 : If we see all the permutations we'll notice that numbers are attaining peak and than comes down. So from back we'll 
// get the Break Point(when arr[i] < arr[i+1]) get it idx and again from back get another idx which is just greater than previously
// found idx element and swap it, than from idx + 1 till n - 1 reverse the order of elements you'll get the next permutation
// TC - O(n) + O(n) + O(n)
// SC - O(1)
class Solution2 {
public:
    void nextPermutation(std::vector<int>& nums) {
        int idx;
        int n = nums.size();
        // First : Traverse from back to get the idx of break point
        for (idx = n - 2; idx >= 0; idx--){
            if(nums[idx] < nums[idx + 1]){
                break;
            }
        }   
        
        if(idx < 0){
            std::reverse(nums.begin(), nums.end()); 
        }

        else{
            int k;
            // Now we got the idx of Break Point
            // Second : Again Traverse from back to get just greater element than idx
            for (k = n - 1; k > idx; k--){
                if(nums[k] > nums[idx])
                    break;
            }

            // Third : Swapping it
            std::swap(nums[k], nums[idx]);

            // Fourth : Reversing the idx + 1 till n - 1 elements
            std::reverse(nums.begin() + idx + 1, nums.end());
        }
    }
};


int main(){
    std::vector<int> nums = {1,2,3};
    Solution2 obj;
    obj.nextPermutation(nums);

    return 0;
}