/**
 * 2493. Divide Nodes Into the Maximum Number of Groups
 * Link: https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/description/?envType=daily-question&envId=2025-01-30
 * 
 * 
 * Approach:
 * 
 * Before Merging
 * https://github.com/user-attachments/assets/58e8b04b-2206-4551-a805-10a14295f391
 * 
 * After Merging
 * https://github.com/user-attachments/assets/114f42be-f44c-4462-b58a-8c08e980ca36
 * 
 * If two nodes are connected they can't be in same group:
 * https://github.com/user-attachments/assets/ff0820fd-6087-43d7-932f-f67193a71bca
 * 
 * Check Bipartite or not ?
 * https://github.com/user-attachments/assets/ae5d048d-d546-4410-8ce8-aec0c6b24ef4
 * 
 * Now to compute no. of groups we can use BFS not necessarily starts from 0 (or source node), so check from each node
 * https://github.com/user-attachments/assets/0d557979-acf1-4a65-80b6-7c1cb8e59139
 * 
 * Summary:
 * https://github.com/user-attachments/assets/6f264fc2-542a-4122-9de8-d26aadb64684
 * 
 * 
 * Step 1 (Bipartite Check using DFS)
 * Treat the graph as a bipartite structure and attempt to color it with two colors (Red and Green).
 * Start from an unvisited node and color it with one color.
 * Using DFS, try to color all its neighbors with the opposite color.
 * If any neighbor has the same color as the current node, the graph is not bipartite, and we return -1.
 * If the entire graph is bipartite, proceed to the next step.
 * 
 * Step2 (Level Calculation using BFS)
 * Perform a BFS starting from each unvisited node to calculate the "level" or depth of each connected component. 
 * For each node, visit its neighbors and increment the level.
 * This helps determine the maximum depth or the maximum number of groups in the component.
 * Keep track of the levels for each component to use them in the next step.
 * 
 * Step 3 (Aggregate Max Groups from Components)
 * Once the BFS is done for all nodes, sum the maximum levels (group sizes) from all connected components.
 * For each unvisited node, calculate the maximum level in its connected component and accumulate the results. 
 * The sum of these values gives the final answer, i.e., the maximum number of magnificent sets in the graph.
 * 
 * 
 * Complexity:
 * Time: O(V * (V + E))
 * Space: O(V + E)
 */


class Solution {
    public int magnificentSets(int n, int[][] edges) {
        // Approach:
        // Step 1: First we'll form adjacency list from given edges (undirected graph)
        List<List<Integer>> adj = new ArrayList<>();

        // O(V)
        for(int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        // O(E)
        for(int i = 0; i < edges.length; i++) {
            int u = edges[i][0] - 1;    // due to 1 based indexing so doing -1 as to avoid visited[n+1]
            int v = edges[i][1] - 1;    

            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        // Step 2: Now we'll traverse over each component of graph and check whether graphs are Bipartite or not, if not than return -1
        int[] color = new int[n];
        Arrays.fill(color, -1);

        // O(V + E)
        for(int i = 0; i < n; i++) {
            // starting from color 0
            if(color[i] == -1) {
                if(checkBipartiteDFS(i, 0, color, adj) == false) {
                    return -1;
                }
            }
        }

        // Step 3: Now from observation it is understood that no. of Graph is nothing but no. of levels from starting node, now we need to start from each node in the component to get max no. of levels(i.e., groups) for that we can maintain level[] that will store levels reach from each ith node
        int[] level = new int[n];
        
        // O(V * (V + E))
        for(int i = 0; i < n; i++) {
            // Note: Here we didn't take visited[] as we'll maintain at each bfs level
            level[i] = bfs(i, level, adj, n);
        }

        // Step 4: Now we'll again go to each component of graph and get its max no. of group formed from each component
        int maxGroup = 0;
        boolean[] visited = new boolean[n]; // for each component of graph

        // O(V + E)
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                maxGroup += maxGroupCountDFS(i, level, visited, adj);
            }
        }

        return maxGroup;
    }

    // Function to check whether graph component is Bipartite or not
    private boolean checkBipartiteDFS(int currentNode, int currentColor, int[] color, List<List<Integer>> adj) {
        color[currentNode] = currentColor;

        for(Integer adjacent: adj.get(currentNode)) {
            if(color[adjacent] == -1) {
                if(checkBipartiteDFS(adjacent, 1 - currentColor, color, adj) == false) {
                    return false;
                }
            } else if(color[adjacent] == color[currentNode]) {
                return false;
            }
        }

        return true;
    }

    // Count the no. of level (groups) using BFS
    private int bfs(int sourceNode, int[] level, List<List<Integer>> adj, int V) {
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(sourceNode);

        // visited[] at each bfs level
        boolean[] visited = new boolean[V];
        visited[sourceNode] = true;

        int levelCount = 1;

        while(!queue.isEmpty()) {
            int size = queue.size();

            while(size-- > 0) {
                Integer currentNode = queue.poll();

                for(Integer adjacent: adj.get(currentNode)) {
                    if(!visited[adjacent]) {
                        visited[adjacent] = true;
                        queue.offer(adjacent);
                    }
                }
            }

            levelCount++;
        }

        return levelCount - 1;  // As after last queue element level is still increasing so we need to do -1
    }

    // Computing max no. of group size by traversing over each node of component and getting the max of it
    private int maxGroupCountDFS(int currentNode, int[] level, boolean[] visited, List<List<Integer>> adj) {
        int maxSize = level[currentNode];
        visited[currentNode] = true;

        for(Integer adjacent: adj.get(currentNode)) {
            if(!visited[adjacent]) {
                maxSize = Math.max(maxSize, maxGroupCountDFS(adjacent, level, visited, adj));
            }
        }

        return maxSize;
    }
}