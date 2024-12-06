/*
 * 2825. Make String a Subsequence Using Cyclic Increments
 * Link: https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/description/?envType=daily-question&envId=2024-12-04
 * 
 * Approach: Brute Force (Two Pointers)
 * 
 * Complexity:
 * Time: O(n + m)
 * Space: O(1)
 */


class Solution1 {
    public boolean canMakeSubsequence(String str1, String str2) {
        if(str1.length() < str2.length()) {
            return false;
        }

        int i = 0;
        int j = 0;

        while(i < str1.length() && j < str2.length()) {
            if(str1.charAt(i) == str2.charAt(j) || getNextChar(str1.charAt(i)) == str2.charAt(j)) {
                i++;
                j++;
            } else {
                i++;
                while(!(i < str1.length() && (str1.charAt(i) == str2.charAt(j) || getNextChar(str1.charAt(i)) == str2.charAt(j)))) {
                    if(i == str1.length()) {
                        return false;
                    }

                    i++;
                }

                i++;
                j++;
            }
        }

        if(j == str2.length()) {
            return true;
        } else {
            return false;
        }
    }

    private char getNextChar(char ch) {
        return (ch == 'z') ? 'a': (char)(ch + 1);
    }
}


/*
 * Approach 2: Two-Pointer Technique
 * 
 * We use two pointers i (for str1) and j (for str2), both initialized to zero.
 * 
 * Character Matching:
 * We iterate through both strings and check if the current character of str1 can match the current character 
 * of str2 based on the following conditions:
 * The characters are already equal (str1[i] == str2[j]).
 * Incrementing str1[i] by one makes it equal to str2[j] (str1[i] + 1 == str2[j]).
 * The character z wraps around to a, which is handled by checking if str1[i] - 25 == str2[j].
 * 
 * Subsequence Validation:
 * If a match is found under any of the above conditions, we increment the pointer j to move to the next character 
 * of str2.
 * 
 * Result:
 * If we successfully match all characters of str2 (j == n), we return true. Otherwise, we return false.
 * 
 * Complexity:
 * Time: O(m + n), where m is the length of str1 and n is the length of str2, as we traverse both strings linearly.
 * Space: O(1)
 */

class Solution2 {
    public boolean canMakeSubsequence(String str1, String str2) {
        int i = 0;
        int j = 0;

        while(i < str1.length() && j < str2.length()) {
            if(str1.charAt(i) == str2.charAt(j) || str1.charAt(i) + 1 == str2.charAt(j) || str1.charAt(i) - 25 == str2.charAt(j)) {
                j++;
            }

            i++;
        }

        return j == str2.length();
    }
}