/**
 * 1930. Unique Length-3 Palindromic Subsequences
 * Link: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/?envType=daily-question&envId=2025-01-04
 * 
 * 
 * Approach 1: Iterative Search for First and Last Indices
 * This approach iterates over the string to identify unique characters. 
 * For each character, it finds its first and last occurrence by scanning the string again. 
 * The characters between these indices are stored in a set to avoid duplicates, and their count is added to the 
 * result.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(1) (constant size for 26 letters).
 */

class Solution1 {
    public int countPalindromicSubsequence(String s) {
        // Approach 1:
        // Step 1: Storing unique characters in set
        int n = s.length();

        Set<Character> set = new HashSet<>();
        for(char ch: s.toCharArray()) {
            set.add(ch);
        }

        // Step 2: Now place each unique characters in first & last position and compute
        // count of unique palindromic subsequence
        int count = 0;

        for(char ch: set) {
            // Step 1: Now we'll find the first & last idx of current char and whatever
            // characters lie between them will be no. of unique palindromic subsequence
            int firstIdx = -1;
            int lastIdx = -1;

            for(int i = 0; i < n; i++) {
                if(s.charAt(i) == ch) {
                    if(firstIdx == -1) {
                        firstIdx = i;
                    }

                    lastIdx = i;
                }
            }

            // Step 2: Now we'll compute subsequence
            Set<Character> tempSet = new HashSet<>();
            for(int mid = firstIdx + 1; mid <= lastIdx - 1; mid++) {
                tempSet.add(s.charAt(mid));
            }

            count += tempSet.size();
        }

        return count;
    }
}


/**
 * Approach 2: Precomputed First and Last Indices
 * This approach precomputes the first and last occurrence of each character in a single pass, storing them in a 
 * fixed-size array. 
 * For each character, it iterates over the precomputed range to count distinct middle characters using a set, 
 * avoiding redundant scans and improving clarity.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(1) (constant size for 26 letters).
 */

class Solution2 {
    public int countPalindromicSubsequence(String s) {
        // Approach 2:
        int n = s.length();

        // Step 1: Precompute Pair<firstIdx, lastIdx>[] for each 26 characters
        Pair[] pairChar = new Pair[26];
        // Note: Avoid using Arrays.fill(pairChar, new Pair(-1, -1)); as it'll create reference to same Pair Object
        for(int i = 0; i < 26; i++) {
            pairChar[i] = new Pair(-1, -1);
        }

        for(int i = 0; i < n; i++) {
            int idx = s.charAt(i) - 'a';

            if(pairChar[idx].firstIdx == -1) {
                pairChar[idx].firstIdx = i;
            }

            pairChar[idx].lastIdx = i;
        }

        // Step 2: Counting unique palindromic subsequence
        int count = 0;

        for(int i = 0; i < 26; i++) {
            int firstIdx = pairChar[i].firstIdx;
            int lastIdx = pairChar[i].lastIdx;

            if(firstIdx == -1 || firstIdx == lastIdx) {
                continue;
            }

            Set<Character> tempSet = new HashSet<>();

            for(int mid = firstIdx + 1; mid <= lastIdx - 1; mid++) {
                tempSet.add(s.charAt(mid));
            }

            count += tempSet.size();
        }

        return count;
    }

    static class Pair {
        int firstIdx;
        int lastIdx;

        Pair(int firstIdx, int lastIdx) {
            this.firstIdx = firstIdx;
            this.lastIdx = lastIdx;
        }
    }
}