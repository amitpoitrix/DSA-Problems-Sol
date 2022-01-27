#include<iostream>
#include<vector>
#include<algorithm>
// Recursion by Striver : Leetcode 40. Combination Sum II

// Bruteforce Approach
// If we modify previous problem (Combination Sum I) solution - i.e., by changing i -> i+1 and using HashSet while inserting ds in ans
// in order to avoid duplicacy of combinations we can achieve out solution but
// TC - O(K * 2^t * logN) where logN is due to hashSet being used

// Optimized Approach
// TC - O(K * 2^N)
// SC - O(K * x) 
class Solution {
private:
    void calCombinationSumII(int idx, std::vector<int> &candidates, int target, std::vector<std::vector<int>> &ans, std::vector<int> &ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }

        for (int i = idx; i < candidates.size(); i++){
            // Avoiding duplicate combination by ignoring the starting element of combination if its same as previous element
            if(i > idx && candidates[i] == candidates[i-1])
                continue;
            // If current index element is greater than target than no need to check further as elements are sorted
            if(candidates[i] > target)
                break;
            
            ds.push_back(candidates[i]);
            calCombinationSumII(i + 1, candidates, target - candidates[i], ans, ds);
            ds.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        // first we'll sort the element in order to get duplicate element in grp
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> ans;
        std::vector<int> ds;
        calCombinationSumII(0, candidates, target, ans, ds);
        return ans;
    }
};

int main(){
    std::vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    Solution obj;
    for (auto x : obj.combinationSum2(candidates, target)){
        for (auto y : x){
            std::cout << y << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}