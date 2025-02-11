/**
 * 1910. Remove All Occurrences of a Substring
 * Link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/?envType=daily-question&envId=2025-02-11
 * 
 * 
 * Approach 1: 
 * Repeatedly searches for the substring (part) in s and removes it.
 * Continues this process until part no longer exists in s.
 * Simple and direct, but inefficient due to repeated string modifications.
 * 
 * Complexity:
 * Time: O(m * n); where m is the no. of occurence of part in s and n is the length of s
 * Space: O(n); becoz of forming s 
 */

class Solution1 {
    public String removeOccurrences(String s, String part) {
        // O(m)
        while(true) {
            int idx = s.indexOf(part);  // O(n)

            if(idx == -1) {
                break;
            }

            s = s.substring(0, idx) + s.substring(idx + part.length()); // O(n)
        }

        return s;
    }
}


/**
 * Approach 2: Using Stack
 * Uses a stack to simulate string processing while checking for part dynamically.
 * If the top of the stack forms part, it removes those characters.
 * Reduces frequent substring searches, making it more optimized.
 * 
 * Complexity:
 * Time: O(m * (m + n)); where m is the length of s & n is the length of n
 * Space: O(m)
 */

class Solution2 {
    public String removeOccurrences(String s, String part) {
        // Approach 2: Using Stack
        int n = part.length();

        Stack<Character> st = new Stack<>();

        // O(m * (m + n))
        for(int i = 0; i < s.length(); i++) {
            // Step 1: Blindly adding characters in stack
            st.push(s.charAt(i));

            // Step 2: If stack size is greater than or equal to part.length than check if stack characters of length part 
            // matches with part if yes than remove from stack
            if(st.size() >= n && checkEqual(st, part, n)) {     // O(m + n) - due to checkEqual()
                // Removing part strings character by character from top of stack
                for(int j = 0; j < n; j++) {    // O(n)
                    st.pop();
                }
            }
        }

        StringBuilder sb = new StringBuilder();

        // O(m)
        while(!st.isEmpty()) {
            sb.append(st.pop());
        }

        return sb.reverse().toString();
    }
    
    // O(m + n)
    private boolean checkEqual(Stack<Character> st, String part, int n) {
        // Taking temp stack in utility function to avoid making changes in original stack
        Stack<Character> tempStack = new Stack<>();
        // Copying all items from original stack using addAll()
        tempStack.addAll(st);   // O(m)

        // O(n)
        for(int i = n - 1; i >= 0; i--) {
            if(tempStack.peek() != part.charAt(i)) {
                return false;
            }

            tempStack.pop();
        }

        return true;
    }
}


/** 
 * Approach 3: Using string as stack
 * Uses a StringBuilder as a stack-like structure.
 * Appends characters and removes the last n characters if they match part.
 * Optimized approach with minimal extra space usage.
 * 
 * Complexity:
 * Time: O(m * n)
 * Space: O(m)
 */

class Solution3 {
    public String removeOccurrences(String s, String part) {
        // Approach 3: Using string as stack
        StringBuilder sb = new StringBuilder();

        // O(m * n)
        for(int i = 0; i < s.length(); i++) {
            sb.append(s.charAt(i));

            // O(n)
            if(sb.length() >= part.length() && sb.substring(sb.length() - part.length()).equals(part)) {
                // Note: Using sb.setLength(len) to change the original length of sb
                sb.setLength(sb.length() - part.length());      // O(1)
            }
        }

        return sb.toString();
    }
}
