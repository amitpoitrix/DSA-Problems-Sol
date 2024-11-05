/*
 * Link: https://leetcode.com/problems/flip-equivalent-binary-trees/?envType=daily-question&envId=2024-10-24
 * 
 * 
 * Approach:
 * 
 * The approach for checking if two binary trees are flip equivalent involves a recursive comparison of the trees' structures and values:
 * Base Case: If both nodes are null, the trees are trivially flip equivalent.
 * Null Handling: If one node is null and the other isn't, the trees cannot be flip equivalent.
 * Value Comparison: If the current nodes of both trees have the same value, two scenarios are recursively checked:
 * The left and right subtrees of both trees match without flipping.
 * The left subtree of one tree matches the right subtree of the other, and vice versa (this accounts for flipping).
 * Return False: If the values don't match or neither of the recursive cases holds, the trees are not flip equivalent.
 * This recursive approach ensures both normal and flipped subtrees are checked at each node.
 */


class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public boolean flipEquiv(TreeNode root1, TreeNode root2) {
        // Base Case
        if(root1 == null && root2 == null)
            return true;

        if(root1 == null || root2 == null) 
            return false;

        // Recursive code
        if(root1.val == root2.val) {
            boolean withoutFLip = flipEquiv(root1.left, root2.left) && flipEquiv(root1.right, root2.right);
            boolean withFLip = flipEquiv(root1.right, root2.left) && flipEquiv(root1.left, root2.right);

            return withoutFLip || withFLip;
        }

        return false;
    }
}