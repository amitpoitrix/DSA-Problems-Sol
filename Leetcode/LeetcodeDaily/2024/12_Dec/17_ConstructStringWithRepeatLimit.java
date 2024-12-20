/**
 * 2182. Construct String With Repeat Limit
 * Link: https://leetcode.com/problems/construct-string-with-repeat-limit/description/?envType=daily-question&envId=2024-12-17
 * 
 * 
 * Approach 1: Greedy with Frequency Array
 * Key Idea: 
 * Use a frequency array to keep track of character counts and process characters in descending order (starting from 'z').
 * 
 * Steps:
 * Traverse the frequency array and append the largest character up to repeatLimit times.
 * If the current character has remaining occurrences, append the next largest character once to avoid violating 
 * the repeatLimit.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(n)
 */

class Solution1 {
    public String repeatLimitedString(String s, int repeatLimit) {
        // Step 1: Create a frequency array of size 26
        int[] charFreq = new int[26];

        for(char ch: s.toCharArray()) { // O(n)
            charFreq[ch - 'a']++;
        }

        // Step 2: Than traverse from right to left to get the greater character first 
        // and than add it in the resultant string min(char_freq, repeatLimit) times
        StringBuilder result = new StringBuilder(); // O(n) ~ space

        int i = 25;
        while(i >= 0) {
            // only move i when its char freq is 0
            if(charFreq[i] == 0) {
                i--;
                continue;
            }

            char currentChar = (char)('a' + i);
            int freq = Math.min(charFreq[i], repeatLimit);

            result.append(String.valueOf(currentChar).repeat(freq));    // O(n)
            charFreq[i] -= freq;

            if(charFreq[i] > 0) {
                // find next smallest alphabet to break the current character streak
                int j = i - 1;
                while(j >= 0) {
                    if(charFreq[j] != 0) {
                        break;
                    }

                    j--;
                }

                if(j < 0) {
                    break;
                }

                char nextChar = (char)('a' + j);

                result.append(nextChar);
                charFreq[j]--;
            }
        }

        return result.toString();
    }
}


/**
 * Approach 2: Max Heap (Priority Queue)
 * Key Idea: 
 * Use a max heap (priority queue) to always fetch the largest available character efficiently.
 * 
 * Steps:
 * Insert all distinct characters into a max heap based on their order.
 * Pop the largest character, append it up to repeatLimit times, and reinsert it into the heap if it still has
 * remaining occurrences.
 * Append the next largest character if needed to avoid exceeding the repeatLimit.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(n)
 */

class Solution2 {
    public String repeatLimitedString(String s, int repeatLimit) {
        int[] charFreq = new int[26];
        for(char ch: s.toCharArray()) { // O(n)
            charFreq[ch - 'a']++;
        }

        Queue<Character> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        
        for(int i = 0; i < 26; i++) {
            if(charFreq[i] != 0) {
                char currChar = (char)('a' + i);
                maxHeap.offer(currChar);
            }
        }

        StringBuilder result = new StringBuilder(); // O(n) ~ space

        while(!maxHeap.isEmpty()) {
            char currentChar = maxHeap.poll();
            int freq = Math.min(charFreq[currentChar - 'a'], repeatLimit);

            result.append(String.valueOf(currentChar).repeat(freq));
            charFreq[currentChar - 'a'] -= freq;

            if(charFreq[currentChar - 'a'] > 0 && !maxHeap.isEmpty()) {
                char nextChar = maxHeap.poll();
                result.append(nextChar);
                
                charFreq[nextChar - 'a']--;

                if(charFreq[nextChar - 'a'] > 0) {
                    maxHeap.offer(nextChar);
                }

                maxHeap.offer(currentChar);
            }
        }

        return result.toString();
    }
}