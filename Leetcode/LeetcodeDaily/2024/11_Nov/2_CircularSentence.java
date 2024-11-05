/*
Link: https://leetcode.com/problems/circular-sentence/?envType=daily-question&envId=2024-11-02

Approach:
Approach is to first forn Strings Array of words and keep on comparing last character with first character of next 
word and last word last character with first word first character.
If it doesn't matches return false else true
*/

class Solution {
    public boolean isCircularSentence(String sentence) {
        int n = sentence.length();

        if(n == 1)
            return true;

        String[] words = sentence.split(" ");

        if(words.length == 1) {
            if(words[0].charAt(0) == words[0].charAt(words[0].length() - 1)) {
                return true;
            } else {
                return false;
            }
        } else {
            // There are more than one words
            int m = words.length;

            for(int i = 1; i < m; i++) {
                char lastCh = words[i - 1].charAt(words[i - 1].length() - 1);
                char firstCh = words[i].charAt(0);

                if(lastCh != firstCh) {
                    return false;
                }
            }

            char lastCh = words[m - 1].charAt(words[m - 1].length() - 1);
            char firstCh = words[0].charAt(0);

            if(lastCh != firstCh)
                return false;
        }

        return true;
    }
}