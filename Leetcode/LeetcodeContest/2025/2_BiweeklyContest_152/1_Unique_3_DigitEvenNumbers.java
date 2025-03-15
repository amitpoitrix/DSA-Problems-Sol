/**
 * Q1. Unique 3-Digit Even Numbers
 * Link: https://leetcode.com/contest/biweekly-contest-152/problems/unique-3-digit-even-numbers/description/
 */

class Solution {
    public int totalNumbers(int[] digits) {
        int n = digits.length;
        
        Set<Integer> set = new HashSet<>();
        StringBuffer numFormed = new StringBuffer();
        
        Set<Integer> setCount = new HashSet<>();
        
        for(int i = 0; i < n; i++) {
            if(digits[i] == 0) {
                continue;
            }
            
            set.add(i);
            numFormed.append(digits[i]);
            
            // solve(digits[], set, lastDigit, count)
            solve(digits, set, numFormed, setCount);

            numFormed.deleteCharAt(numFormed.length() - 1);
            set.remove(i);
        }
        
        return setCount.size();
    }
    
    private void solve(int[] digits, Set<Integer> set, StringBuffer numFormed, Set<Integer> setCount) {
        // Base Case
        if(numFormed.length() == 3) {
            // possibility of 3 digit even no
            int num = Integer.parseInt(numFormed.toString());

            // System.out.println("num: " + num);
            
            if(num % 2 == 0) {
                setCount.add(num);
            }
            
            return;
        }
        
        // Recursive Case
        for(int i = 0; i < digits.length; i++) {
            if(!set.contains(i)) {
                set.add(i);
                numFormed.append(digits[i]);
                
                solve(digits, set, numFormed, setCount);

                numFormed.deleteCharAt(numFormed.length() - 1);
                set.remove(i);
            }
        }
    }
}