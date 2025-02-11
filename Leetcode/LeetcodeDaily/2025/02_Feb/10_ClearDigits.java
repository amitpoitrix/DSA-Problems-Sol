/**
 * 3174. Clear Digits
 * Link: https://leetcode.com/problems/clear-digits/description/?envType=daily-question&envId=2025-02-10
 * 
 * Approach 1: Using Stack
 * Use a stack to store characters, pushing letters and popping when encountering digits.
 * 
 * Complexity: 
 * Time: O(n)
 * Space: O(n)
 */

class Solution1 {
    public String clearDigits(String s) {
        Stack<Character> st = new Stack<>();

        // O(n)
        for(char ch: s.toCharArray()) {
            if(ch >= '0' && ch <= '9') {
                if(!st.isEmpty()) {
                    st.pop();   // O(1)
                }
            } else {
                st.push(ch);    // O(1)
            }
        }

        StringBuilder sb = new StringBuilder();

        // O(n)
        while(!st.isEmpty()) {
            sb.append(st.pop());
        }

        // O(n)
        return sb.reverse().toString();
    }
}


/**
 * Approach 2: Using string as Stack
 * Instead of a stack, maintain a result string, appending letters and popping when encountering digits.
 */

class Solution2 {
    public String clearDigits(String s) {
        int n = s.length();

        StringBuilder sb = new StringBuilder();

        int i = 0;

        while(i < n) {
            char ch = s.charAt(i);

            if(ch >= '0' && ch <= '9') {
                sb.deleteCharAt(sb.length() - 1);
            } else {
                sb.append(ch);
            }

            i++;
        }

        return sb.toString();
    }
}


/**
 * Approach 3: Inplace - Optimised Approach
 * Modify the string directly using two pointers—one for reading and one for writing.
 */

class Solution3 {
    public String clearDigits(String s) {
        // Approach 3: Optimised Approach - inplace
        int n = s.length();

        // Step 1: Converting to character array so that swap is simple
        char[] charArr = s.toCharArray();

        int i = 0;
        int j = 0;

        while(i < n) {
            if(Character.isDigit(charArr[i])) {
                // if ith character is digit than move j one backward
                j = Math.max(0, j - 1); // to avoid j becomes -ve
            } else {
                // else replace ith character with jth and move j by 1
                charArr[j] = charArr[i];
                j++;
            }

            // i pointer will move as it is
            i++;    
        }

        return new String(charArr, 0, j);   // create new string starting from [0, j-1]
    }
}