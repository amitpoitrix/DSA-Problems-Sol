#include <bits/stdc++.h>
using namespace std;

// Lt: 1. Two Sum
// https://leetcode.com/problems/two-sum/

// Using Hashmap
// TC - O(n); in worst case O(n^2)
// SC - O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            // If (target - nums[i]) is already present in hashmap
            if(mp.find(target-nums[i]) != mp.end()){
                res.push_back(mp[target-nums[i]]);
                res.push_back(i);
                return res;
            }
            
            // If not than insert into hashmap
            mp[nums[i]] = i;
        }
        
        return res;
    }
};

int main(){
    return 0;
}