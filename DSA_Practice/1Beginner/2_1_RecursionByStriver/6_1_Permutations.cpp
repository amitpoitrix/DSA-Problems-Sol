#include<iostream>
#include<vector>
// Recursion by Striver - L12. Print all Permutations of a String/Array | Recursion | Approach - 1
// Leetcode 46. Permutations

// Approach 1 : Using Array ds, map ds
// TC - O(n * n!) as n size array will give n! no. of permutations & another n is time to insert in ds
// SC - O(n) + O(n) + O(n) + O(n!) where 1st O(n) due to Array ds, 2nd O(n) due to HashMap, 3rd O(n) due to Auxiliary space use by 
// recursion & last  O(n!) due to size of 2d vector to store all permutations 
class Solution {
private:
    void calPermutation(std::vector<int> &nums, std::vector<std::vector<int>> &ans, std::vector<int> &ds, int freq[]){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                calPermutation(nums, ans, ds, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::vector<int> ds;
        // Taking a HashMap in order to mark whether that element is consider or not 
        int freq[nums.size()];
        // Initializing like this instead of = {0}; as its not working in online Judge
        for (int i = 0; i < nums.size(); i++){
            freq[i] = 0;
        }

        calPermutation(nums, ans, ds, freq);
        return ans;
    }
};

// Approach 2 : Optimized Space Complexity -no use of extra array ds & map ds
// TC - O(n * n!)
// SC - O(n) + O(n!) where O(n) is the auxiliary space taken by recursion
class Solution2{
private:
    void calcPermutation(int idx, std::vector<int> &nums, std::vector<std::vector<int>> &ans){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }

        // starting traversing from given idx i.e., i = idx to n-1
        for (int i = idx; i < nums.size(); i++){
            std::swap(nums[idx], nums[i]);
            // Here we are passing idx+1 instead of i+1 becoz we want equal no. of recursive calls from each further iteration
            calcPermutation(idx + 1, nums, ans);
            // Reverting back the swap after recursion(or Backtracking)
            std::swap(nums[idx], nums[i]);
        }
        
    }

public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        calcPermutation(0, nums, ans);
        return ans;
    }
};

int main(){
    std::vector<int> nums = {1,2,3};

    Solution2 obj;
    for (auto x : obj.permute(nums)){
        for (auto y : x){
            std::cout << y << " ";
        }
        std::cout << "\n";
    }

    return 0;
}