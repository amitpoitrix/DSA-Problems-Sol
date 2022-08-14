#include <bits/stdc++.h>
using namespace std;

// 128. Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/

// Optimised Approach: Using hashset
// TC - O(n)
// SC - O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Here we make use of set in order to avoid duplicate elements and also find element in O(1) time
        unordered_set<int> hashSet(nums.begin(), nums.end());
        
        int ans = 0;
        for(auto x: hashSet){
            // if prev of current element is not present than we can start count length of LCS becoz its 
            // the staring element for LCS
            if(hashSet.find(x - 1) == hashSet.end()){
                int curr = x;
                int seqLength = 1;  // for current element
                
                // kept on increasing sequence length if curr's next is found for each next iteration
                while(hashSet.find(curr + 1) != hashSet.end()){
                    curr++;
                    seqLength++;
                }
                
                ans = max(ans, seqLength);
            }
        }
        
        return ans;
    }
};

int main(){
    return 0;
}