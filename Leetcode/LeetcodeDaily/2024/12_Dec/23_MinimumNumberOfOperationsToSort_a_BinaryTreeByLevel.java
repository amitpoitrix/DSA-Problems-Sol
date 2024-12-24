/**
 * 2471. Minimum Number of Operations to Sort a Binary Tree by Level
 * Link: https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/?envType=daily-question&envId=2024-12-23
 * 
 * 
 * Approach: 
 * The solution calculates the minimum number of operations required to sort the values at each level of a 
 * binary tree to achieve level-wise sorted order. The approach involves two main steps:
 * 
 * 1. Level-Order Traversal:
 * Perform a level-order traversal of the binary tree using a queue.
 * For each level, collect the node values into a list.
 * 
 * 2. Counting Minimum Swaps:
 * For each level's list, calculate the minimum number of swaps required to sort the list.
 * Use a hashmap to track the indices of elements for efficient swapping.
 * Iterate through the list, and whenever an element is out of place, swap it with its correct position, updating 
 * the hashmap accordingly.
 * Increment the swap count for every such operation.
 * 
 * Complexity:
 * Time: O(nlogn); where n is the number of nodes in the tree. This comes from the BFS traversal and the sorting 
 * required at each level. 
 * Space: O(n); due to the space used by the queue, the level nodes list, the sorted list, and the HashMap, all 
 * of which require space proportional to the number of nodes at any given level.
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
    public int minimumOperations(TreeNode root) {
        // Using BFS 
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        int minOperations = 0;
        while(!queue.isEmpty()) {
            int n = queue.size();

            List<Integer> levelNodes = new ArrayList<>();
            
            while(n-- > 0) {
                TreeNode currentNode = queue.poll();

                levelNodes.add(currentNode.val);

                if(currentNode.left != null) {
                    queue.offer(currentNode.left);
                }

                if(currentNode.right != null) {
                    queue.offer(currentNode.right);
                }
            }

            minOperations += findMinSwaps(levelNodes);
        }

        return minOperations;
    }

    // Finds min no. of swap to sort the list
    private int findMinSwaps(List<Integer> levelNodes) {
        // We'll make use of HashMap that will store {element, idx} & sorted levelNodes to get minSwaps
        int n = levelNodes.size();

        // creating HashMap
        Map<Integer, Integer> map = new HashMap<>();

        for(int i = 0; i < n; i++) {
            map.put(levelNodes.get(i), i);
        }

        // sorted list from orginal list
        List<Integer> sortedList = new ArrayList<>(levelNodes);
        Collections.sort(sortedList);

        int minSwaps = 0;
        for(int i = 0; i < n; i++) {
            // As we're using list (i.e., collections) use .equals() instead of "=="
            if(sortedList.get(i).equals(levelNodes.get(i))) {
                continue;
            }

            // unequal means swap is needed
            // first get the idx of correct element (i.e.,sorted list element) from map
            int correctIdx = map.get(sortedList.get(i));

            // updating map due to swap
            map.put(levelNodes.get(correctIdx), i);
            map.put(levelNodes.get(i), correctIdx);
            
            // swapping & updating map accordingly
            int temp = levelNodes.get(i);
            levelNodes.set(i, levelNodes.get(correctIdx));
            levelNodes.set(correctIdx, temp);

            // After swap incrementing swaps count
            minSwaps++;
        }

        return minSwaps;
    }
}