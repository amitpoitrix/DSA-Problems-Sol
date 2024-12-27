/**
 * 3203. Find Minimum Diameter After Merging Two Trees
 * Link: https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/description/?envType=daily-question&envId=2024-12-24
 * 
 * 
 * Approach 1: 
 * To calculate the minimum diameter after merging two trees, the approach involves:
 * 
 * 1. Building the Adjacency List:
 * Construct the adjacency list for both trees using the given edges, stored in a Map.
 * 
 * 2. Calculating Tree Diameters:
 * Use a two-step BFS approach to calculate the diameter of each tree:
 * First BFS finds the farthest node from any arbitrary node (e.g., node 0).
 * Second BFS from the farthest node gives the tree's diameter.
 * 
 * 3. Merging the Trees:
 * The combined diameter is computed as (d1 + 1) / 2 + (d2 + 1) / 2 + 1.
 * 
 * Result:
 * The final result is the maximum of the three values: the diameter of tree 1, tree 2, and the combined diameter.
 * 
 * Complexity:
 * Time: O((V1 + E1) + (V2 + E2)); where n1 and n2 are the number of nodes in the two trees. The time complexity comes from 
 * creating the adjacency lists and performing two BFS operations for each tree.
 * Space: O((V1 + E1) + (V2 + E2)); where n1 and n2 are the number of nodes in the two trees. The space complexity comes from 
 * storing the adjacency lists and the BFS-related data structures (queue, visited array).
 */

class Solution {
    public int minimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        // Step 1: First create adjacencyList from given edges
        ArrayList<ArrayList<Integer>> adj1 = createAdjacencyList(edges1);
        ArrayList<ArrayList<Integer>> adj2 = createAdjacencyList(edges2);

        // Step 2: Now find the diameter of both Trees as well there combination
        int d1 = diameterOfGraph(adj1);
        int d2 = diameterOfGraph(adj2);

        int combinedTreeDiameter = ((d1 + 1) / 2) + ((d2 + 1) / 2) + 1;

        // Step 3: Now return the diameter which is max of all those above threes diameter
        return Math.max(combinedTreeDiameter, Math.max(d1, d2));
    }

    private ArrayList<ArrayList<Integer>> createAdjacencyList(int[][] edges) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

        for(int i = 0; i < edges.length + 1; i++) {
            adj.add(new ArrayList<>());
        }

        for(int[] edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        return adj;
    }

    private int diameterOfGraph(ArrayList<ArrayList<Integer>> adj) {
        // Step 1: Choose any random node and find the farthest node
        Pair firstEndNode = bfs(adj, 0);

        // Step 2: find the another farthest node from above node
        Pair secondEndNode = bfs(adj, firstEndNode.farthestNode);

        return secondEndNode.distance;
    }

    private Pair bfs(ArrayList<ArrayList<Integer>> adj, int source) {
        int n = adj.size();
        boolean[] visited = new boolean[n];
        
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(source);
        visited[source] = true;

        int distance = 0;
        int endNode = source;

        while(!queue.isEmpty()) {
            int size = queue.size();

            while(size-- > 0) {
                int currentNode = queue.poll();
                endNode = currentNode;

                for(Integer adjacentNode: adj.get(currentNode)) {
                    if(!visited[adjacentNode]) {
                        visited[adjacentNode] = true;
                        queue.offer(adjacentNode);
                    }
                }
            }

            // As we're computing diameter so
            if(!queue.isEmpty()) {
                distance++;
            }
        }

        return new Pair(endNode, distance);
    }

    static class Pair {
        int farthestNode;
        int distance;

        public Pair(int farthestNode, int distance) {
            this.farthestNode = farthestNode;
            this.distance = distance;
        }
    }
}