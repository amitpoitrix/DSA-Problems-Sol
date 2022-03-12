#include<iostream>
// Leetcode : 1910. Remove All Occurrences of a Substring

class Solution {
public:
    std::string removeOccurrences(std::string s, std::string part) {
        while (s.length() != '\0' && s.find(part) < s.length()){
            s.erase(s.find(part), part.length());
        }
        
        return s;
    }
};

int main(){
    return 0;
}