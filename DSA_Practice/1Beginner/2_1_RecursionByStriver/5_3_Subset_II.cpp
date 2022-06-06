#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Recursion by Striver : Leetcode 90. Subsets II

class Solution {
private:
    void subset(int idx, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds){
        ans.push_back(ds);

        for (int i = idx; i < nums.size(); i++){
            // Not take - Removing duplicacy
            if(i > idx && nums[i] == nums[i-1])
                continue;
            
            ds.push_back(nums[i]);
            subset(i+1, nums, ans, ds);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        // Sort it so that duplicates will be align together 
        // that makes duplicates easy to avoid
        sort(nums.begin(), nums.end());
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