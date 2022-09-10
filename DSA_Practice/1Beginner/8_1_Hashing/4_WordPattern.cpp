#include<bits/stdc++.h>
using namespace std;

// Lt: 290. Word Pattern
// https://leetcode.com/problems/word-pattern/

// Using Hashing (Map + set)
// TC - O(nlogn)
// SC - O(n)
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Getting words from string s and store it in array of strings str
        vector<string> str;
        string ans = "";
        for(auto ch: s){
            // if encounter space ' ' or end of character('/0' or 0) than we got the word just 
            // insert it & re-initialise ans to ""
            if(ch == ' ' || ch == '/0'){
                str.push_back(ans);
                ans = "";   // For computing next word
            }
            else{
                ans.push_back(ch);
            }
        }
        str.push_back(ans); // inserting last word in array of strings
        
        // if pattern size and array of strings size doesn't match than return false
        if(pattern.size() != str.size()){
            return false;
        }
        
        // Now making pair of mp[char] -> words
        unordered_map<char, string> mp;
        // Using set in order to detect same word being assign to different pattern character
        set<string> st; 
        for(int i = 0; i < str.size(); i++){
            // if pattern char is not present in map
            if(mp.find(pattern[i]) == mp.end()){
                // first check if its value(word) is already being assign to someone else
                if(st.count(str[i]) > 0){
                    return false;
                }
                // if not than assign it to map as well as insert it in set
                mp[pattern[i]] = str[i];
                st.insert(str[i]);
            }
            
            else{   // if pattern char is already present in map than check its value with current value
                if(mp[pattern[i]] != str[i])
                    return false;
            }
        }
        
        return true;
    }
};

int main(){
    return 0;
}