#include<iostream>
#include<vector>
// Striver SDE Sheet - Day1-Array-Part1
// Leetcode : 53. Maximum Subarray

// BruteForce Approach 
// TC - O(n^3)
// SC - O(1)
// This Approach will give TLE
class Solution{
public:
    int maxSubArray(std::vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for (int i = 0; i <= n - 1; i++){
            for (int j = i; j <= n - 1; j++){
                int sum = 0;
                for (int k = i; k <= j; k++){
                    sum += nums[k];
                    maxi = std::max(maxi, sum);
                }                   
            }
        }
        
        return maxi > 0 ? maxi : 0;
    }
};


// Optimizing above Approach 
// TC - O(n^2)
// SC - O(1)
// This Approach also giving TLE
class Solution1{
public:
    int maxSubArray(std::vector<int>& nums) {
        int n = nums.size();
        int maxi = -1e9;
        for (int i = 0; i <= n - 1; i++){
            int sum = 0;
            for (int j = i; j <= n - 1; j++){
                sum += nums[j];
                maxi = std::max(maxi, sum);  
            }
        }
        
        return maxi;
    }
};


// Most Optimized Approach - Using Kadane's Algorithm
// TC - O(n)
// SC - O(1)
// ACCEPTED
class Solution1{
public:
    int maxSubArray(std::vector<int>& nums) {
        int n = nums.size();
        int maxi = -1e9;
        int sum = 0;
        for (int i = 0; i <= n - 1; i++){
            sum += nums[i];
            maxi = std::max(maxi, sum);
            // for next iteration
            if(sum < 0)
                sum = 0;
        }
        
        return maxi;
    }
};


int main(){

    return 0;
}