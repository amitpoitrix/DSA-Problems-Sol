#include<iostream>
using namespace std;

// Leetcode : 1910. Remove All Occurrences of a Substring
// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

// Algo:
// 1. Traverse till length of string and find pos of substring to remove/erase & than remove it

// TC - O(n)
// SC - O(1)

// Inbuilt string function
// str.find(subString) -> find the pos of substring in str or else points to str.end() i.e., npos
// str.erase(pos_of_substring_to_remove, length_of_substring_to_remove) -> removes substring from str
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.length() != '\0' && s.find(part) < s.length()){
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

int main(){
    return 0;
}