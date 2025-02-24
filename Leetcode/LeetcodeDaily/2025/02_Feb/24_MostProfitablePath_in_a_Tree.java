/**
 * 2467. Most Profitable Path in a Tree
 * Link: https://leetcode.com/problems/most-profitable-path-in-a-tree/description/?envType=daily-question&envId=2025-02-24
 * 
 * Approach: Using DFS for Bob & DFS for Alice
 * The idea is to first find Bob’s path to node 0 using DFS and store the time he takes to reach each node. 
 * Then, Alice starts her own DFS traversal from node 0, deciding how much profit she can collect based on whether 
 * she reaches a node before, after, or at the same time as Bob. 
 * The goal is to maximize Alice’s income when she reaches a leaf node.
 * 
 * Complexity:
 * Time: O(n); due to two DFS traversals over all nodes
 * Space: O(n); due to adjacency list, visited array, and recursion stack
 */

class Solution {
    public int mostProfitablePath(int[][] edges, int bob, int[] amount) {
        // Approach:
        // As undirected tree is given with edges means its a graph with no cycle
        // edges[ai, bi] is given so we can form adjacency list which will help in
        // visiting neighbor nodes
        int n = amount.length;

        List<List<Integer>> adj = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        for(int i = 0; i < edges.length; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        
        // Step 1: We'll first form Map<node, time> for bob which will help in
        // considering whether reward is awarded to Alice or bob and also when both
        // time's matches means reward should be divided among each other.
        Map<Integer, Integer> bobMap = new HashMap<>();
        boolean[] visited = new boolean[n];

        // Step 2: Now we'll use DFS to populate bobMap
        // Here 0 is t = 0
        bobDFS(0, bob, visited, bobMap, adj);

        // Step 3: And than again use DFS for computing maxProfit taken by alice to
        // reach any leaf node from 0 node
        Arrays.fill(visited, false);  // reseting visited[] for Alice

        int[] maxProfit = new int[1];
        maxProfit[0] = Integer.MIN_VALUE;

        // aliceDFS(time, currentNode, income, maxProfit, visited, bobMap, adj, amount[])
        aliceDFS(0, 0, 0, maxProfit, visited, bobMap, adj, amount);

        return maxProfit[0];
    }

    // Populating bobMap using DFS
    boolean bobDFS(int t, int current, boolean[] visited, Map<Integer, Integer> bobMap, List<List<Integer>> adj) {
        // Step 1: Marking the current node as visited and updating the bobMap
        visited[current] = true;
        bobMap.put(current, t);

        // Step 2: Base Case: When bob reaches root node i.e., 0 than return true
        if(current == 0) {
            return true;
        }

        // Step 3: visiting neighbor nodes
        for(Integer adjacent: adj.get(current)) {
            if(!visited[adjacent]) {
                if(bobDFS(t + 1, adjacent, visited, bobMap, adj) == true) {
                    return true;
                }
            }
        }

        // Note: While bactracking remove unwanted path as we know there is only 1 path to root i.e., 0
        bobMap.remove(current);
        return false;
    }

    void aliceDFS(int t, int current, int income, int[] maxProfit, boolean[] visited, Map<Integer, Integer> bobMap, List<List<Integer>> adj, int[] amount) {
        // Step 1: First we'll mark the current node as visited
        visited[current] = true;

        // Step 2: Consider current income when there is no record of currentNode 
        // in bobMap OR time taken by alice is lower as compare to bob
        // Step 3: amount[current] is divided when both have same timing
        if(!bobMap.containsKey(current) || bobMap.get(current) > t) {
            income += amount[current];
        } else if(bobMap.get(current) == t) {
            income += (int)(amount[current] / 2);
        }

        // Step 4: Now computing maxProfit when reaches leaf node && its not a root node (i.e, 0)
        if(adj.get(current).size() == 1 && current != 0) {
            maxProfit[0] = Math.max(maxProfit[0], income);
        }

        // Step 5: Now visit the unvisited neighbors node
        for(Integer adjacent: adj.get(current)) {
            if(!visited[adjacent]) {
                aliceDFS(t + 1, adjacent, income, maxProfit, visited, bobMap, adj, amount);
            }
        }
    }
}