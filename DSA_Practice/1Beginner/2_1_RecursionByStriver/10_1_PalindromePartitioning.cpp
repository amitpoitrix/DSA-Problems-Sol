#include<iostream>
#include<vector>
using namespace std;
// Recursion by Striver : Leetcode : 131. Palindrome Partitioning
// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
private:
    bool isPalindrome(int start, int end, string s){
        while (start <= end){
            if(s[start++] != s[end--])
                return false;
        }
        
        return true;
    }

    void palindromePartitioning(int idx, string s, vector<string> &path, vector<vector<string>> &res){
        if(idx == s.size()){
            res.push_back(path);
            return;
        }

        for (int i = idx; i < s.size(); i++){
            if(isPalindrome(idx, i, s)){
                path.push_back(s.substr(idx, i - idx + 1));
                palindromePartitioning(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;

        palindromePartitioning(0, s, path, res);
        return res;
    }
};

int main(){
    std::string s = "aabb";

    Solution obj;
    for (auto x : obj.partition(s)){
        for (auto y : x){
            for (auto z : y){
                std::cout << z << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    
    return 0;
}