#include<iostream>
#include<vector>
// DP by Striver : DP 17. Counts Subsets with Sum K | Dp on Subsequences
// Same as DP 14. Subset Sum Equals to Target

// Using Recursion
// TC - O(2^n)
// SC - O(n)
class Solution{
private:
    int f(int idx, int target, std::vector<int> &num){
        if(target == 0) return 1;
        if(idx == 0) return num[0] == target;

        int notTake = f(idx - 1, target, num);
        int take = 0;
        if(num[idx] <= target) take = f(idx - 1, target - num[idx], num);
        
        return notTake + take;
    }

public:
    int findWays(std::vector<int> &num, int tar){
        int n = num.size();
        return f(n-1, tar, num);
    }
};


// Using DP - Memoization(Top-Down)
// TC - O(n * tar)
// SC - O(n * tar) + O(n)
class Solution1{
private:
    int f(int idx, int target, std::vector<int> &num, std::vector<std::vector<int>> &dp){
        if(target == 0) return 1;   // Only valid when 1 <= num[i] <= 1000 & will create problem when 0 <= num[i] <= 1000*
        /* 
            for 0 <= num[i] <= 1000 or num[] = {0,0,1} & sum = 1 than count should be 4 but above logic will give 1 due to target == 0
            so we'll remove that condition and add additional condition when idx == 0
            if(idx == 0){
                if(sum == 0 && num[0] == 0) return 2;   // take num[0] or Not take num[0] both will contribute to sum 0 if num[0] is 0 so count is 2
                if(sum == 0 || sum == num[0]) return 1; // either sum is 0 or sum is equal to num[0] than 1 count
                return 0;
            }
        */
        if(idx == 0) return num[0] == target;

        if(dp[idx][target] != -1) return dp[idx][target];

        int notTake = f(idx - 1, target, num, dp);
        int take = 0;
        if(num[idx] <= target) take = f(idx - 1, target - num[idx], num, dp);
        
        return dp[idx][target] = notTake + take;
    }

public:
    int findWays(std::vector<int> &num, int tar){
        int n = num.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(tar + 1, -1));
        return f(n-1, tar, num, dp);
    }
};


// Using DP - Tabulation(Bottom-Up)
// TC - O(n * tar)
// SC - O(n * tar)
class Solution2{
public:
    int findWays(std::vector<int> &num, int tar){
        int n = num.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(tar + 1, 0));
        // Base Case for Tabulation
        for (int i = 0; i < n; i++) dp[i][0] = 1;
        if(num[0] <= tar) dp[0][num[0]] = 1;

        for (int idx = 0; idx < n; idx++){
            for (int target = 1; target <= tar; target++){
                int notTake = dp[idx - 1][target];
                int take = 0;
                if(num[idx] <= target) take = dp[idx - 1][target - num[idx]];
                
                dp[idx][target] = notTake + take;  
            }
        }
        
        return dp[n-1][tar];
    }
};


// Space Complexity on Tabulation(Bottom-Up)
// TC - O(n * tar)
// SC - O(tar)
class Solution3{
public:
    int findWays(std::vector<int> &num, int tar){
        int n = num.size();
        std::vector<int> prev(tar + 1, 0), curr(tar + 1, 0);
        // Base Case for Tabulation
        prev[0] = curr[0] = 1;
        if(num[0] <= tar) prev[num[0]] = 1;

        for (int idx = 1; idx < n; idx++){

            for (int target = 0; target <= tar; target++){
                int notTake = prev[target];
                int take = 0;
                if(num[idx] <= target) take = prev[target - num[idx]];
                
                curr[target] = notTake + take;  
            }

            prev = curr;
        }
        
        return prev[tar];
    }
};


int main(){
    std::vector<int> num = {12,1,3};
    int tar = 4;

    Solution3 obj;
    std::cout << obj.findWays(num, tar);

    return 0;
}