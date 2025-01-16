/**
 * 2657. Find the Prefix Common Array of Two Arrays
 * Link: https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/?envType=daily-question&envId=2025-01-14
 * 
 * 
 * Approach 1: Bruteforce Approach
 * The brute force approach iterates over each prefix of the arrays A and B and checks if elements in A are present 
 * in B up to the current index. 
 * This involves nested loops, leading to a time complexity of O(n3). 
 * The idea is straightforward but inefficient due to repeated comparisons.
 * 
 * Complexity:
 * Time: O(n^3)
 * Space: O(1); ignoring resultant[] size of n
 */

/*
A = [1,3,2,4]
B = [3,1,2,4]

In brute force for each i we'll check is there any B[i] matches with A[i] if yes we'll increase the count for each ith element
*/

class Solution1 {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        // Approach 1: Bruteforce Approach
        int n = A.length;
        int[] result = new int[n];
        
        for(int i = 0; i < n; i++) {

            int count = 0;
            for(int x = 0; x <= i; x++) {

                for(int y = 0; y <= i; y++) {
                    
                    if(A[x] == B[y]) {
                        count++;
                        break;
                    }
                }
            }
            result[i] = count;
        }

        return result;
    }
}


/**
 * Approach 2: Better Approach
 * This approach uses two boolean arrays to track which numbers have appeared in A and B up to the current index. 
 * For each prefix, it checks all numbers to count common elements. 
 * While still checking all numbers for each prefix, the use of auxiliary arrays reduces the complexity to O(n2).
 * 
 * Complexity:
 * Time: O(n^2)
 * Space: O(n)
 */

/*
A = [1,3,2,4]
B = [3,1,2,4]
           i 

     0 1 2 3 4
bA= [F,T,T,T,T] of size (n + 1), as here based on indexing we're going to change
bB= [F,T,T,T,T] 

count = 4
0 2 3 4
*/

class Solution2 {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        // Approach 2: Better Approach
        int n = A.length;
        int[] result = new int[n];

        boolean[] boolA = new boolean[n + 1];
        boolean[] boolB = new boolean[n + 1];
        
        for(int i = 0; i < n; i++) {

            boolA[A[i]] = true;
            boolB[B[i]] = true;

            int count = 0;

            for(int k = 1; k <= n; k++) {
                if(boolA[k] == true && boolB[k] == true) {
                    count++;
                }
            }

            result[i] = count;
        }

        return result;
    }
}


/**
 * Approach 3: Optimised Approach
 * The optimal approach leverages a hash map to track the frequency of elements from both arrays. 
 * When an element's frequency reaches 2, it indicates it is common in the prefix. 
 * This approach avoids redundant checks and achieves a linear time complexity of O(n), making it the most efficient 
 * solution.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(n)
 */

/*
A = [1,3,2,4]
B = [3,1,2,4]
           i

map[1] = 2
map[3] = 2
map[2] = 2
map[4] = 2

cumulativeCount = 4
0 2 3 4
*/

class Solution3 {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        // Approach 3: Optimised Approach
        int n = A.length;
        int[] result = new int[n];

        // we can use map
        Map<Integer, Integer> map = new HashMap<>();

        int cumulativeCount = 0;

        for(int i = 0; i < n; i++) {
            map.put(A[i], map.getOrDefault(A[i], 0) + 1);
            map.put(B[i], map.getOrDefault(B[i], 0) + 1);

            if(A[i] != B[i]) {
                // if current character doesn't match than check character frequency for both characters
                if(map.get(A[i]) == 2) {
                    cumulativeCount++;
                }

                if(map.get(B[i]) == 2) {
                    cumulativeCount++;
                }
            } else {
                // else check for any one character as both are same
                if(map.get(A[i]) == 2) { // or B[i]
                    cumulativeCount++;
                }
            }

            result[i] = cumulativeCount;
        }

        return result;
    }
}