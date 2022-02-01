#include<iostream>
#include<vector>
// Recursion by Striver : Leetcode : 131. Palindrome Partitioning

// TC - 4^(n*m)
// SC - O(n*m)
class Solution {
private:
    bool isPalindrome(int start, int end, std::string s){
        while (start <= end){
            if(s[start++] != s[end--])
                return false;
        }
        
        return true;
    }

    void palindromePartitioning(int idx, std::string s, std::vector<std::string> &path , std::vector<std::vector<std::string>> &res){
        if(idx == s.size()){
            res.push_back(path);
            return;
        }

        for (int i = idx; i < s.size(); i++){
            if(isPalindrome(idx, i, s)){
                path.push_back(s.substr(idx, i - idx + 1));
                // As we don't want equal no. of recursive calls in each iteration so passing i + 1 instead of idx + 1 
                palindromePartitioning(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }

public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> path;

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