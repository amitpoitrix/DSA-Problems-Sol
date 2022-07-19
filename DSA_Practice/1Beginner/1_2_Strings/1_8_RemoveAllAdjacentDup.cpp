#include<iostream>
using namespace std;

// 1047. Remove All Adjacent Duplicates In String
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

// Approach 1 : Using stack
// Algo:
// Take empty string and check whether its back element is equal to current ith element of given string if yes than
//  pop_back() from created string else push_back(current).

// TC - O(n)
// SC - O(n)
class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";
        for(char &c : s){
            if(!res.empty() && res.back() == c)
                res.pop_back();
            else
                res.push_back(c);
        }
        return res;
    }
};

// Approach 2: Using two pointers
// TC - O(n)
// SC - O(1)
class Solution1{
public:
    string removeDuplicates(string s) {
        int i = 0, n = s.size();
        for(int j = 0; j < n; j++, i++){
            s[i] = s[j];
            if(i > 0 && s[i-1] == s[i])
                i -= 2;
        }
        return s.substr(0, i);
    }
};

int main(){
    return 0;
}