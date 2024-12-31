/**
 * 515. Find Largest Value in Each Tree Row
 * Link: https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/?envType=daily-question&envId=2024-12-25
 * 
 * Complexity:
 * Time: O(n); 
 * Space: O(n); In the worst case (for a balanced tree), the queue can hold up to n/2 nodes at the largest level 
 * (the level with the most nodes)
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
    public List<Integer> largestValues(TreeNode root) {
        // Using BFS
        if(root == null) {
            return new ArrayList<>();
        }

        List<Integer> largest = new ArrayList<>();

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while(!queue.isEmpty()) {
            int n = queue.size();

            int largestElement = Integer.MIN_VALUE;
            while(n-- > 0) {
                TreeNode currentNode = queue.poll();

                if(currentNode.val > largestElement) {
                    largestElement = currentNode.val;
                }

                if(currentNode.left != null) {
                    queue.add(currentNode.left);
                }

                if(currentNode.right != null) {
                    queue.add(currentNode.right);
                }
            }

            largest.add(largestElement);
        }

        return largest;
    }
}