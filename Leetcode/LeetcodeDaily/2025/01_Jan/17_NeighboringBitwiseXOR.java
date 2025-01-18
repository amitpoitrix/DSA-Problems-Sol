/**
 * 2683. Neighboring Bitwise XOR
 * Link: https://leetcode.com/problems/neighboring-bitwise-xor/description/?envType=daily-question&envId=2025-01-17
 * 
 * 
 * Approach 1: Simulation (Starting with 0 and 1)
 * This approach simulates the construction of the original array by trying both 
 * possible starting values (0 and 1) for the first element. 
 * It reconstructs the array using the XOR operation and checks if the last element satisfies the condition with the first.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(n)
 */

class Solution1 {
    public boolean doesValidArrayExist(int[] derived) {
        // Approach 1: Using XOR property for 3 no.'s i.e., x = y ^ z
        int n = derived.length;

        int[] original = new int[n];
        // Here original[] initially all are 0
        // i.e., original[0] = 0;
        for(int i = 0; i < n - 1; i++) {
            // derived[i] = original[i] ^ original[i + 1];
            original[i + 1] = original[i] ^ derived[i];
        }

        if(derived[n - 1] == (original[n - 1] ^ original[0])) {
            return true;
        }

        // Now Assuming original[0] as 1
        original[0] = 1;
        for(int i = 0; i < n - 1; i++) {
            original[i + 1] = original[i] ^ derived[i];
        }

        if(derived[n - 1] == (original[n - 1] ^ original[0])) {
            return true;
        }

        // At the end return false as we couldn't able to form original[]
        return false;
    }
}


/**
 * Approach 2: XOR Property Observation
 * This approach leverages the property that the XOR of all elements in the derived array must equal 0 for a valid 
 * original array to exist. 
 * It eliminates the need for array reconstruction, making it more space-efficient.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution2 {
    public boolean doesValidArrayExist(int[] derived) {
        // Approach 2: Using XOR property 
        int n = derived.length;

        // FInd xor of all elements of derived[i]
        int xor = 0;
        for(int i = 0; i < n; i++) {
            xor ^= derived[i];
        }

        // if xor is 0 than we can form original array else we can't
        return xor == 0;
    }
}