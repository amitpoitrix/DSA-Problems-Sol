/*
 * 1545. Find Kth Bit in Nth Binary String
 * Link: https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
 * 
 * 
 * Similar Questions:
 * 779. K-th Symbol in Grammar 
 * https://leetcode.com/problems/k-th-symbol-in-grammar/description/
 * 
 * 3307. Find the K-th Character in String Game II 
 * https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/description/
 */


/*
 * Approach: 
 * 
 * Recursive Structure: The binary sequence at level n is built recursively by taking the sequence at level n-1, 
 * adding a '1', and then appending the reverse of n-1 where each bit is flipped. This pattern can be leveraged 
 * to recursively find the k-th bit.
 * Base Case: When n = 1, the sequence is just '0', so if the search reaches this level, the result is '0'.
 * Midpoint Check: The sequence length at level n is 2^n - 1. The midpoint is always '1'. If k is exactly at this 
 * midpoint, return '1'.
 * First Half: If k lies in the first half of the sequence, the answer can be found by recursively searching the 
 * corresponding position in the sequence for n-1.
 * Second Half: If k is in the second half, it corresponds to a mirrored and flipped bit of the first half. 
 * Recursively find the corresponding bit in the first half and flip it.
 * This approach efficiently uses recursion to handle the reverse and flip operations without generating the entire 
 * sequence explicitly.
 */

class Solution {
    public char findKthBit(int n, int k) {
        // Using Recursion

        // Step 1: Base Case
        if(n == 1)
            return '0';

        // Step 2: Now based on ceil(length) < k, == k & > k
        int len = (1 << n) - 1; // 2^n - 1

        if(k < (len / 2) + 1) {
            return findKthBit(n - 1, k);
        } else if(k == (len / 2) + 1) {
            return '1';
        } else {
            // ceil(len / 2) > k
            return findKthBit(n - 1, len - k + 1) == '0' ? '1': '0';
        }
    }
}