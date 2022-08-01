#include<iostream>
#include<vector>
using namespace std;
// Striver SDE Sheet - Day1-Array-Part1
// Leetcode : 53. Maximum Subarray\
// https://leetcode.com/problems/maximum-subarray/

// BruteForce Approach 
// TC - O(n^3)
// SC - O(1)
// This Approach will give TLE
class Solution{
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                int sum = 0;
                for (int k = i; k <= j; k++){
                    sum += nums[k];
                    maxi = max(maxi, sum);
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
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1e9;
        for (int i = 0; i < n; i++){
            int sum = 0;
            for (int j = i; j < n; j++){
                sum += nums[j];
                maxi = max(maxi, sum);  
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
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1e9;
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += nums[i];
            maxi = max(maxi, sum);
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