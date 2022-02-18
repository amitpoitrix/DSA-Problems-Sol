#include<iostream>
#include<vector>
// DP by Striver : DP 20. Minimum Coins | DP on Subsequences | Infinite Supplies Pattern

// Using Recursion
// TC - >> O(2^n) ; Greater than O(2^n) as while considering the coin we are not reducing the idx
// SC - O(target)
class Solution{
private:
    int f(int idx, int target, std::vector<int> &num){
        if(idx == 0){
            if(target % num[0] == 0) return target / num[0];
            else return 1e9;    // Else return MAX no. as if we return 0 so it will be count as min 
        }

        int notTake = 0 + f(idx - 1, target, num);
        int take = 1e9;
        if(num[idx] <= target){
            // As we have infinite/Multiple supplies for each coin so after picking that coin we are not reducing idx
            take = 1 + f(idx, target - num[idx], num);
        }

        return std::min(notTake, take); 
    }

public:
    int minimumElements(std::vector<int> &num, int x){
        int n = num.size();
        int ans = f(n-1, x, num);
        if(ans >= 1e9) return -1;
        else return ans;
    }
};


// Using DP - Memoization(Top-Down) - No TLE
// TC - O(n * target)
// SC - O(n * target) + O(target)
class Solution1{
private:
    int f(int idx, int target, std::vector<int> &num, std::vector<std::vector<int>> &dp){
        if(idx == 0){
            if(target % num[0] == 0) return target / num[0];
            else return 1e9;    // Else return MAX no. as if we return 0 so it will be count as min 
        }

        if(dp[idx][target] != -1) return dp[idx][target];

        int notTake = 0 + f(idx - 1, target, num, dp);
        int take = 1e9;
        if(num[idx] <= target){
            // As we have infinite/Multiple supplies for each coin so after picking that coin we are not reducing idx
            take = 1 + f(idx, target - num[idx], num, dp);
        }

        return dp[idx][target] = std::min(notTake, take); 
    }

public:
    int minimumElements(std::vector<int> &num, int x){
        int n = num.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(x + 1, -1));
        int ans = f(n-1, x, num, dp);
        if(ans >= 1e9) return -1;
        else return ans;
    }
};


// Using DP - Tabulation(Bottom-Up) - Giving TLE on CodeStudio
// TC - O(n * target)
// SC - O(n * target)
class Solution2{
public:
    int minimumElements(std::vector<int> &num, int x){
        int n = num.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(x + 1, 0));
        int target = x;
        // Base Case for Tabulation
        for (int T = 0; T <= target; T++){
            if(T % num[0] == 0) dp[0][T] = T / num[0];
            else dp[0][T] = 1e9;
        }
        
        for (int idx = 1; idx < n; idx++){
            for (int T = 0; T <= target; T++){
                int notTake = 0 + dp[idx - 1][T];
                int take = 1e9;
                if(num[idx] <= T) take = 1 + dp[idx][T - num[idx]];

                dp[idx][T] = std::min(notTake, take); 
            }
        }
        
        int ans = dp[n-1][target];
        if(ans >= 1e9) return -1;
        else return ans;
    }
};


// Space Optimization on Tabulation(Bottom-Up) - No TLE
// TC - O(n * target)
// SC - O(target)
class Solution3{
public:
    int minimumElements(std::vector<int> &num, int x){
        int n = num.size();
        int target = x;
        std::vector<int> prev(target + 1, 0), curr(target + 1, 0);
        // Base Case for Tabulation
        for (int T = 0; T <= target; T++){
            if(T % num[0] == 0) prev[T] = T / num[0];
            else prev[T] = 1e9;
        }
        
        for (int idx = 1; idx < n; idx++){
            for (int T = 0; T <= target; T++){
                int notTake = 0 + prev[T];
                int take = 1e9;
                if(num[idx] <= T) take = 1 + curr[T - num[idx]];

                curr[T] = std::min(notTake, take); 
            }
            prev = curr;
        }
        
        int ans = prev[target];
        if(ans >= 1e9) return -1;
        else return ans;
    }
};


int main(){

    return 0;
}