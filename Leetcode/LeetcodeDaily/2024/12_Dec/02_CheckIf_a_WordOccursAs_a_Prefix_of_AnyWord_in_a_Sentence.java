/*
 * 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
 * Link: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/?envType=daily-question&envId=2024-12-02
 * 
 * 
 * Complexity:
 * Time: O(n + w * k), where n = length of the sentence string, w = number of words in sentence, k = length of the searchWord.
 * Space: O(w)
 */

class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {
        String[] sentArr = sentence.split(" ");

        for(int i = 0; i < sentArr.length; i++) {
            if(sentArr[i].startsWith(searchWord)) {
                return i + 1;
            }
        }

        return -1;
    }
}