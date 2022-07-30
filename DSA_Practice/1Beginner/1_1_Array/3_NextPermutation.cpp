#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Striver SDE Sheet - Day1-Array-Part1
// Leetcode : 31. Next Permutation
// https://leetcode.com/problems/next-permutation/

// Approach 1 : Get all the permuations and Sort them in ascending order and get the next permuation of Given Input no.

// Approach 2 : In C++ there is an inbuilt function called next_permutation
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Inbuilt function
        next_permutation(nums.begin(), nums.end());
        // print
        cout << nums[0] << nums[1] << nums[2];
    }
};

// Approach 3 : If we see all the permutations we'll notice that numbers are attaining peak and than comes down. So from 
// back we'll  get the Break Point(when arr[i] < arr[i+1]) get its i as idx1 and again traverse from back get another 
// i as idx2 which is just greater than previously found idx1 element and than swap idx1 with idx2, than from 
// idx + 1 till end reverse the order of elements you'll get the next permutation
// TC - O(n) + O(n) + O(n)
// SC - O(1)
class Solution2 {
public:
    void nextPermutation(vector<int>& nums) {
        int idx1 = -1, n = nums.size();
        // Step 1 : Traverse from back to get idx1 i.e., break point(nums[i] < nums[i+1])
        for (int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                idx1 = i;
                break;
            }
        }   
        
        // If given permutation is last permutation so returning first one
        if(idx1 == -1){
            reverse(nums.begin(), nums.end()); 
        }
        // If given permutation is not the last one
        else{
            // Step2 : Again Traverse from back to get index of first greater element than idx1 
            int idx2 = -1;
            for (int i = n - 1; i > idx1; i--){
                if(nums[i] > nums[idx1]){
                    idx2 = i;
                    break;
                }
            }

            // Third : Swap idx1 with idx2
            swap(nums[idx1], nums[idx2]);

            // Fourth : Reverse from idx1 + 1 till last element
            reverse(nums.begin() + idx1 + 1, nums.end());
        }
    }
};


int main(){
    vector<int> nums = {1,2,3};
    Solution2 obj;
    obj.nextPermutation(nums);

    return 0;
}