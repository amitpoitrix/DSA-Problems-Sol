/**
 * 1400. Construct K Palindrome Strings
 * Link: https://leetcode.com/problems/construct-k-palindrome-strings/description/?envType=daily-question&envId=2025-01-11
 * 
 * 
 * Approach: 
 * Edge Case Handling:
 * If the length of the string s is less than k, it is impossible to form k palindromes, so return false.
 * If the length of the string s is equal to k, each character can be placed in its own palindrome, so return true.
 * 
 * Character Frequency Count:
 * Use a frequency array (freq) to count the occurrences of each character in s.
 * 
 * Count Odd Frequencies:
 * Traverse the frequency array to count the number of characters that appear an odd number of times (oddCount).
 * 
 * Key Observation:
 * A character with an odd frequency must appear in its own palindrome (e.g., for "aaaab", the b must be a separate 
 * palindrome).
 * Therefore, the number of odd-count characters (oddCount) determines the minimum number of palindromes required.
 * 
 * Final Check:
 * If oddCount greater than k, it's impossible to form k palindromes, so return false.
 * Otherwise, return true, as we can distribute the even-count characters among the k palindromes.
 * 
 * Key Insight
 * The approach leverages the relationship between odd-frequency characters and palindromes:
 * 
 * Odd-count characters determine the minimum number of palindromes required.
 * Even-count characters can be freely distributed across the palindromes.
 * 
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution {
    public boolean canConstruct(String s, int k) {
        if(s.length() < k) {
            return false;
        }

        if(s.length() == k) {
            return true;
        }

        // Now we'll compute no. of characters having odd no. of frequency
        int[] charFreq = new int[26];
        for(char ch: s.toCharArray()) {
            charFreq[ch - 'a']++;
        }

        int oddCharFreq = 0;
        for(int i = 0; i < 26; i++) {
            if(charFreq[i] % 2 != 0) {
                oddCharFreq++;
            }
        }

        return oddCharFreq <= k;
    }
}