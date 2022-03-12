#include<iostream>
// GFG : Maximum Occuring Character
// https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1

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
            // Lowercase
            if(ch >= 'a' && ch <= 'z'){
                // Converting lowercase char to int
                charIdx = ch - 'a';
            }
            // Uppercase
            else if(ch >= 'A' && ch <= 'Z'){
                // Converting Uppercase char to int
                charIdx = ch - 'A';
            }
            arr[charIdx]++;
        }

        // Now finding the char having max occurence
        int maxi = -1, ans = -1;
        // Here we'll traverse through character array of size 26
        for (int i = 0; i < 26; i++){
            // Getting the max count of char
            if(maxi < arr[i]){
                ans = i;
                maxi = arr[i];
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