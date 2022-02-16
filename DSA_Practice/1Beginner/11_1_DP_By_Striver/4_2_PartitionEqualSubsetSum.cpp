#include<iostream>
#include<vector>
// DP by Striver : DP 15. Partition Equal Subset Sum | DP on Subsequences
// Same as DP 14. Subset Sum Equals to Target

// Taken Most Optimized Sol from Lec 14
class Solution3{
private:
    bool subsetSumToK(int n, int k, std::vector<int> &arr) {
        std::vector<bool> prev(k+1, 0), curr(k+1, 0); // As we are passing k so dp size k+1
        // Base Case for Tabulation - Making First idx of each array as True i.e., when target is 0
        prev[0] = curr[0] = true;
        // Another Base Case
        if(arr[0] <= k)
            prev[arr[0]] = true;   // Becoz we have assume target as arr[0] so dp[0][arr[0]] will always be true

        for (int idx = 1; idx < n; idx++){

            for (int target = 1; target <= k; target++){
                int notTaken = prev[target];
                int taken = false;
                if(target >= arr[idx])
                    taken = prev[target - arr[idx]];
                
                curr[target] = notTaken | taken;
            }

            prev = curr;
        }
        
        return prev[k];
    }

public:
    bool canPartition(std::vector<int> &arr, int n){
        // Here in Partition equal subset sum we have to divide the array such that both subset sums are equal and we have to return 
        // ans in T/F, Two subsets are equal only when total sum of the subsets is divisible by 2 if yes than its same as
        // Subset Sum Target problem with target as totalSum/2. 
        int totalSum = 0;
        for (int i = 0; i < n; i++){
            totalSum += arr[i];
        }
        
        if(totalSum % 2)
            return false;
        else{
            return subsetSumToK(n, totalSum/2, arr);
        }
    }
};

int main(){
    std::vector<int> arr = {4,5,6,6,9};
    int n = arr.size();

    Solution3 obj;
    std::cout << obj.canPartition(arr, n);

    return 0;
}