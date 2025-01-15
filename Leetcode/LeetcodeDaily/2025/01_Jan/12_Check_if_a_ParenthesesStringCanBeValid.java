/**
 * 2116. Check if a Parentheses String Can Be Valid
 * Link: https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/?envType=daily-question&envId=2025-01-12
 * 
 * 
 * Approach 1: Using Stack
 * The intuition behind this approach is to use stacks to track the positions of unmatched open brackets and flexible 
 * positions ('0'). 
 * As we iterate through the string, we manage these stacks to simulate valid bracket pairing. 
 * Finally, we check if the unmatched open brackets can be matched with flexible positions by ensuring the order 
 * constraints are satisfied.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(n)
 */

class Solution1 {
    public boolean canBeValid(String s, String locked) {
        int n = s.length();

        if(n % 2 != 0) {
            return false;
        }

        Stack<Integer> open = new Stack<>();
        Stack<Integer> openClose = new Stack<>();

        for(int i = 0; i < n; i++) {
            if(locked.charAt(i) == '0') {
                openClose.push(i);
            } else {
                // means its locked - can't change it
                if(s.charAt(i) == ')') {
                    // if we got closed bracket
                    if(!open.isEmpty()) {
                        open.pop();
                    } else if(!openClose.isEmpty()) {
                        openClose.pop();
                    } else {
                        return false;
                    }
                } else {
                    // means we got open one
                    open.push(i);
                }
            }
        }

        while(!open.isEmpty() && !openClose.isEmpty() && open.peek() < openClose.peek()) {
            open.pop();
            openClose.pop();
        }

        // even though openClose stack is not empty it doesn't matter than they will have even no. of brackets that can 
        // match with each other to become valid
        return open.isEmpty();
    }
}


/**
 * Approach 2: Without Stack
 * This approach uses two passes (left-to-right and right-to-left) to count the balance of open and close brackets, 
 * treating flexible positions ('0') as either type as needed. 
 * The thought process is to ensure that at no point does the balance become invalid, confirming that the string can 
 * represent a valid sequence of brackets.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(1)
 */

class Solution2 {
    public boolean canBeValid(String s, String locked) {
        // Approach 2: Without using Stack space
        // We'll count no. of open brackets while traversing left to right and at any point if open becomes -ve than return false
        // Else if we'll traverse right to left and count no. of closed brackets, and if it becomes -ve than return false
        // else return true
        int n = s.length();

        if(n % 2 != 0) {
            return false;
        }

        // Case 1: First traversing from left to right and count no. of open brackets & at any point if it becomes -ve than return false.
        int openCount = 0;
        for(int i = 0; i < n; i++) {
            if(s.charAt(i) == '(' || locked.charAt(i) == '0') {
                openCount++;
            } else {
                openCount--;
            }

            // If at any point open bracket counts becomes -ve than return false
            if(openCount < 0) {
                return false;
            }
        }

        // Case 2: Now traversing from right to left and count no. of close brackets & at any point if it becomes -ve than return false.
        int closeBracket = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s.charAt(i) == ')' || locked.charAt(i) == '0') {
                closeBracket++;
            } else {
                closeBracket--;
            }

            if(closeBracket < 0) {
                return false;
            }
        }

        return true;
    }
}