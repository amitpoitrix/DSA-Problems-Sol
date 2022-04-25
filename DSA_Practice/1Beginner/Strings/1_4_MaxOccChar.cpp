#include<iostream>
// GFG : Maximum Occuring Character
// https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1
// Ques - We've to find char having max freq & should lexicographically smaller alphbet

// Algo:
// 1. Here we'll make use of HashMap so for this we'll take array of size 26 & traverse till str.length() & fill it up 
// with freq of each char how? 
// For this we've to find char idx of lower & uppercase character and than calculate freq of that char idx
// 2. Now we've to find max freq & its idx of that char so for this we've traverse till [0-25] i.e., 26 character/Alphabets
// 3. After getting char idx of lexicographically smaller & having max freq character we'll convert that char idx to char
// & than return that char

// TC - min(O(n), O(26))
// SC - O(26) ~ O(1)

class Solution{
public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(std::string str){
        // Taking array of size 26
        int arr[26] = {0};

        // Counting each character by first finding index of each character
        for (int i = 0; i < str.size(); i++){
            char ch = str[i];
            int charIdx = 0;
            // Getting idx for Lowercase character
            if(ch >= 'a' && ch <= 'z'){
                charIdx = ch - 'a'; // for ch = 'a' so 'a' - 'a' = 0 ; ch = 'z' so 'z' - 'a' = 25
            }
            // Getting idx for Uppercase character
            else if(ch >= 'A' && ch <= 'Z'){
                charIdx = ch - 'A';
            }
            arr[charIdx]++;
        }

        // Now finding the char having max freq lexicographically
        int maxi = -1, ans = -1;
        // Here we'll traverse through character array of size 26
        for (int i = 0; i < 26; i++){
            // Getting the max freq + idx of char
            if(maxi < arr[i]){
                ans = i;    // Getting char idx
                maxi = arr[i];  // Getting max freq of char
            }
        }
        
        // Now converting int to char
        char resultChar = 'a' + ans;
        return  resultChar;
    }
};

int main(){

    return 0;
}