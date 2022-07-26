#include <bits/stdc++.h>
using namespace std;

// Lt: 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/

// Approach 1: Using sorting
// TC - O(nlogn)
// SC - O(1)
class Solution1 {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        if(s != t) return false;
        return true;
    }
};

// Approach 2: Using Char freq
// TC - O(n)
// SC - O(26)
class Solution2 {
public:
    bool isAnagram(string s, string t) {
        // Base case: If length() is different than return false
        if(s.length() != t.length())
            return false;
        
        // Using char freq array
        int a[26] = {0};
        int b[26] = {0};
        for(int i = 0; i < s.length(); i++){
            a[s[i] - 'a']++;
        }
        
        for(int i = 0; i < t.length(); i++){
            b[t[i] - 'a']++;
        }
        
        for(int i = 0; i < 26; i++){
            if(a[i] != b[i])
                return false;
        }
        
        return true;
    }
};

// Approach 3: Using Hashmap
// TC - O(logn) ~ O(1) in avg case for unordered_map
// SC - O(n)
class Solution3 {
public:
    bool isAnagram(string s, string t) {
        // Base case: If length() is different than return false
        if(s.length() != t.length())
            return false;
        
        // Using map
        unordered_map<char, int> mp;
        // Traversing over s string and store its each char freq
        for(auto x: s){
            mp[x]++;
        }
        // Traversing over t string
        for(auto x: t){
            // If t's char is not in map or if its there than its freq is 0
            if(mp.find(x) == mp.end() || mp[x] == 0)
                return false;
            else    // else decrement that char freq
                mp[x]--; 
        }
        
        return true;
    }
};

int main(){
    return 0;
}