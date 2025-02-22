/**
 * 1028. Recover a Tree From Preorder Traversal
 * Link: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/?envType=daily-question&envId=2025-02-22
 * 
 * 
 * Approach:
 * Main function: 
 * The recoverFromPreorder function calls the helper function solve(). 
 * The traversal string has length n, and we're passing an index array idx to keep track of the current position 
 * as we recursively build the tree.
 * 
 * solve() function:
 * At each recursive call, we iterate over the string to determine the number of dashes (which is proportional to the 
 * current depth) and then extract the node value.
 * The key part of the time complexity comes from traversing the entire string while recursively building the tree.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(n)
 */

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode recoverFromPreorder(String traversal) {
        int n = traversal.length();

        // Note: need to pass idx by reference
        int[] idx = new int[1];
        idx[0] = 0;

        // solve(String, idx, depth, size);
        return solve(traversal, idx, 0, n);
    }

    private TreeNode solve(String s, int[] idx, int depth, int n) {
        // Base Case
        if(idx[0] >= n) {
            return null;
        }

        // Step 1: Find no. of dashes
        int j = idx[0];
        int dashes = 0;
        while(j < n && s.charAt(j) == '-') {
            j++;
        }

        dashes = j - idx[0];

        // Step 2: If dashes doesn't match with depth than return null as its not a correct position
        if(dashes != depth) {
            return null;
        } 

        // Step 3: If dashes matches with depth than add the node with num formed, before forming 
        // num (as it can be mora than 1 digit) make sure to reset idx to j pointer
        idx[0] = j;
        int num = 0;
        while(idx[0] < n && Character.isDigit(s.charAt(idx[0]))) {
            num = (num * 10) + s.charAt(idx[0]) - '0';
            idx[0]++;
        }

        TreeNode root = new TreeNode(num);

        // Step 4: After adding the node than make recursive call to first left & than right
        root.left = solve(s, idx, depth + 1, n);
        root.right = solve(s, idx, depth + 1, n);

        return root;
    } 
}