#include<iostream>
#include<vector>
using namespace std;
// DP by Striver : DP 15. Partition Equal Subset Sum | DP on Subsequences
// https://leetcode.com/problems/partition-equal-subset-sum/
// Same as DP 14. Subset Sum Equals to Target

// Taken Most Optimized Sol from Lec 14
// TC - O(n * target) + O(n)
// SC - O(target)
class Solution3{
private:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vector<bool> prev(k+1, 0), curr(k+1, 0);
        // 1st base case
        prev[0] = curr[0] = true;
        // 2nd base Case
        if(arr[0] <= k) prev[arr[0]] = true;

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
    bool canPartition(vector<int> &arr, int n){ 
        int totalSum = 0;
        for (int i = 0; i < n; i++){
            totalSum += arr[i];
        }
        
        if(totalSum % 2)
            return false;

        return subsetSumToK(n, totalSum/2, arr);
    }
};

int main(){
    std::vector<int> arr = {4,5,6,6,9};
    int n = arr.size();

    Solution3 obj;
    std::cout << obj.canPartition(arr, n);

    return 0;
}