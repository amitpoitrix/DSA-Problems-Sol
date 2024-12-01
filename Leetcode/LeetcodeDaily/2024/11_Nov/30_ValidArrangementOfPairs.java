import java.util.*;

/*
 * 2097. Valid Arrangement of Pairs
 * Link: https://leetcode.com/problems/valid-arrangement-of-pairs/description/?envType=daily-question&envId=2024-11-30
 * 
 * Approach
 * The solution finds a valid Eulerian path in a directed graph represented by a list of pairs. 
 * 
 * It involves the following steps:
 * Graph Construction: Build an adjacency list to represent the directed graph, while also tracking the 
 * indegree and outdegree of each node.
 * 
 * Start Node Identification: Identify the starting node of the Eulerian path. The start node is the node where 
 * outdegree - indegree == 1. If no such node exists, use the first node from the input pairs.
 * 
 * DFS to Construct Eulerian Path: Perform a depth-first search (DFS) using a stack to traverse the graph and 
 * construct the Eulerian path by removing edges as they are visited.
 * 
 * Result Construction: Reverse the Eulerian path obtained from DFS and convert it into a list of consecutive 
 * pairs, which forms the valid arrangement.
 * 
 * This approach ensures that all edges are used exactly once, yielding a valid Eulerian path in the given directed graph.
 */

class Solution {
    public int[][] validArrangement(int[][] pairs) {
        // Using Hierholzer's Algorithm - for Finding Euler's Path
        // Step 1: First find the adjaceny list and than find the indegree[] & outdegree[]

        // ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        // Here map is being used because node's aren't starting from 0
        Map<Integer, List<Integer>> adj = new HashMap<>();

        Map<Integer, Integer> indegree = new HashMap<>();
        Map<Integer, Integer> outdegree = new HashMap<>();

        for(int i = 0; i < pairs.length; i++) {    
            int u = pairs[i][0];
            int v = pairs[i][1];

            if(!adj.containsKey(u)) {
                adj.put(u, new ArrayList<>());
            }

            adj.get(u).add(v);
            
            indegree.put(v, indegree.getOrDefault(v, 0) + 1);
            outdegree.put(u, outdegree.getOrDefault(u, 0) + 1);
        }
        
        // Step 2: Now find the Starting node in Directed Graph where we need to find Euler's path
        int startingNode = pairs[0][0];
        // Getting nodes from adjacency list
        for(Map.Entry<Integer, List<Integer>> entry: adj.entrySet()) {
            Integer currentNode = entry.getKey();

            if(outdegree.getOrDefault(currentNode, 0) - indegree.getOrDefault(currentNode, 0) == 1) {
                startingNode = currentNode;
                break;
            }
        }

        // Step 3: Now apply dfs to find the Euler's path & remove traversed edges
        // We're removing traversed edges becoz we don't want to traverse it again 
        // just an alternative to visited[]
        // And what Euler path property says - once path is traversed it need to traverse again
        List<Integer> path = new ArrayList<>();
        dfs(startingNode, adj, path);
        Collections.reverse(path);

        int[][] result = new int[pairs.length][2];

        for(int i = 1; i < path.size(); i++) {
            result[i - 1][0] = path.get(i - 1);
            result[i - 1][1] = path.get(i);
        }

        return result;
    }

    private void dfs(int node, Map<Integer, List<Integer>> adj, List<Integer> path) {
        while(adj.containsKey(node) && !adj.get(node).isEmpty()) {
            // removing 0th idx from adj map
            int adjacentNode = adj.get(node).remove(0);

            dfs(adjacentNode, adj, path);
        }

        // Adding post order after processing
        path.add(node);
    }
}