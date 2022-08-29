#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> str;
        
        string ans = "";
        for(auto ch: s){
            if(ch == ' ' || ch == '/0'){
                str.push_back(ans);
                ans = "";
            }
            else{
                ans.push_back(ch);
            }
        }
        str.push_back(ans);
        
        if(pattern.size() != str.size()){
            return false;
        }
        
        unordered_map<char, string> mp;
        for(int i = 0; i < s.size(); i++){
            if(mp.find(pattern[i]) == mp.end())
                mp[pattern[i]] = str[i];
            
            else{
                if(mp[pattern[i]] != str[i])
                    return false;
            }
        }
        
        return true;
    }
};

int main(){

}