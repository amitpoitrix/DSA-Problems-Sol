#include<bits/stdc++.h>
using namespace std;

// Lt: 169. Majority Element
// https://leetcode.com/problems/majority-element/

// Approach 1: Usinh Hashmap
// TC - O(nlogn)
// SC - O(n);   Hashmap size
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Using Hashmap
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        
        for(auto x: mp){
            if(x.second > n/2)
                return x.first;
        }
        
        return -1;
    }
};

// Approach 2: Using Moore's Voting Algorithm
// TC - O(n)
// SC - O(1)
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        // Using Moore's Voting Algorithm
        int count = 0, res = 0;
        for(auto num: nums){
            if(count == 0)
                res = num;
            
            if(res == num)
                count++;
            else
                count--;
        }
        
        return res;
    }
};

int main(){
    return 0;
}