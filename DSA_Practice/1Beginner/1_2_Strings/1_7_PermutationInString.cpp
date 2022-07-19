#include<iostream>
using namespace std;

// 567. Permutation in String
// https://leetcode.com/problems/permutation-in-string/
// Ques - We need to find whether s1 permutation(any) exist in s2 (as substring) or not

// Algo:
// 1. Logic : First we'll make hashmap of string s1 & count each char freq in arr[26] than we'll take a window of s1.length 
// and traverse on s2 string & simultaneously compute char freq(create another hashmap arr2[26] for string s2) that comes 
// under window size. Atlast compare both the hashmap if equals than return true.
// 2. While computing hashmap on s2 string make sure to remove previous element that doesn't come under window size
// 3. In ques it doesn't mention that s1 < s2 so make note of this point too 

// TC - O(m+n)
// SC - O(26) + O(26) ~ O(1)

class Solution {
private:
    bool isSame(int a[26], int b[26]){
        for(int i = 0; i < 26; i++){
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
    
public:
    bool checkInclusion(string s1, string s2) {
        // Char freq for string s1
        int arr1[26] = {0};
        for(int i = 0; i < s1.length(); i++){
            int charIdx = s1[i] - 'a';
            arr1[charIdx]++;
        }
        
        // Char freq for string s2
        int arr2[26] = {0};
        // Now taking window of size s1
        int window = s1.length();
        int i = 0;
        // Computing first window
        while(i < window && i < s2.length()){
            int charIdx = s2[i] - 'a';
            arr2[charIdx]++;
            i++;
        }
        
        if(isSame(arr1, arr2))
            return true;
        
        // Now shifting the window to next idx and removing 
        // old char which doesn't comes under window size
        while(i < s2.length()){
            // Insert new element to window
            int charIdx = s2[i] - 'a';
            arr2[charIdx]++;
            
            // Removing the old char
            char oldChar = s2[i - window];
            charIdx = oldChar - 'a';
            arr2[charIdx]--;
            
            if(isSame(arr1, arr2))
                return true;
            
            i++;
        }
        
        return false;
    }
};

int main(){
    return 0;
}