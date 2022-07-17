#include<iostream>
#include<vector>
using namespace std;
// Leetcode : 344. Reverse String
// https://leetcode.com/problems/reverse-string/

// TC - O(n)
// SC - O(1)
class Solution {
public:
    void reverseString(std::vector<char> &s) {
        int n = s.size();
        // Traversing till n/2
        for (int i = 0; i < n / 2; i++){
            swap(s[i], s[n - i - 1]);
        }
    }
};

// Using Two Pointers Approach
class Solution1{
public:
    void reverseString(std::vector<char> &s) {
        int n = s.size();
        int start = 0;
        int end = n - 1;
        while(start < end){
            swap(s[start++], s[end--]);
        }
    }
};

int main(){
    return 0;
}