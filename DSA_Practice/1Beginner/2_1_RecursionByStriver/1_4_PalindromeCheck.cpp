#include<iostream>
// Recursion by Striver

// Checking palindrome using Recursion
bool checkPalindrome(int i, std::string s){
    if(i >= s.size()/2)
        return true;
    
    else if(s[i] != s[s.size()-i-1])
        return false;
    
    return checkPalindrome(i+1, s);
} 

int main(){
    std::string s = "naman";

    if(checkPalindrome(0, s))
        std::cout << "Its a Palindrome";
    else
        std::cout << "Not a Palindrome";

    return 0;
}