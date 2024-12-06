import java.util.*;

/*
 * 1346. Check If N and Its Double Exist
 * Link: https://leetcode.com/problems/check-if-n-and-its-double-exist/description/?envType=daily-question&envId=2024-12-01
 * 
 * 
 * Approach 1: BruteForce Approach
 */

class Solution1 {
    public boolean checkIfExist(int[] arr) {
        int n = arr.length;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if((arr[i] == 2 * arr[j]) || (arr[i] * 2 == arr[j])) {
                    return true;
                }
            }
        }

        return false;
    }
}

/*
 * Approach 2: Using Set
 */

class Solution {
    public boolean checkIfExist(int[] arr) {
        Set<Integer> set = new HashSet<>();

        for(int element: arr) {
            if(set.contains(2 * element) || (element % 2 == 0 && set.contains(element / 2))) {
                return true;
            }

            set.add(element);
        }

        return false;
    }
}