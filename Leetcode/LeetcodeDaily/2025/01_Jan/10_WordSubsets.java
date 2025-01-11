/**
 * 916. Word Subsets
 * Link: https://leetcode.com/problems/word-subsets/description/?envType=daily-question&envId=2025-01-10
 * 
 * 
 * Approach:
 * This approach determines the universal strings in words1 by comparing character frequencies. Here's a breakdown:
 * 
 * Calculate Maximum Character Frequencies for words2:
 * Iterate through each string in words2.
 * Use a temporary frequency array (temp) to count the occurrences of each character in the current string.
 * Update a global frequency array (freq2) to store the maximum frequency of each character across all strings 
 * in words2.
 * 
 * Check Each String in words1:
 * For each string in words1, calculate its character frequency using a temporary array (temp).
 * Compare the frequencies in temp with freq2 using the isSubset helper function.
 * If temp satisfies the subset condition, add the string to the result.
 * 
 * Helper Function (isSubset):
 * Compares two frequency arrays and ensures that for each character, the frequency in temp is at least as much as 
 * in freq2.
 * 
 * Key Insight:
 * By precomputing the maximum frequency requirements for words2, the algorithm efficiently checks each string 
 * in words1 for universality without redundant computations.
 * 
 * Complexity:
 * Time: O((n * a) + (m * b)); where n is the length of words1[] & a is length of each word1 string, similarly for
 * words
 * Space: O(26) ~ O(1)
 */

class Solution {
    public List<String> wordSubsets(String[] words1, String[] words2) {
        // Step 1: Precomputing words2[] each word character frequency
        int[] freq2 = new int[26];

        for(String word2: words2) {
            int[] temp2 = new int[26];

            for(char ch: word2.toCharArray()) {
                temp2[ch - 'a']++;

                freq2[ch - 'a'] = Math.max(freq2[ch - 'a'], temp2[ch - 'a']);
            }
        }

        // Step 2: Now finding universal strings
        List<String> result = new ArrayList<>();

        for(String word1: words1) {
            int[] temp1 = new int[26];

            for(char ch: word1.toCharArray()) {
                temp1[ch - 'a']++;
            }

            if(isSubset(temp1, freq2)) {
                result.add(word1);
            }
        }

        return result;
    }

    private boolean isSubset(int[] temp1, int[] freq2) {
        for(int i = 0; i < 26; i++) {
            if(temp1[i] < freq2[i]) {
                return false;
            }
        }

        return true;
    }
}