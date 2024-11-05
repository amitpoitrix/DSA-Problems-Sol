import java.util.*;

// Link: https://leetcode.com/problems/cousins-in-binary-tree-ii/?envType=daily-question&envId=2024-10-23

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

/*
 * Approach 1: Using two pass
 * 
 * With 1st pass the idea is to find level order sum
 * and than in 2nd pass update eah nodes value with (level sum - siblings sum)
 * We'll use BFS for level order traversal
 */
class Solution {
    public TreeNode replaceValueInTree(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        List<Integer> levelSum = new ArrayList<>();
        levelSum.add(root.val);

        // 1st Pass: Finding the sum at each level
        while(!queue.isEmpty()) {
            int n = queue.size();   // no. of nodes in current level;
            int currentLevelSum = 0;

            while(n-- > 0) {
                TreeNode current = queue.poll();

                if(current.left != null) {
                    currentLevelSum += current.left.val;
                    queue.offer(current.left);
                }

                if(current.right != null) {
                    currentLevelSum += current.right.val;
                    queue.offer(current.right);
                }
            }

            levelSum.add(currentLevelSum);
        }

        // 2nd pass: changing the value of each
        queue.offer(root);
        root.val = levelSum.get(0) - root.val;

        int level = 1;

        while(!queue.isEmpty()) {
            int n = queue.size();

            while(n-- > 0) {
                // using this current I can find the sibling sum of next level 
                // which is nothing but child of this current node
                TreeNode current = queue.poll();

                int siblingSum = current.left != null ? current.left.val: 0;
                siblingSum += current.right != null ? current.right.val: 0;

                if(current.left != null) {
                    current.left.val = levelSum.get(level) - siblingSum;
                    queue.offer(current.left);
                }

                if(current.right != null) {
                    current.right.val = levelSum.get(level) - siblingSum;
                    queue.offer(current.right);
                }
            }

            level++;
        }

        return root;
    }
}


// ***************************************************************************************************


/*
 * Approach 2: Using Single Pass
 * 
 * We'll compute total level nodes sum in the last iteration and than will update each node 
 * with its sibling sum Using BFS
 */
class Solution2 {
    public TreeNode replaceValueInTree(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();

        int nextTotalSum = root.val;
        int totalSum = nextTotalSum;
        root.val = totalSum - root.val; // here sibling is root.val only

        nextTotalSum = 0;

        while(!queue.isEmpty()) {
            int n = queue.size();

            totalSum = nextTotalSum;
            nextTotalSum = 0;

            while(n-- > 0) {
                TreeNode current = queue.poll();

                int siblingSum = current.left != null ? current.left.val: 0;
                siblingSum += current.right != null ? current.right.val: 0;

                current.val = totalSum - siblingSum;

                if(current.left != null) {
                    nextTotalSum += current.left.val;
                    current.left.val = siblingSum;
                    queue.offer(current.left);
                }

                if(current.right != null) {
                    nextTotalSum += current.right.val;
                    current.right.val = siblingSum;
                    queue.offer(current.right);
                }
            }

            System.out.println("nextTotalSum: " + nextTotalSum);
        }

        return root;
    }
}