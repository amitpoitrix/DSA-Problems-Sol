/*
 * 2109. Adding Spaces to a String
 * Link: https://leetcode.com/problems/adding-spaces-to-a-string/description/?envType=daily-question&envId=2024-12-03
 * 
 * 
 * Complexity:
 * Time: O(m * n); where m is the length of the spaces array and n is the length of the string s.
 * Space: O(n + m), where n is the length of the string s and m is the length of the spaces array.
 */

class Solution {
    public String addSpaces(String s, int[] spaces) {
        StringBuilder sb = new StringBuilder();

        int startIdx = 0;
        for(int i = 0; i < spaces.length; i++) {
            if(spaces[i] == 0) {
                sb.append(" ");
                startIdx = spaces[i];
            }
            else {
                sb.append(s.substring(startIdx, spaces[i]));
                sb.append(" ");

                startIdx = spaces[i];
            }
        }

        sb.append(s.substring(startIdx));

        return sb.toString();
    }
}