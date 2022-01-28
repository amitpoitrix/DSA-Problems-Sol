#include<iostream>
#include<vector>
#include<algorithm>
// Recursion by Striver : Leetcode 90. Subsets II

class Solution {
private:
    void subset(int idx, std::vector<int> &nums, std::vector<std::vector<int>> &ans, std::vector<int> &ds){
        ans.push_back(ds);

        // Starting i from given idx
        for (int i = idx; i < nums.size(); i++){
            // Not take - Removing duplicacy
            if(i > idx && nums[i] == nums[i-1])
                continue;
            
            // Take
            ds.push_back(nums[i]);
            subset(i+1, nums, ans, ds);
            ds.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::vector<int> ds;
        // First sorting it so as to avoid duplicacy
        std::sort(nums.begin(), nums.end());
        subset(0, nums, ans, ds);
        return ans;
    }
};

int main(){
    std::vector<int> nums = {1,2,2};

    Solution obj;
    for (auto x : obj.subsetsWithDup(nums)){
        for (auto y : x){
            std::cout << y << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}