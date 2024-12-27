/*
 * 1545. Find Kth Bit in Nth Binary String
 * Link: https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
 * 
 * 
 * Approach: 
 * 
 * Recursive Structure: The binary sequence at level n is built recursively by taking the sequence at level n-1, 
 * adding a '1', and then appending the reverse of n-1 where each bit is flipped. This pattern can be leveraged 
 * to recursively find the k-th bit.
 * 
 * Base Case: When n = 1, the sequence is just '0', so if the search reaches this level, the result is '0'.
 * 
 * Midpoint Check: The sequence length at level n is 2^n - 1. The midpoint is always '1'. If k is exactly at this 
 * midpoint, return '1'.
 * 
 * First Half: If k lies in the first half of the sequence, the answer can be found by recursively searching the 
 * corresponding position in the sequence for n-1.
 * 
 * Second Half: If k is in the second half, it corresponds to a mirrored and flipped bit of the first half. 
 * Recursively find the corresponding bit in the first half and flip it.
 * 
 * This approach efficiently uses recursion to handle the reverse and flip operations without generating the entire 
 * sequence explicitly.
 */

class Solution1 {
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


/**
 * Similar Questions:
 * 
 * 779. K-th Symbol in Grammar
 * https://leetcode.com/problems/k-th-symbol-in-grammar/description/
 * 
 * Explaination Diagram:
 * <img width="1361" alt="image" src="https://github.com/user-attachments/assets/484f99e7-2c4f-4f93-a5d8-27bd3eb392ad" />
 * 
 * Recursion Flow:
 * <img width="1011" alt="image" src="https://github.com/user-attachments/assets/eb0932ab-11cf-42d9-a4cb-17612893724f" />
 * 
 * Summary:
 * First draw diagram from n = 1 to 4 and observe the recursive calls needed.
 * 
 * Base Case: 
 * when n = 1 & k = 1 than we return 0
 * 
 * Recursive Case: 
 * We'll find the mid and if k <= mid than we'll call previous recursive call - solve(n - 1, k)
 * else we'll call previous recursive call with k as k - mid with ! (negation) - !solve(n - 1, k - mid)
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(n)
 */

class Solution2 {
    public int kthGrammar(int n, int k) {
        // Base Case
        if(n == 1 && k == 1) {
            return 0;
        }

        // Recursive Case
        int length = (int)Math.pow(2, n - 1);
        int mid = length / 2;

        if(k <= mid) {
            return kthGrammar(n - 1, k);
        } else {
            return 1 - kthGrammar(n - 1, k - mid); // negation
        }
    }
}


/**
 * 3307. Find the K-th Character in String Game II 
 * https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/description/
 */
