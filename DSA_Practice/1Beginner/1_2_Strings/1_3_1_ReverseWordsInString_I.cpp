#include<iostream>
#include<algorithm>
using namespace std;

// Lt: 151. Reverse Words in a String
// https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int n = s.size(), i = 0, j = 0;
        while(i < n){
            while(i < n && s[i] == ' ')
                i++;
            
            if(i == n)
                break;
            
            j = i + 1;
            while(j < n && s[j] != ' ')
                j++;
            
            string sub = s.substr(i, j - i);  // [i, j-i-1]
            if(res.empty())
                res = sub;
            else
                res = sub + " " + res;
            
            i = j + 1;
        }

        return res;
    }
};

// Approach 2:
// TC - O(n)
// SC - O(1)
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        
        int l = 0, r = 0, i = 0, n = s.size();
        while(i < n){
            // Skipping the character with spaces
            while(i < n && s[i] == ' ')
                i++;
            
            // Adding reverse words char till it encounter space
            while(i < n && s[i] != ' ')
                s[r++] = s[i++];
            
            // if we can find a non-empty word then
            if(l < r){
                reverse(s.begin() + l, s.begin() + r);  // reverse current word
                if(r == n)
                    break;
                
                s[r++] = ' ';   // set empty space
                l = r;
            }
        }
        
        // skip last empty character if have
        if(r > 0 && s[r-1] == ' ')
            r--;
        
        s.resize(r);
        return s;
    }
};

int main(){
    return 0;
}