#include<iostream>
#include<vector>
// Leetcode - 78. Subsets
// Return all subsets(or Power set) of given set

// Using Power Set
class Solution1{
public:
    std::vector<std::vector<int>> subsets(std::vector<int> nums){
        int n = nums.size();
        int len = (1 << n) - 1;
        std::vector<std::vector<int>> res;

        for (int i = 0; i <= len; i++){
            std::vector<int> ds;
            for (int j = 0; j < n; j++){
                if(i & (1 << j))
                    ds.push_back(nums[j]);
            }
            res.push_back(ds);
        }
        
        return res;
    }
};

// Using Multiple Recursion (by using for loop)
class Solution {
private:
    void subset(int idx, std::vector<int> &nums, std::vector<std::vector<int>> &ans, std::vector<int> &ds){
        ans.push_back(ds);
        
        for (int i = idx; i < nums.size(); i++){
            ds.push_back(nums[i]);
            // Here we are passing i+1 instead of idx+1 becoz we don't want equal no. of recursive calls from each further iteration
            subset(i+1, nums, ans, ds);
            ds.pop_back();
        }
    }
    
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::vector<int> ds;
        subset(0, nums, ans, ds);
        return ans;
    }
};

// Using Two Recursion calls
class Solution2 {
private:
    void subset(int idx, std::vector<int> &nums, std::vector<std::vector<int>> &ans, std::vector<int> &ds){
        if(idx == nums.size()){
            ans.push_back(ds);
            return;
        }

        // Take
        ds.push_back(nums[idx]);
        subset(idx + 1, nums, ans, ds);
        ds.pop_back();    

        // Not Take
        subset(idx + 1, nums, ans, ds);
    }
    
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::vector<int> ds;
        subset(0, nums, ans, ds);
        return ans;
    }
};

int main(){
    std::vector<int> nums = {1,2,3};

    Solution obj;
    for (auto x : obj.subsets(nums)){
        for (auto y : x){
            std::cout << y << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}