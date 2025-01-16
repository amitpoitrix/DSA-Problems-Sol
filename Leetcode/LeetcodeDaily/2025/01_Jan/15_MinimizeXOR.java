/**
 * 2429. Minimize XOR
 * Link: https://leetcode.com/problems/minimize-xor/description/?envType=daily-question&envId=2025-01-15
 * 
 * 
 * Approach 1: Starting from num1 and then forming the result
 * The intuition is to start with num1 and modify its bits to match the required number of set bits (1s) in num2. 
 * If num1 has fewer set bits than required, unset bits are turned on (0 -> 1) starting from the least significant bit (LSB). 
 * Conversely, if num1 has more set bits, the LSB bits are turned off (1 -> 0)
 * This ensures the result remains as close as possible to num1 while meeting the constraints.
 * 
 * Complexity:
 * Time: O(logn); as there is logn no. of set bits in given number n
 * Space: O(1)
 */

class Solution1 {
    public int minimizeXor(int num1, int num2) {
        // Approach 1: 
        int x = num1;

        int currentSetBit = Integer.bitCount(x);
        int requiredSetBit = Integer.bitCount(num2);

        int pos = 0;

        if(currentSetBit < requiredSetBit) {
            // So now we gonna add the set bit from LSB side
            while(currentSetBit < requiredSetBit) {
                // if bit is not set at position pos than only we're setting the bit and incrementing the current set bit count
                if(!isSetBit(x, pos)) {
                    x = setBit(x, pos);
                    currentSetBit++;
                }

                // 31....(pos + 3) (pos + 2) (pos + 1) (pos)
                // 31....3 2 1 0 -> total 32 bits
                pos++;
            }
        } else if(currentSetBit > requiredSetBit) {
            while(currentSetBit > requiredSetBit) {
                // if bit is set at position pos than only we can it unset
                if(isSetBit(x, pos)) {
                    x = unsetBit(x, pos);
                    currentSetBit--;
                }

                pos++;
            }
        }

        return x;
    }

    private boolean isSetBit(int x, int pos) {
        return (x & (1 << pos)) != 0;
    }

    private int setBit(int x, int pos) {
        x |= (1 << pos);

        return x;
    }

    private int unsetBit(int x, int pos) {
        x &= ~(1 << pos);

        return x;
    }
}


/**
 * Approach 2: Directly building the result
 * Here, the result is constructed from scratch by prioritizing the significant bits of num1. 
 * The algorithm first sets the highest significant bits of num1 to ensure minimal difference from it. 
 * If additional bits are needed, it sets unset bits starting from the least significant bit. 
 * This approach focuses on building a result with minimal XOR to num1 while achieving the required set bits.
 * 
 * Complexity:
 * Time: O(logn)
 * Space: O(1)
 */

class Solution2 {
    public int minimizeXor(int num1, int num2) {
        // Approach 2: 
        int x = 0;

        int requiredSetBit = Integer.bitCount(num2);

        // setting bit in x from MSB side
        for(int pos = 31; pos >= 0 && requiredSetBit > 0; pos--) {
            // if bit is set in num1 at position pos than only set bit in x in that pos
            if(isSetBit(num1, pos)) {
                x = setBit(x, pos);
                requiredSetBit--;
            }
        }

        // Now if required set bit is still there than we'll set from LSB side in x
        for(int pos = 0; pos < 32 && requiredSetBit > 0; pos++) {
            // if bit is not set in x than only set the bit at position pos
            if(!isSetBit(x, pos)) {
                x = setBit(x, pos);
                requiredSetBit--;
            }
        }

        return x;
    }

    private boolean isSetBit(int x, int pos) {
        return (x & (1 << pos)) != 0;
    }

    private int setBit(int x, int pos) {
        x |= (1 << pos);

        return x;
    }
}