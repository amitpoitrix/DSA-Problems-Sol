#include<bits/stdc++.h>
using namespace std;

// Lt: 229. Majority Element II
// https://leetcode.com/problems/majority-element-ii/

// Approach 1: Using Hashmap
// TC - O(nlogn)
// SC - O(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Using Hashmap
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        
        vector<int> res;
        for(auto x: mp){
            if(x.second > n/3){
                res.push_back(x.first);
            }
        }
        
        return res;
    }
};

// Using Extended Boyer Moore Voting Algorithm
// TC - O(n) + O(n)
// SC - O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Using Extended Boyer Moore Voting Algorithm
        int nums1 = -1, nums2 = -1, c1 = 0, c2 = 0;
        for(auto x: nums){
            if(x == nums1) c1++;
            
            else if(x == nums2) c2++;
            
            else if(c1 == 0){
                nums1 = x;
                c1 = 1;
            }
            
            else if(c2 == 0){
                nums2 = x;
                c2 = 1;
            }
            
            else{
                c1--;
                c2--;
            }
        }
        
        vector<int> res;
        int n = nums.size();
        c1 = c2 = 0;
        for(auto x: nums){
            if(x == nums1) c1++;
            else if(x == nums2) c2++;
        }
        
        if(c1 > n/3)
            res.push_back(nums1);
        if(c2 > n/3)
            res.push_back(nums2);
        
        return res;
    }
};

int main(){
    return 0;
}