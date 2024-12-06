import java.util.*;

/*
 * 2337. Move Pieces to Obtain a String
 * Link: https://leetcode.com/problems/move-pieces-to-obtain-a-string/description/?envType=daily-question&envId=2024-12-05
 * 
 * 
 * Approach 1: Recursive Backtracking with Memoization
 * Idea: Uses recursive backtracking to explore all possible valid transformations from the start string to the 
 * target string by swapping adjacent characters 'L' and 'R' with underscores (_), with memoization to avoid 
 * recomputation.
 * 
 * Complexity:
 * Time: Exponential in the worst case due to exploring all possible swaps, though memoization reduces redundant 
 * computations.
 * Space: High, due to the recursive call stack and memoization map.
 */

class Solution1 {
    public boolean canChange(String start, String target) {
        Map<String, Boolean> dp = new HashMap<>();

        return solver(start, target, dp);
    }

    private boolean solver(String start, String target, Map<String, Boolean> dp) {
        // Base Case
        if(start.equals(target)) {
            return true;
        }

        // Memoization 
        if(dp.containsKey(start)) {
            return dp.get(start);
        }

        // Recursive Solution
        int n = start.length();

        for(int i = 0; i < n; i++) {
            if(start.charAt(i) == '_') {
                continue;
            } 
            
            if(i > 0 && start.charAt(i - 1) == '_' && start.charAt(i) == 'L') {
                String newStart = swap(i - 1, i, start);   // swapping

                if(solver(newStart, target, dp)) {
                    dp.put(newStart, true);
                    return true;
                }

                // As original string is not swapped so no need to revert
            }
            
            if(i < n - 1 && start.charAt(i + 1) == '_' && start.charAt(i) == 'R') {
                String newStart = swap(i, i + 1, start);   // swapping

                if(solver(newStart, target, dp)) {
                    dp.put(newStart, true);
                    return true;
                }
            }
        }

        dp.put(start, false);
        return false;
    }

    // Swapping characters in String
    private String swap(int idx1, int idx2, String start) {
        char[] ch = start.toCharArray();

        char temp = ch[idx1];
        ch[idx1] = ch[idx2];
        ch[idx2] = temp;

        return new String(ch);
    }
}


/*
 * Approach 2: Two-Pointer Greedy Approach
 * Idea: Uses two pointers to simultaneously traverse the start and target strings, ensuring that 
 * characters L and R appear in valid positions relative to their movement constraints 
 * (L can only move left, and R can only move right).
 * 
 * Complexity:
 * Time: Linear, i.e., O(n), since each character is processed once.=
 * Space: Constant, i.e., O(1), since it uses only two pointers and no additional data structures.
 */

 class Solution2 {
    public boolean canChange(String start, String target) {
        int n = start.length();

        int i = 0;
        int j = 0;

        while(i < n || j < n) {
            // Skiiping the blanks
            while(i < n && start.charAt(i) == '_') {
                i++;
            }

            while(j < n && target.charAt(j) == '_') {
                j++;
            }

            if(i == n || j == n) {
                return i == n && j == n;
            }

            // if characters pointed by both pointers are not same than return false
            if(start.charAt(i) != target.charAt(j)) {
                return false;
            }

            // Now characters are same
            if(i < j && start.charAt(i) == 'L') {
                return false;
            }

            if(i > j && start.charAt(i) == 'R') {
                return false;
            }

            i++;
            j++;
        }

        return true;
    }
}