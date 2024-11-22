/*
 * 2516. Take K of Each Character From Left and Right
 * Link: https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/description/?envType=daily-question&envId=2024-11-20
 * 
 * 
 * Approach 1: Using Recursion
 * 
 * This approach uses recursion to explore all possible ways to delete characters from either the left 
 * or right of the string to ensure that at least k occurrences of 'a', 'b', and 'c' are present in the deleted 
 * characters.
 * 
 * Key Features:
 * Maintains a frequency array to track the counts of 'a', 'b', and 'c'.
 * Recursively tries both options: delete from the left or delete from the right.
 * Returns the minimum number of deletions required.
 * 
 * Drawbacks: 
 * The time complexity is exponential (O(2^n)), making it impractical for large inputs.
 */

 class Solution {
    int minTime = Integer.MAX_VALUE;

    public int takeCharacters(String s, int k) {
        // Approach 1: Using Recursion
        // Step 1: recursively take 1 character from either left or right and increment the minutes variable & if left pointer becomes greater than right than we'll return
        // Step 2: We'll maintain a counter array that stores the freq of a, b & c characters and increment it accordingly while removing characters from either left or right

        int i = 0;
        int j = s.length() - 1;

        int[] freq = new int[3];
        int minutes = 0;

        solver(i, j, minutes, freq, s, k);

        return minTime == Integer.MAX_VALUE ? -1: minTime;
    }

    private void solver(int i, int j, int minutes, int[] freq, String s, int k) {
        // Base Case
        if(freq[0] >= k && freq[1] >= k && freq[2] >= k) {
            minTime = Math.min(minTime, minutes);
            return;
        }

        if(i > j) {
            return;
        }

        // Recursive Code
        // Removing leftmost characters
        char leftChar = s.charAt(i);
        freq[leftChar - 'a']++;
        solver(i + 1, j, minutes + 1, freq, s, k);
        freq[leftChar - 'a']--;

        // Removing rightmost characters
        char rightChar = s.charAt(j);
        freq[rightChar - 'a']++;
        solver(i, j - 1, minutes + 1, freq, s, k);
        freq[rightChar - 'a']--;
    }
}


/*
 * Approach 2: Using Sliding Window
 * 
 * This approach optimizes the problem using the sliding window technique to find the largest substring (window) 
 * that can remain untouched while ensuring the deleted characters meet the k requirement for 'a', 'b', and 'c'.
 * 
 * Key Features:
 * Uses two pointers (i and j) to define the current window and dynamically adjust it based on character counts.
 * If the current window causes any character count to fall below k, it shrinks the window from the left to 
 * restore validity.
 * Computes the minimum deletions as total length - max valid window size.
 * 
 * Advantages: 
 * Efficient with a time complexity of O(n), suitable for large inputs.
 */

 class Solution2 {
    public int takeCharacters(String s, int k) {
        // Approach: Using Sliding Window
        // Step 1: Find the freq of each character and check whether there freq are atleast k or not

        // 0 -> 'a', 1 -> 'b', 2 -> 'c'
        int[] freq = new int[3];

        for(char ch: s.toCharArray()) {
            freq[ch - 'a']++;
        }

        if(freq[0] < k || freq[1] < k || freq[2] < k) {
            return -1;
        }

        // Step 2: Now we'll apply our Sliding Window Approach
        int left = 0;
        int right = 0;
        int n = s.length();

        int minTime = Integer.MAX_VALUE;

        while(right < n) {
            // 1. First we're consider character at right pointer in our window which contains characters that need not to be deleted
            freq[s.charAt(right) - 'a']--;

            // 2. Now if window becomes invalid because of inclusion of character at right pointer than we need to make window valid by moving left pointer
            while(left <= right && (freq[0] < k || freq[1] < k || freq[2] < k)) {
                // means our window is invalid
                freq[s.charAt(left) - 'a']++;

                left++;
            }

            // 3. Now if condition satisfies than we'll compute minTime
            if(freq[0] >= k && freq[1] >= k && freq[2] >= k) {
                int windowLength = right - left + 1;

                minTime = Math.min(minTime, n - windowLength);
            }

            right++;
        }

        return minTime == Integer.MAX_VALUE ? -1: minTime;
    }
}

// window -> subarray that need not to be deleted and it should be as max as possible so that
// overall time taken to remove characters from either side of the string comes out to min

// aabaaaacaabc
//             i
//             j

// // freq of characters that I'm going to delete
// a -> 8
// b -> 2
// c -> 2
// still above freq satisfy the consdition as each character is >= k

// time = 8 (i.e., n - windowLength)