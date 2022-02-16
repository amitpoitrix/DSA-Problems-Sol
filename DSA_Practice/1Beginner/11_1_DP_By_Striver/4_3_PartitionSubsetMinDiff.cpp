#include<iostream>
#include<vector>
// DP by Striver : Dp 16. Partition A Set Into Two Subsets With Minimum Absolute Sum Difference | DP on Subsequences
// Same as DP 14. Subset Sum Equals to Target

// Here in this current ques we have to partition the array into 2 subsets such that there absolute difference is minimum
// This problem is solved using Tabulation method of Subset Sum Target Problem in which last row of DP matrix will be used to
// determine the absolute min difference btw subsets s1 & s2

// Using DP - Tabulation(Bottom-Up)
// TC - O(n * target) ~ becoz there are 2 states which are changing
// SC - O(n * target)
class Solution{
public:
    int minSubsetSumDifference(std::vector<int>& arr, int n){
        // Step 1 : Calculating Total sum of array elements
        int totalSum = 0;
        for (int i = 0; i < n; i++){
            totalSum += arr[i];
        }

        int k = totalSum;

        // Step 2 : Subset Sum Target DP - Tabulation Solution
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(k+1, 0));
        for (int i = 0; i < n; i++){
            dp[i][0] = true;
        }

        if(arr[0] <= k)
            dp[0][arr[0]] = true;   

        for (int idx = 1; idx < n; idx++){
            for (int target = 1; target <= k; target++){
                int notTaken = dp[idx - 1][target];
                int taken = false;
                if(target >= arr[idx])
                    taken = dp[idx - 1][target - arr[idx]];
                
                dp[idx][target] = notTaken | taken;
            }
        }

        // Step 3 : Determining the absolute difference
        int mini = 1e9; // As we are calculating min so taking MAX_INT value

        // We'll consider those cells of last row of dp matrix that are true(or Target can be achieved) and till half pos only as 
        // further of it everything will be repeated
        for (int s1 = 0; s1 <= totalSum/2; s1++){
            if(dp[n-1][s1] == true)
                mini = std::min(mini, abs((totalSum - s1) - s1));
        }
        
        return mini;
    }
};


// Space Optimization on Tabulation(Bottom-Up)
// TC - O(n * target) ~ becoz there are 2 states which are changing
// SC - O(target)
class Solution1{
public:
    int minSubsetSumDifference(std::vector<int>& arr, int n){
        // Step 1 : Calculating Total sum of array elements
        int totalSum = 0;
        for (int i = 0; i < n; i++){
            totalSum += arr[i];
        }

        int k = totalSum;

        // Step 2 : Subset Sum Target DP - Tabulation Solution
        std::vector<bool> prev(k+1, 0), curr(k+1, 0);
        prev[0] = curr[0] = true;
        if(arr[0] <= k)
            prev[arr[0]] = true;

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

        // Step 3 : Determining the absolute difference
        int mini = 1e9; // As we are calculating min so taking MAX_INT value
        for (int s1 = 0; s1 <= totalSum/2; s1++){
            if(prev[s1] == true)
                mini = std::min(mini, abs((totalSum - s1) - s1));
        }
        
        return mini;
    }
};


int main(){
    std::vector<int> arr = {8,6,5};
    int n = arr.size();

    Solution1 obj;
    std::cout << obj.minSubsetSumDifference(arr, n);

    return 0;
}