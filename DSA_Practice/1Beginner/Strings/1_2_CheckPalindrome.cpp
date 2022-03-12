#include<iostream>
#include<vector>
// Leetcode : 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/

// Normal Check Palindrome in string
class Solution{
public:
    bool checkPalindrome(std::string s){
        int n = s.length();
        int start = 0;
        int end = n - 1;

        while (start < end){
            if(s[start] != s[end])
                return 0;
            else{
                start++;
                end--;
            }
        }
        
        return 1;
    }
};


// Actual Leetcode ques
class Solution1{
private:
    // Checking whether a valid char or not
    bool isValidChar(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
            return 1;
        
        return 0;
    }

    // Making Lowercase Character
    char makeLowerCase(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            return ch;
        else{
            char temp = ch - 'A' + 'a'; // for Making UpperCase to LowerCase temp = ch - 'a' + 'A';
            return temp;
        }
    }

public:
    bool checkPalindrome(std::string s){
        int n = s.length();
        int start = 0;
        int end = n - 1;

        while (start < end){
            if(!isValidChar(s[start])){
                start++;
                continue;
            }

            else if(!isValidChar(s[end])){
                end--;
                continue;
            }

            else if(makeLowerCase(s[start]) != makeLowerCase(s[end]))
                return 0;
            
            else{
                start++;
                end--;
            }
        }
        
        return 1;
    }
};


int main(){
    return 0;
}