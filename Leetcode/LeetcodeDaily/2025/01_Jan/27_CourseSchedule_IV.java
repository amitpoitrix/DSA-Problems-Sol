/**
 * 1462. Course Schedule IV
 * Link: https://leetcode.com/problems/course-schedule-iv/description/?envType=daily-question&envId=2025-01-27
 * 
 * 
 * Approach 1: Using DFS
 * The idea is to treat the problem as a graph traversal task. 
 * For each query, perform a depth-first search (DFS) starting from the source node to check if the destination 
 * node is reachable. 
 * The adjacency list represents the graph, and a visited array ensures nodes are not revisited during the traversal. 
 * This approach is straightforward but can be repetitive since we traverse the graph separately for each query.
 * 
 * 
 * Complexity:
 * Time: O((V + E) * Q), where O(V + E) for building the graph, O(Q * (V + E)) for processing all queries.
 * Space: O((V + E) * (Q * V)), where Adjacency list: O(V + E), Visited array for each query: O(Q * V), Answer list: O(Q)
 */

class Solution1 {
    public List<Boolean> checkIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
        // Approach 1: Apply DFS at each query to check whether we reach dest from src

        // Step 1: Forming graph using Adjacency List
        List<List<Integer>> adj = new ArrayList<>();

        for(int i = 0; i < numCourses; i++) {
            adj.add(new ArrayList<>());
        }

        for(int i = 0; i < prerequisites.length; i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            // u -> v
            adj.get(u).add(v);
        }

        // Step 2: Applying DFS for each query
        List<Boolean> answer = new ArrayList<>();

        for(int i = 0; i < queries.length; i++) {
            int src = queries[i][0];
            int dest = queries[i][1];

            // We've to create visited[] for each query as we're applying DFS for each query
            boolean[] visited = new boolean[numCourses];

            boolean isReachable = dfs(src, dest, adj, visited);

            answer.add(isReachable);
        }

        return answer;
    }

    private boolean dfs(int src, int dest, List<List<Integer>> adj, boolean[] visited) {
        if(src == dest) {
            return true;
        }

        visited[src] = true;

        for(Integer adjacent: adj.get(src)) {
            if(!visited[adjacent]) {
                if(dfs(adjacent, dest, adj, visited) == true) {
                    return true;
                }
            }
        }

        return false;
    }
}


/**
 * Approach 2: Using Kahn's Algorithm (Topological Sort)
 * This approach uses topological sorting to process nodes in dependency order. 
 * While processing, maintain a mapping of each node to its prerequisites by aggregating the prerequisites of 
 * its predecessors. 
 * After building this mapping, answering queries becomes a simple lookup. 
 * This approach efficiently combines graph traversal and dependency aggregation, making it well-suited for 
 * large graphs with many queries.
 * 
 * 
 * Complexity:
 * Time: O(V + E + Q), where Graph building: O(E), Topological sorting: O(V + E), Prerequisite set population: O(E), 
 * Query processing: O(Q)
 * Space: O(V^2), where Adjacency list: O(V + E), Indegree array: O(V), Map: O(V^2), Queue: O(V), Answer list: O(Q)
 */

class Solution2 {
    public List<Boolean> checkIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
        // Approach 2: Find Toposort and than check for each query

        // Step 1: Find Topological Sort using BFS(Kahn's Algorithm)
        // Step 2: Find the answer for each query by storing each nodes prerequisites in Map of <node, set>

        List<List<Integer>> adj = new ArrayList<>();

        for(int i = 0; i < numCourses; i++) {
            adj.add(new ArrayList<>());
        }

        int[] indegree = new int[numCourses];

        for(int i = 0; i < prerequisites.length; i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            // u -> v
            adj.get(u).add(v);
            indegree[v]++;
        }

        // Now Applying BFS to find Toposort
        Queue<Integer> queue = new LinkedList<>();

        // Adding starting elements on queue whose indegree is 0
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                queue.offer(i);
            }
        }

        List<Integer> topoSort = new ArrayList<>();

        // Inorder to efficiently find whether currentNode prerequisites is there in its mapping Set
        Map<Integer, Set<Integer>> map = new HashMap<>();

        while(!queue.isEmpty()) {
            Integer currentNode = queue.poll();

            topoSort.add(currentNode);

            for(Integer adjacent: adj.get(currentNode)) {
                // Now we're adding prerequisite nodes for adjacent node which is currentNode
                map.putIfAbsent(adjacent, new HashSet<>());
                map.get(adjacent).add(currentNode);

                // There might be prerequisites nodes for currentNodes also so adding those in adjacent's prerequisites
                if(map.containsKey(currentNode)) {
                    for(Integer setNodes: map.get(currentNode)) {
                        map.get(adjacent).add(setNodes);
                    }
                }

                indegree[adjacent]--;

                if(indegree[adjacent] == 0) {
                    queue.offer(adjacent);
                }
            }
        }

        // Now traverse over each query and check
        List<Boolean> answer = new ArrayList<>();

        for(int i = 0; i < queries.length; i++) {
            int firstCourse = queries[i][0];
            int secondCourse = queries[i][1];

            // There might be possibility that node doesn't exist in map like those nodes whose indegree is 0
            if(map.containsKey(secondCourse) && map.get(secondCourse).contains(firstCourse)) {
                answer.add(true);
            } else {
                answer.add(false);
            }
        }

        return answer;
    }   
}