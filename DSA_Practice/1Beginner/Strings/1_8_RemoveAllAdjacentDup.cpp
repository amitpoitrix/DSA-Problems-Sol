#include<iostream>
using namespace std;

// 1047. Remove All Adjacent Duplicates In String
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

// Algo:
// Take empty string and check whether its back element is equal to current ith element of given string if yes that pop_back() 
// from created string else push_back(current).

// TC - O(n)
// SC - O(n)

class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";
        for(char &c : s){
            if(!res.empty() && res.back() == c){
                res.pop_back();
            }
            else{
                res.push_back(c);
            }
        }
        
        return res;
    }
};

int main(){
    return 0;
}