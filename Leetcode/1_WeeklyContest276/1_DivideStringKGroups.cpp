#include<iostream>
#include<vector>
// Leetcode - Weekly Contest 276 on 16th Jan 2022
// 1. 2138. Divide a String Into Groups of Size k

class Solution {
public:
    std::vector<std::string> divideString(std::string s, int k, char fill) {
        std::vector<std::string> res;
        for (int i = 0; i < s.size(); i++){
            if(i % k == 0){
                res.push_back("");
            }
            res.back() += s[i];
        }
        
        while (res.back().size() < k){
            res.back() += fill;
        }
        
        return res;
    }
};

int main(){
    std::string s = "abcdefghij";
    int k = 3;
    char fill = 'x';

    Solution obj;
    std::vector<std::string> result = obj.divideString(s, k, fill);

    for (auto x : result){
        std::cout << x << " ";
    }

    return 0;
}