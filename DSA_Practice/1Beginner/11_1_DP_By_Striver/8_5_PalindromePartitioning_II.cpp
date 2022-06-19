#include<iostream>
#include<vector>
using namespace std;
// DP by Striver: DP 53. Palindrome Partitioning - II | Front Partition
// https://leetcode.com/problems/palindrome-partitioning-ii/

// Memoization
// TC - O(n * n) ~ O(n^2)
// SC - O(n) + O(n)
class Solution {
private:
    bool isPalindrome(int i, int j, string &s){
        while(i < j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        
        return true;
    }
    
    int f(int idx, int n, string &s, vector<int> &dp){
        // Base Case
        if(idx == n) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int minCost = 1e9;
        for(int j = idx; j < n; j++){
            // Checking palindrome from [idx...j]
            if(isPalindrome(idx, j, s)){
                int cost = 1 + f(j+1, n, s, dp);
                minCost = min(minCost, cost);
            }
        }
        
        return dp[idx] = minCost;
    }
    
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, n, s, dp) - 1;
    }
};

// Tabulation
// TC - O(n^2)
// SC - O(n)
class Solution2{
private:
    bool isPalindrome(int i, int j, string &s){
        while(i < j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        
        return true;
    }
    
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        
        // Base Case
        dp[n] = 0;
        
        for(int idx = n-1; idx >= 0; idx--){
            int minCost = 1e9;
            for(int j = idx; j < n; j++){
                // Checking palindrome from [idx...j]
                if(isPalindrome(idx, j, s)){
                    int cost = 1 + dp[j+1];
                    minCost = min(minCost, cost);
                }
            }
            dp[idx] = minCost;
        }
        
        return dp[0] - 1;
    }
};

int main(){
    return 0;
}