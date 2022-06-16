#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// DP by Striver: DP 45. Longest String Chain | Longest Increasing Subsequence | LIS
// https://leetcode.com/problems/longest-string-chain/

class Solution {
private:
    bool checkPossible(string &s1, string &s2){
        // As s1 will be greater than s2
        if(s1.size() != 1 + s2.size()) 
            return false;
        
        int i = 0;  // pointer to s1
        int j = 0;  // pointer to s2
        
        // Traversing till s1 string which is larger in size
        while(i < s1.size()){
            if(j < s2.size() && s1[i] == s2[j]){
                i++;
                j++;
            }
            else{
                // only pointer to s1 will increase in case of mismatch
                i++;    
            }
        }
        
        if(i == s1.size() && j == s2.size()) 
            return true;
        
        return false;
    }
    
    // Compare() for string based upon there length
    static bool comp(string &s1, string &s2){
        return s1.length() < s2.length();
    }
    
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        sort(words.begin(), words.end(), comp);
        
        int maxi = 1;
        for(int idx = 0; idx < n; idx++){
            for(int prev_idx = 0; prev_idx < idx; prev_idx++){
                if(checkPossible(words[idx], words[prev_idx]) && dp[idx] < 1 + dp[prev_idx])
                    dp[idx] = 1 + dp[prev_idx];
            }
            maxi = max(maxi, dp[idx]);
        }
        
        return maxi;
    }
};

int main(){
    return 0;
}