#include <bits/stdc++.h>
using namespace std;

// Lt: 18. 4Sum
// https://leetcode.com/problems/4 sum/

// TC - O(n^3)
// SC - O(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        
        if(nums.empty())
            return res;
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        for(int i = 0; i < n; i++){
            
            for(int j = i+1; j < n; j++){
                
                int left = j+1, right = n-1;
                long long int target_2 = target - (long long int)(nums[i] + nums[j]);
                
                while(left < right){    
                    if((nums[left] + nums[right]) < target_2)
                        left++;
                
                    else if((nums[left] + nums[right]) > target_2)
                        right--;

                    else{
                        vector<int> quad(4);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[left];
                        quad[3] = nums[right];
                        res.push_back(quad);
                        
                        // Skipping the duplicates for left pointer
                        while(left < right && nums[left] == quad[2])
                            left++;
                        // Skipping the duplicates for left pointer
                        while(left < right && nums[right] == quad[3])
                            right--;
                    }
                }
                
                // Skipping the duplicates for j pointer
                while(j+1 < n && nums[j] == nums[j+1])
                    j++;
            }
            // Skipping the duplicates for i pointer
            while(i+1 < n && nums[i] == nums[i+1])
                i++;
        }
        
        return res;
    }
};

int main(){
    return 0;
}