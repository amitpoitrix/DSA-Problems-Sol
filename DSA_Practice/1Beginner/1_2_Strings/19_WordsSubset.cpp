#include <bits/stdc++.h>
using namespace std;

// Lt: 916. Word Subsets
// https://leetcode.com/problems/word-subsets/

class Solution {
private:
    // Function to return freq of ch in s
    int countFreq(string s, char ch){
        int cnt = 0;
        for(auto c: s){
            if(c == ch)
                cnt++;
        }
        return cnt;
    }
    
    // Function to check subset based on freq count of each char
    bool isSubset(string s, vector<int> &freqCount2){
        for(char ch = 'a'; ch <= 'z'; ch++){
            // Checking false condition
            if(countFreq(s, ch) < freqCount2[ch - 'a']) 
                return false;
        }
        
        return true;
    }
    
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        vector<int> freqCount2(26, 0);  // max freq of each char of words2
        
        // Traversing over words2 to get all its strings
        for(string s: words2){  
            // Traversing over each char of each string to find max freq
            for(char ch = 'a'; ch <= 'z'; ch++){
                freqCount2[ch - 'a'] = max(freqCount2[ch - 'a'], countFreq(s, ch));
            }
        }
        
        // Now traversing over each string od words1 to get universal string
        for(string s: words1){
            if(isSubset(s, freqCount2))
                res.push_back(s);
        }
        
        return res;
    }
};

int main(){
    return 0;
}