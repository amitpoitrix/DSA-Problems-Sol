/**
 * 2415. Reverse Odd Levels of Binary Tree
 * Link: https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/?envType=daily-question&envId=2024-12-20
 * 
 * 
 * Approach 1: Using BFS
 * Idea: 
 * Perform a level-order traversal (BFS) using a queue to process nodes level by level. 
 * At each odd level, reverse the values of the nodes.
 * 
 * Steps:
 * Use a queue to store nodes of the current level.
 * Collect nodes at each level into a list.
 * If the level is odd, swap values between nodes from opposite ends of the list.
 * 
 * Complexity:
 * Time: O(n) + O(n) ~ O(n); The time spent in BFS is O(n) (as we visit each node exactly once) & The time spent 
 * reversing the values at each odd level is also O(n) in total because we're processing each node at odd levels once.
 * Space: O(n);  due to the space used by the BFS queue and the list to store nodes at each level.
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
class Solution1 {
    public TreeNode reverseOddLevels(TreeNode root) {
        // Using BFS
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        int level = 0;

        while(!queue.isEmpty()) {
            int n = queue.size();

            List<TreeNode> levelNodes = new ArrayList<>();

            while(n-- > 0) {
                TreeNode currentNode = queue.poll();

                levelNodes.add(currentNode);

                if(currentNode.left != null) {
                    queue.offer(currentNode.left);
                }

                if(currentNode.right != null) {
                    queue.offer(currentNode.right);
                }
            }

            if(level % 2 != 0) {
                // Now level is odd so we've to reverse the list
                int i = 0;
                int j = levelNodes.size() - 1;

                while(i < j) {
                    int temp = levelNodes.get(i).val;
                    levelNodes.get(i).val = levelNodes.get(j).val;
                    levelNodes.get(j).val = temp;
                    i++;
                    j--;
                }
            }

            level++;
        }

        return root;
    }
}


/**
 * Approach 2: DFS(Recursion Leap Of Faith)
 * Idea: 
 * Use a recursive DFS to traverse the tree simultaneously from the leftmost and rightmost nodes of each level. 
 * At odd levels, swap the values of the paired nodes.
 * 
 * Steps:
 * Recursively process left and right subtrees in a mirrored fashion.
 * Swap values of nodes at odd levels.
 * 
 * Complexity:
 * Time: O(n)
 * Space: O(n)
 */

class Solution2 {
    public TreeNode reverseOddLevels(TreeNode root) {
        // Using DFS
        solve(root.left, root.right, 1);
        return root;
    }

    private void solve(TreeNode left, TreeNode right, int level) {
        // Base Case
        if(left == null && right == null) {
            return;
        }

        if(level % 2 != 0) {
            // means odd level so we've reverse it
            int temp = left.val;
            left.val = right.val;
            right.val = temp;
        }

        solve(left.left, right.right, level + 1);
        solve(left.right, right.left, level + 1);
    }
}