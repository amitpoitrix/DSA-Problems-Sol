#include<bits/stdc++.h>
using namespace std;

// Lt: 890. Find and Replace Pattern
// https://leetcode.com/problems/find-and-replace-pattern/

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for(int i = 0; i < words.size(); i++){  // Outer Loop to traverse over words
            // Hashmap1 for 1 to 1 mapping i.e, pattern[j] -> words[i][j]
            unordered_map<char, char> m1, m2;
            bool flag = true;
            
            for(int j = 0; j < words[i].size(); j++){  // Inner loop to traversing over each char of words[i]
                // words[i] = "ccc", pattern = "abb"
                auto it1 = m1.find(pattern[j]);  // Find "a"
                // We couldn't find a so insert "a" -> "c"
                if(it1 == m1.end()){
                    m1.insert({pattern[j], words[i][j]});   // a->c
                }
                else{   // if its already there than check if its mapping is same as last one
                    if(it1->second != words[i][j]){// if not than just break out
                        flag = false;
                        break;
                    }
                }
            
                // Hashmap2 reverse mapping 1 to 1 i.e., we're checking in two ways i.e, words[i][j] -> pattern[j]
                auto it2 = m2.find(words[i][j]); // Find "c"
                if(it2 == m2.end()){
                    m2.insert({words[i][j], pattern[j]});   // c->a
                }
                else{// Lets say 2nd time c comes up which points to b as c->b which should not be the case  
                    if(it2->second != pattern[j]){   
                        flag = false;
                        break;
                    }
                }
            }
            
            // If flag remains unchanged than only insert words[i]
            if(flag)
                ans.push_back(words[i]);
        }
        
        return ans;
    }
};

int main(){
    return 0;
}