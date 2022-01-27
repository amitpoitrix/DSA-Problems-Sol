#include<iostream>
#include<vector>
// Recursion by Striver - Leetcode 39. Combination Sum
// TC - O(k * 2^t) where k is time to insert k length combination of no. to ds & t is the target sum as what if given int is 1
// SC - O(k * x) where k is avg length of combination & x is the no. of such combination

class Solution {
private:
    void calCombinationSum(int i, std::vector<int> &candidates, int target,std::vector<std::vector<int>> &ans,std::vector<int> &ds){
        if(i == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        // Take - considering the current element any no. of times so i will be same
        if(candidates[i] <= target){
            ds.push_back(candidates[i]);
            calCombinationSum(i, candidates, target - candidates[i], ans, ds);
            ds.pop_back();
        }

        // Not Take - Now we'll increament i
        calCombinationSum(i+1, candidates, target, ans, ds);
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> ans;
        std::vector<int> ds;
        calCombinationSum(0, candidates, target, ans, ds);
        return ans;
    }
};

int main(){
    std::vector<int> candidates = {2,3,6,7};
    int target = 7;

    Solution obj;
    for (auto x : obj.combinationSum(candidates, target)){
        for (auto y : x){
            std::cout << y << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}