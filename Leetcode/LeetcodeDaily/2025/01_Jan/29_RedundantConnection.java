/**
 * 684. Redundant Connection
 * Link: https://leetcode.com/problems/redundant-connection/description/?envType=daily-question&envId=2025-01-29
 * 
 * 
 * Approach 1: Using DFS
 * Treat the graph as an undirected structure and build it edge by edge.
 * Before adding an edge, check if both nodes are already connected using DFS.
 * If they are, adding this edge creates a cycle, making it redundant.
 * 
 * Complexity:
 * Time: O(V^2); where O(V) * O(V) due to calling dfs() for each edges
 * Space: O(V)
 */

class Solution1 {
    public int[] findRedundantConnection(int[][] edges) {
        // Approach: 
        // We'll keep on adding edges in the adjacency list but before that we'll check whether we're able to reach 
        // node v from u (using either DFS/BFS traversal) if yes than current edge is the extra edge else connect 
        // that edge and check for new one.

        // Here no. of nodes (V) is equal to no. of edges (E)
        int V = edges.length;

        List<List<Integer>> adj = new ArrayList<>();

        for(int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        for(int i = 0; i < V; i++) {
            int u = edges[i][0] - 1;    // As nodes are [1, n] so making it [0, n-1]
            int v = edges[i][1] - 1;

            // visited[] for each DFS traversal
            boolean[] visited = new boolean[V];

            if(dfs(u, v, visited, adj) == true) {
                return edges[i];
            }

            // else joining the edges
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        return new int[] {-1, -1};
    }

    private boolean dfs(int src, int dest, boolean[] visited, List<List<Integer>> adj) {
        // check if we're able to reach destination node from source node
        if(src == dest) {
            return true;
        }

        visited[src] = true;

        for(Integer adjacent: adj.get(src)) {
            if(!visited[adjacent]) {
                if(dfs(adjacent, dest, visited, adj) == true) {
                    return true;
                }
            }
        }

        return false;
    }
}


/**
 * Approach 2: Using DSU
 * Use the Union-Find data structure to track connected components efficiently.
 * If two nodes of an edge belong to the same component, the edge is redundant.
 * Path compression and union by szie help optimize the process.
 * 
 * Complexity:
 * Time: O(V * alpha(V)) ~ O(V)
 * Space: O(V)
 */

class Solution2 {
    public int[] findRedundantConnection(int[][] edges) {
        // Approach: Using DSU
        // So the approach is to check whether both nodes (u & v) have same parents or not if yes than that's u->v 
        // is and extra edge else make union and check for next edge

        int V = edges.length;   // As no. of edges & no. of nodes both are same

        DSU dsu = new DSU(V);

        for(int i = 0; i < V; i++) {
            int u = edges[i][0] - 1;    // As node sre from [1, n] instead of [0, n-1]
            int v = edges[i][1] - 1;

            if(dsu.find(u) == dsu.find(v)) {
                return edges[i];
            }

            dsu.union(u, v);
        }

        return new int[] {-1, -1};
    }

    static class DSU {
        private int[] parent;
        private int[] size;

        public DSU(int n) {
            this.parent = new int[n];
            this.size = new int[n];

            for(int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        // O(alpha(n)) ~ constant
        public int find(int node) {
            if(node == parent[node]) {
                return node;
            }

            return parent[node] = find(parent[node]);
        }

        // O(alpha(n)) ~ constant
        public void union(int u, int v) {
            int uParent = find(u);
            int vParent = find(v);

            if(uParent == vParent) {
                return;
            }

            if(size[uParent] > size[vParent]) {
                // than uParent will be the ultimate parent of vParent
                parent[vParent] = uParent;
                size[vParent] += size[uParent];
            } else if(size[uParent] < size[vParent]) {
                parent[uParent] = vParent;
                size[vParent] += size[uParent];
            } else {
                // Anyone can become ultimate parent
                parent[uParent] = vParent;
                size[vParent] += size[uParent];
            }
        }
    }
}