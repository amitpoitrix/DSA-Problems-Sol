/**
 * 2425. Bitwise XOR of All Pairings
 * Link: https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/?envType=daily-question&envId=2025-01-16
 * 
 * 
 * Approach 1: Bruteforce Approach - TLE
 * 
 * Complexity:
 * Time: O(n * m)
 * Space: O(1)
 */

class Solution1 {
    public int xorAllNums(int[] nums1, int[] nums2) {
        // Approach 1: Bruteforce Approach
        int xor = 0;

        for(int i = 0; i < nums1.length; i++) {
            for(int j = 0; j < nums2.length; j++) {
                xor ^= (nums1[i] ^ nums2[j]);
            }
        }

        return xor;
    }
}


/**
 * Approach 2: Direct XOR Property
 * This approach directly uses the XOR property, focusing on the parity of the lengths of nums1 and nums2. 
 * It XORs all elements of the other array when one array's length is odd, avoiding additional space usage.
 * 
 * Complexity:
 * Time: O(n + m)
 * Space: O(1)
 */

class Solution2 {
    public int xorAllNums(int[] nums1, int[] nums2) {
        // Approach 2: Optimised Approach
        int n = nums1.length;
        int m = nums2.length;

        if((n % 2 == 0) && (m % 2 == 0)) {
            // When both array lengths are even
            return 0;
        } else if((n % 2 != 0) && (m % 2 != 0)) {
            // when both array lengths are odd
            return findXor(nums1) ^ findXor(nums2);
        } else if(n % 2 != 0) {
            // if nums1 is odd than find xor of nums2
            return findXor(nums2);
        } else {
            // if nums2 is odd than find xor of nums1
            return findXor(nums1);
        }
    }

    private int findXor(int[] nums) {
        int xor = 0;

        for(int i = 0; i < nums.length; i++) {
            xor ^= nums[i];
        }

        return xor;
    }
}