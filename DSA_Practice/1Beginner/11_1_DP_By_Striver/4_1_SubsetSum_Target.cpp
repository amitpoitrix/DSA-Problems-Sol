#include<iostream>
#include<vector>
// DP by Striver : DP 14. Subset Sum Equals to Target | Identify DP on Subsequences |
// DP 3rd Pattern : DP on Subsequences

// Using Recursion
// TC - O(2^n)
// SC - O(n)
class Solution{
private:
    bool f(int idx, int target, std::vector<int> &arr){
        // Base Case
        if(target == 0)
            return true;
        
        else if(idx == 0)
            return (arr[0] == target);
        
        else{
            int notTaken = f(idx - 1, target, arr);
            int taken = false;
            if(target >= arr[idx])
                taken = f(idx - 1, target - arr[idx], arr);
            
            return taken | notTaken;
        }
    }

public:
    bool subsetSumToK(int n, int k, std::vector<int> &arr) {
        return f(n - 1, k, arr);
    }
};


// Using DP - Memoization(Top-Down)
// TC - O(n * target) ~ becoz there are 2 states which are changing
// SC - O(n * target) + O(n)
class Solution1{
private:
    bool f(int idx, int target, std::vector<int> &arr, std::vector<std::vector<int>> &dp){
        // Base Case
        if(target == 0)
            return true;
        
        else if(idx == 0)
            return (arr[0] == target);
        
        else if(dp[idx][target] != -1)
            return dp[idx][target];
        
        else{
            int notTaken = f(idx - 1, target, arr, dp);
            int taken = false;
            if(target >= arr[idx])
                taken = f(idx - 1, target - arr[idx], arr, dp);
            
            // This will automatically store it into 0 or 1
            return dp[idx][target] = taken | notTaken;
        }
    }

public:
    bool subsetSumToK(int n, int k, std::vector<int> &arr) {
        // For Memoization we are declaring 2D DP becoz of 2 states change of int type instead of bool
        std::vector<std::vector<int>> dp(n, std::vector<int>(k+1, -1)); // As we are passing k so dp size k+1
        return f(n - 1, k, arr, dp);
    }
};


// Using DP - Tabulation(Bottom-Down)
// TC - O(n * target) ~ becoz there are 2 states which are changing
// SC - O(n * target)
class Solution2{
public:
    bool subsetSumToK(int n, int k, std::vector<int> &arr) {
        // For Tabulation we are declaring 2D DP becoz of 2 states with bool type
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(k+1, 0)); // As we are passing k so dp size k+1
        // Base Case for Tabulation
        for (int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        // Another Base Case
        if(arr[0] <= k)
            dp[0][arr[0]] = true;   // Becoz we have assume target as arr[0] so dp[0][arr[0]] will always be true

        for (int idx = 1; idx < n; idx++){
            for (int target = 1; target <= k; target++){
                int notTaken = dp[idx - 1][target];
                int taken = false;
                if(target >= arr[idx])
                    taken = dp[idx - 1][target - arr[idx]];
                
                dp[idx][target] = notTaken | taken;
            }
        }
        
        return dp[n-1][k];
    }
};


// Space Complexity on Tabulation(Bottom-Down)
// TC - O(n * target) ~ becoz there are 2 states which are changing
// SC - O(target)
class Solution3{
public:
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
};


int main(){
    std::vector<int> arr = {2,5,1,6,7};
    int n = arr.size();
    int k = 4;

    Solution3 obj;
    std::cout << obj.subsetSumToK(n, k, arr);

    return 0;
}