#include<bits/stdc++.h>
using namespace std;

// Lt: 1743. Restore the Array From Adjacent Pairs
// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/

// TC - O(n)
// SC - O(n)
class Solution {
private: 
    void dfs(int head, unordered_map<int, vector<int>> &mp, unordered_set<int> &s, vector<int> &ans){
        if(s.find(head) != s.end()) 
            return;
        
        ans.push_back(head);
        s.insert(head);
        
        for(auto &x: mp[head]){
            dfs(x, mp, s, ans);
        }
    }
    
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> mp;
        for(auto &x: adjacentPairs){
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
        }
        
        int head = 0;
        for(auto &x: mp){
            if(x.second.size() == 1){
                head = x.first;
                break;
            }
        }
        
        unordered_set<int> s;
        vector<int> ans;
        dfs(head, mp, s, ans);
        
        return ans;
    }
};

int main(){
    return 0;
}