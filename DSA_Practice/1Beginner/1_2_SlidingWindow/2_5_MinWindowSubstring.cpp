#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Lt 76. Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        if(s.size() < t.size())
            return ans;
        
        unordered_map<char, int> mp;
        for(auto &x: t)
            mp[x]++;
        
        int count = mp.size();
        int i = 0, j = 0, len = 1e9;
        
        while(j < s.size()){
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                    count--;
            }
            
            if(count > 0)
                j++;
            
            else if(count == 0){
                while(count == 0){
                    if(mp.find(s[i]) != mp.end()){
                        if((j - i + 1) < len){
                            len = j - i + 1;
                            ans = s.substr(i, j - i + 1);
                        }

                        mp[s[i]]++;
                        if(mp[s[i]] > 0)
                            count++;
                    }
                    i++;
                }
                j++;
            }   
        }
        
        return ans;
    }
};

int main(){
    return 0;
}