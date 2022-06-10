#include<iostream>
#include<vector>
using namespace std;
// DP by Striver : DP 18. Count Partitions With Given Difference | Dp on Subsequences
// Same as DP 17. Count Subset Sum Equals to Target
// https://leetcode.com/problems/target-sum/

// Target Sum - Leetcode Problem is same as this current ques

// Using Recursion
// TC - O(2^n)
// SC - O(n)
class Solution{
private:
    int f(int idx, int target, vector<int> &num){
        if(idx == 0){
            if(target == 0 && num[0] == 0) return 2;
            if(target == 0 || num[0] == target) return 1;
            return 0;
        }

        int notTake = f(idx - 1, target, num);
        int take = 0;
        if(num[idx] <= target) 
            take = f(idx - 1, target - num[idx], num);
        
        return notTake + take;
    }

    int findWays(std::vector<int> &num, int tar){
        int n = num.size();
        return f(n-1, tar, num);
    }

public:
    int countPartitions(int n, int d, vector<int> &arr) {
        int totalSum = 0;
        for (int i = 0; i < arr.size(); i++) 
            totalSum += arr[i];

        if((totalSum - d) < 0 || (totalSum - d)%2 != 0) 
            return 0;

        return findWays(arr, (totalSum - d)/2);
    }
};


// Using DP - Memoization(Top-Down)
// TC - O(n * tar)
// SC - O(n * tar) + O(n)
class Solution1{
private:
    int mod = (1e9 + 7);    // As in CodeStudio ans can be large enough

    int f(int idx, int target, vector<int> &num, vector<vector<int>> &dp){
        if(idx == 0){
            if(target == 0 && num[0] == 0) return 2;
            if(target == 0 || num[0] == target) return 1;
            return 0;
        }

        if(dp[idx][target] != -1) return dp[idx][target];

        int notTake = f(idx - 1, target, num, dp);
        int take = 0;
        if(num[idx] <= target) 
            take = f(idx - 1, target - num[idx], num, dp);
        
        return dp[idx][target] = (notTake + take) % mod;
    }

    int findWays(vector<int> &num, int tar){
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
        return f(n-1, tar, num, dp);
    }

public:
    int countPartitions(int n, int d, vector<int> &arr) {
        int totalSum = 0;
        for (int i = 0; i < arr.size(); i++) 
            totalSum += arr[i];

        if((totalSum - d) < 0 || (totalSum - d)%2 != 0) 
            return 0;

        return findWays(arr, (totalSum - d)/2);
    }
};


// Using DP - Tabulation(Bottom-Up)
// TC - O(n * tar)
// SC - O(n * tar)
class Solution2{
private:
    int mod = (1e9 + 7);

    int findWays(vector<int> &num, int tar){
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
        // 1st Base Case
        if(num[0] == 0) 
            dp[0][0] = 2;   // As num[0] is 0 so take num[0] or not take num[0], sum will remain 0 so count is 2
        else 
            dp[0][0] = 1;  // if sum is 0 but num[0] != 0 than count is 1 when we don't consider num[0]
        
        // 2nd Base Case : what if num[0] = 0 than count will be 2 so in order to avoid we put additional check
        if(num[0] != 0 && num[0] <= tar) 
            dp[0][num[0]] = 1;

        for (int idx = 1; idx < n; idx++){
            for (int target = 0; target <= tar; target++){
                int notTake = dp[idx - 1][target];
                int take = 0;
                if(num[idx] <= target) 
                    take = dp[idx - 1][target - num[idx]];
                
                dp[idx][target] = (notTake + take) % mod;  
            }
        }
        
        return dp[n-1][tar];
    }

public:
    int countPartitions(int n, int d, vector<int> &arr) {
        int totalSum = 0;
        for (int i = 0; i < arr.size(); i++) 
            totalSum += arr[i];

        if((totalSum - d) < 0 || (totalSum - d)%2 != 0) 
            return 0;

        return findWays(arr, (totalSum - d)/2);
    }
};


// Space Complexity on Tabulation(Bottom-Up)
// TC - O(n * tar)
// SC - O(tar)
class Solution3{
private:
    int mod = (1e9 + 7);

    int findWays(vector<int> &num, int tar){
        int n = num.size();
        vector<int> prev(tar + 1, 0), curr(tar + 1, 0);
        // 1st Base Case
        if(num[0] == 0) 
            prev[0] = 2;
        else 
            prev[0] = 1;

        // 2nd Base Case 
        if(num[0] != 0 && num[0] <= tar) 
            prev[num[0]] = 1;

        for (int idx = 1; idx < n; idx++){
            for (int target = 0; target <= tar; target++){
                int notTake = prev[target];
                int take = 0;
                if(num[idx] <= target) 
                    take = prev[target - num[idx]];
                
                curr[target] = (notTake + take) % mod;  
            }
            prev = curr;
        }
        
        return prev[tar];
    }

public:
    int countPartitions(int n, int d, vector<int> &arr) {
        int totalSum = 0;
        for (int i = 0; i < arr.size(); i++) 
            totalSum += arr[i];

        if((totalSum - d) < 0 || (totalSum - d)%2 != 0) 
            return 0;

        return findWays(arr, (totalSum - d)/2);
    }
};


int main(){
    std::vector<int> num = {5,2,6,4};
    int n = num.size();
    int d = 3;

    Solution obj;
    std::cout << obj.countPartitions(n, d, num);

    return 0;
}