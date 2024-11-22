/*
 * 2914. Minimum Number of Changes to Make Binary String Beautiful
 * Link: https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/?envType=daily-question&envId=2024-11-05
 * 
 * Approach 1: Iterative Counting and Tracking
 * 
 * Description: This approach involves iterating through the string and counting consecutive characters while 
 * checking for matches with the previous character sequence. If the count of consecutive characters is even, 
 * the sequence is reset. If the count is odd, the character must be changed, and the change counter is incremented.
 * 
 * Time Complexity: O(n), where n is the length of the string.
 * Space Complexity: O(1) because no additional data structures are used.
 * 
 * Key Points:
 * Tracks sequences of consecutive characters.
 * Ensures that changes are only made when the count of consecutive characters is odd.
 */


class Solution {
    public int minChanges(String s) {
        int n = s.length();

        char lastCh = s.charAt(0);
        int count = 1;  // to keep track of length of substring
        int changes = 0;    // no. of changes required

        for(int i = 1; i < n; i++) {
            if(lastCh == s.charAt(i)) {
                // if character is same than keep on incrementing count
                count++;
                continue;
            }

            if(count % 2 == 0) {
                // if length of substring is even, means no changes required and 
                // current ch won't take part in previous substring formed
                count = 1;  // count is 1 because from this we're started forming new substring
            } else {
                // count is odd means current char should take part in forming even length
                // of substring and changes is required
                changes++;
                count = 0;  // count is 0 because current char is being used in forming previous even length substring
            }

            lastCh = s.charAt(i);
        }

        return changes;
    }
}


/*
 * Approach 2: Iterative Check in Pairs
 * 
 * Description: This simpler approach iterates through the string by checking characters in pairs (i.e., indexes i 
 * and i+1). If the two characters in a pair differ, a change is required, and the changes counter is incremented. 
 * The loop increments by 2 to ensure only adjacent pairs are checked.
 * 
 * Time Complexity: O(n), as it scans through the string in a single pass.
 * Space Complexity: O(1) since no extra space is used.
 * 
 * Key Points:
 * Operates by checking each adjacent pair directly.
 * Simpler logic focused on pairwise differences.
 */

class Solution2 {
    public int minChanges(String s) {
        // Approach 2: Here we'll forget about the partition as we'll consider min
        // even length partition of size 2

        int n = s.length();

        int changes = 0;

        for(int i = 0; i < n; i += 2) {
            if(s.charAt(i) != s.charAt(i + 1)) {
                changes++;
            }
        }

        return changes;
    }
}