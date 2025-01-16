/**
 * 3223. Minimum Length of String After Operations
 * Link: https://leetcode.com/problems/minimum-length-of-string-after-operations/description/?envType=daily-question&envId=2025-01-13
 * 
 * 
 * Approach: 
 * This approach focuses on counting characters based on their frequency. 
 * First, we calculate the frequency of each character in the string. 
 * For each character, 
 * if its frequency is even, we add two to the result; 
 * if odd, we add one. 
 * This ensures we account for the minimum possible contribution of each character to the final string length.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(26)
 */

class Solution {
    public int minimumLength(String s) {
        int n = s.length();

        int[] charFreq = new int[26];

        for(char ch: s.toCharArray()) {
            charFreq[ch - 'a']++;
        }

        int minLength = 0;
        for(int i = 0; i < 26; i++) {
            if(charFreq[i] == 0) {
                continue;
            }

            if(charFreq[i] % 2 == 0) {
                // ith character frequency is even so last 2 characters will remain
                minLength += 2;
            } else {
                // ith character frequency is odd so last 1 character will remain
                minLength += 1;
            }
        }

        return minLength;
    }
}

/*
abaacbcbb
a...a...a...a 
a...a
So only 2 characters is left out

a...a...a...a...a 
a...a...a
a
So only 1 characters is left out

Even: when we've even no. of characters than we can remove all characters with 2 remaining (as inorder to remove any character we need atleast 3 characters)
Odd: In case of odd no. of characters in the end only 1 character will left out
*/