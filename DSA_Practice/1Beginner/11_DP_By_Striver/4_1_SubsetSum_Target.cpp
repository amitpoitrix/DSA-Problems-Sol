#include<iostream>
#include<vector>
using namespace std;
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
    bool f(int idx, int target, vector<int> &arr, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(idx == 0) return (arr[0] == target);
        
        if(dp[idx][target] != -1) return dp[idx][target];
        
        int notTaken = f(idx - 1, target, arr, dp);
        int taken = false;
        if(target >= arr[idx])
            taken = f(idx - 1, target - arr[idx], arr, dp);
            
        // This will automatically store it into 0 or 1
        return dp[idx][target] = taken | notTaken;
    }

public:
    bool subsetSumToK(int n, int k, std::vector<int> &arr) {
        // For Memoization we are declaring 2D DP becoz of 2 states 
        // change of int type instead of bool
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return f(n - 1, k, arr, dp);
    }
};


// Using DP - Tabulation(Bottom-Down)
// TC - O(n * target)
// SC - O(n * target)
class Solution2{
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
        // 1st Base Case (target)
        for (int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        // 2nd Base Case (idx)
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
        
        return dp[n-1][k];
    }
};


// Space Complexity on Tabulation(Bottom-Down)
// TC - O(n * target)
// SC - O(target)
class Solution3{
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        vector<bool> prev(k+1, 0), curr(k+1, 0);
        // 1st Base Case - Making First idx of each array as True i.e., when target is 0
        prev[0] = curr[0] = true;
        // 2nd Base Case
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