import java.util.*;

/*
 * 3243. Shortest Distance After Road Addition Queries I
 * Link: https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/description/?envType=daily-question&envId=2024-11-27
 * 
 * Approach 1: Using BFS
 * Purpose: Finds the shortest path in an unweighted graph.
 * Technique: Explores nodes level by level, ensuring the first time a node is reached is via the shortest path.
 * 
 * Time Complexity: O(V+E), where V is the number of vertices and E is the number of edges.
 * 
 * Pros:
 * Simpler and faster for unweighted graphs.
 * Directly computes the shortest path in terms of the number of edges.
 * 
 * Cons:
 * Less flexible for handling graphs with weighted edges.
 */

class Solution1 {
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        // Step 1: Make adjacency list from n no. of nodes
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        // Step 2: connect node i to (i + 1) 
        for(int i = 1; i < n; i++) {
            adj.get(i-1).add(i);
        }

        // Step 3: Traverse over each query and add the edges in the adjacency list and pass it to BFS to find the shortest path to reach 0 to n-1 nodes and store that path in ans[]
        int m = queries.length;
        int[] answer = new int[m];

        for(int i = 0; i < m; i++) {
            // Adding ith query means adding road
            adj.get(queries[i][0]).add(queries[i][1]);

            answer[i] = bfs(n, adj);
        }

        return answer;
    }

    private int bfs(int n, ArrayList<ArrayList<Integer>> adj) {
        boolean[] visited = new boolean[n];

        Queue<Integer> queue = new LinkedList<>();
        queue.offer(0); // Here assuming src node as 0
        visited[0] = true; 

        int level = 0;
        while(!queue.isEmpty()) {
            // Using level-wise BFS
            int size = queue.size();

            while(size-- > 0) {
                Integer currentNode = queue.poll();
                
                // If node reaches last node than return it
                if(currentNode == n - 1) {
                    return level;
                }

                for(Integer adjacentNode: adj.get(currentNode)) {
                    if(!visited[adjacentNode]) {
                        visited[adjacentNode] = true;
                        queue.offer(adjacentNode);
                    }
                }
            }

            level++;
        }

        return -1;
    }
}


/*
 * Approach 2: Using Dijkstra's Algorithm
 * Purpose: Finds the shortest path in a weighted graph.
 * Technique: Utilizes a min-heap (priority queue) to explore nodes with the smallest known distances first.
 * 
 * Time Complexity: O(ElogV), where E is the number of edges and V is the number of vertices.
 * 
 * Pros:
 * Efficient for graphs with weighted edges.
 * Finds the shortest path with precision even when edges have different weights.
 * 
 * Cons:
 * Slightly more complex and may be overkill for unweighted graphs.
 */

 class Solution2 {
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        ArrayList<ArrayList<PairA>> adj = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        for(int i = 1; i < n; i++) {
            adj.get(i-1).add(new PairA(i, 1));
        }

        int m = queries.length;
        int[] answer = new int[m];
        for(int i = 0; i < m; i++) {
            adj.get(queries[i][0]).add(new PairA(queries[i][1], 1));

            answer[i] = dijkstra(n, adj);
        }

        return answer;
    }

    private int dijkstra(int n, ArrayList<ArrayList<PairA>> adj) {
        int[] minDistance = new int[n];
        Arrays.fill(minDistance, Integer.MAX_VALUE);

        Queue<PairB> pq = new PriorityQueue<>((PairB a, PairB b) -> a.distance - b.distance);
        pq.offer(new PairB(0, 0));
        minDistance[0] = 0;

        while(!pq.isEmpty()) {
            PairB p = pq.poll();
            int currentDistance = p.distance;
            int currentNode = p.node;

            if(currentNode == n - 1) {
                return minDistance[n - 1];
            }

            for(PairA adjacentPair: adj.get(currentNode)) {
                int adjacentNode = adjacentPair.node;
                int adjacentDistance = adjacentPair.distance;

                if(currentDistance + adjacentDistance < minDistance[adjacentNode]) {
                    minDistance[adjacentNode] = currentDistance + adjacentDistance;
                    pq.offer(new PairB(currentDistance + adjacentDistance, adjacentNode));
                }
            }
        }

        return minDistance[n-1];
    }
}

class PairA {
    int node;
    int distance;

    PairA(int node, int distance) {
        this.node = node;
        this.distance = distance;
    }
}

class PairB {
    int distance;
    int node;

    PairB(int distance, int node) {
        this.distance = distance;
        this.node = node;
    }
}