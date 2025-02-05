/**
 * 1790. Check if One String Swap Can Make Strings Equal
 * Link: https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/?envType=daily-question&envId=2025-02-05
 * 
 * 
 * Approach 1:
 * Intuition: Count the frequency of each character in both strings and track the differing positions.
 * If there are more than two differences or mismatched character counts, the strings can't be made equal with one swap.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(26)
 */

class Solution1 {
    public boolean areAlmostEqual(String s1, String s2) {
        // Approach 1: Using Difference Count + Map
        // Step 1: Count the no. of difference index and if more than 2 than return false
        // Step 2: Meanwhile maintain 2 frequency map of size 26 that tracks if any element is not there in another string

        int n = s1.length();

        int[] freq1 = new int[26];
        int[] freq2 = new int[26];

        int diffCount = 0;

        for(int i = 0; i < n; i++) {
            if(s1.charAt(i) != s2.charAt(i)) {
                diffCount++;

                // This will ensure only 1 swap is allowed in a string
                if(diffCount > 2) {
                    return false;
                }
            }

            // Tracking each character in each string
            freq1[s1.charAt(i) - 'a']++;
            freq2[s2.charAt(i) - 'a']++;
        }

        // Now checking mismatch characters with there frequency in each string
        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i]) {
                return false;
            }
        }

        return true;
    }
}


/**
 * Approach 2
 * Intuition: Identify the indices where characters differ.
 * If exactly two positions differ, swapping these characters should make the strings equal.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution2 {
    public boolean areAlmostEqual(String s1, String s2) {
        // Approach 2: Using just Difference Count
        // Step 1: Count the no. of difference index and if more than 2 than return false
        // Step 2: While counting difference do track of 1st & 2nd idx where it mismatches which will be help in checking
        // whether after swapping by once strings are equal or not

        int n = s1.length();

        int firstIdx = 0;
        int secondIdx = 0;

        int diffCount = 0;

        for(int i = 0; i < n; i++) {
            if(s1.charAt(i) != s2.charAt(i)) {
                diffCount++;

                // This will ensure only 1 swap is allowed in a string
                if(diffCount > 2) {
                    return false;
                } else if(diffCount == 1) {
                    firstIdx = i;
                } else {
                    secondIdx = i;
                }
            }
        }

        return s1.charAt(firstIdx) == s2.charAt(secondIdx) && s1.charAt(secondIdx) == s2.charAt(firstIdx);
    }
}