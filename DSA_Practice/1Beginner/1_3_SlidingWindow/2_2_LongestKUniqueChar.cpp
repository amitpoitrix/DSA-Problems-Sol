#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Longest K unique characters substring
// https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

// TC - O(n)
// SC - O(1)
class Solution{
public:
    int longestKSubstr(string s, int k) {
        int len = -1;
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        
        while(j < s.size()){
            mp[s[j]]++;
            
            if(mp.size() < k)
                j++;
            
            else if(mp.size() == k){
                len = max(len, j - i + 1);
                j++;
            }
            
            else if(mp.size() > k){
                while(mp.size() > k){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                        mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        
        return len;
    }
};

int main(){
    return 0;
}