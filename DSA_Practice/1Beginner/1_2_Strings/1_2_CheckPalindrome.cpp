#include<iostream>
#include<vector>
// Leetcode : 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/
// Normal Check Palindrome in string

// Algo:
// 1. Take two pointers pointing to start & end and check if both elements are equal or not, if not return false/0

// TC - O(n)
// SC - O(1)

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
// Ques : Check palindrome by removing/ignore all Non-AlphaNumeric elments + make all elements lowerCase

// Algo:
// 1. Take two pointers pointing to start & end and check if both elements are equal or not, if not return false/0
// 2. Remove/ignore all Non-AlphaNumeric elements first & than check for palindrome. 

// TC - O(n)
// SC - O(1)

class Solution1{
private:
    // Checking whether a valid char or not OR Checking for Non-AlphaNumeric char
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
            // First checking Non-AlphaNumeric for start pointer
            if(!isValidChar(s[start])){
                start++;
                continue;
            }
            // Now checking Non-AlphaNumeric for end pointer
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