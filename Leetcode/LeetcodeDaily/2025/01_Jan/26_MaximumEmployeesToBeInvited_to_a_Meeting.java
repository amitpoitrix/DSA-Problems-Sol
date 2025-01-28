/**
 * 2127. Maximum Employees to Be Invited to a Meeting
 * Link: https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/description/?envType=daily-question&envId=2025-01-26
 * 
 * 
 * Approach:
 * 
 * Observation 1: When there are couple nodes than ask length from nodes from both couple nodes and while finding 
 * length of nodes just reverse the direction for traversal
 * https://github.com/user-attachments/assets/1b9cb388-915f-493f-a4f4-514f9199c328
 * 
 * Observation 2: When there is cycle than all nodes which are part of that cycle can sit in round tables
 * https://github.com/user-attachments/assets/f6017f7c-df4d-4fdd-9a4f-694846c89ec9
 * 
 * Observation 3: Can we've different separate components as well - And will consider the one having max no. of nodes
 * in cycle as we can't add all the cyclic nodes
 * https://github.com/user-attachments/assets/756d36d6-f001-4625-896f-d30f7e82e0f9
 * 
 * Observation 4: When we've semi-cycle (couple nodes) components + Full cycle components than semi one can merge 
 * with each other
 * https://github.com/user-attachments/assets/9ed1fcc7-38d5-4340-934b-f0a43fb2aa0b
 * 
 * Summary:
 * 1. There will always be cycle as ith person favorite is fav[i] which forms relation i ---> nums[i] so there 
 * will be one moment when there is cycle
 * 2. 2 types of cycle
 * https://github.com/user-attachments/assets/8a77a67e-30ad-41f8-bc7d-63152979f67d
 * 
 * 
 * Approach:
 * The problem revolves around finding cycles and paths in a directed graph where each node has exactly one 
 * outgoing edge. 
 * 
 * Here's the intuition behind the approach:
 * 
 * Reverse Graph Construction:
 * To calculate the maximum invitations, the graph is reversed. 
 * This helps in determining how far the influence of a cycle or a "happy couple" extends by considering incoming 
 * edges.
 * 
 * Cycle Detection:
 * Each node is visited to detect cycles. 
 * When a cycle is found, its length is calculated. 
 * The longest cycle length is tracked as one possible answer.
 * 
 * Special Case - Happy Couples:
 * If a cycle of length 2 is detected (mutual favorites), it represents a "happy couple." 
 * For such cases, the paths extending from each of the two nodes in the cycle are calculated using BFS. 
 * The total invitations include the couple and the nodes influenced by them.
 * 
 * Result Computation:
 * The final result is the maximum of:
 * 1. The longest cycle length.
 * 2. The total invitations from all "happy couple" scenarios.
 * 
 * 
 * Complexity:
 * Time: O(V); since each node is traverse atmost once during creation of adjacency list, detecting cycle in graph 
 * using bfs and during finding max nodes length using BFS
 * Space: O(V)
 */ 

class Solution {
    public int maximumInvitations(int[] favorite) {
        // Approach: Its a graph question because 0 to n-1 employees are given with relation like ith favorite is 
        // favorite[i] i.e., i --> favorite[i]

        // Step 1: Now we need to make employee sit so that there will be max no. of employee in the round table 
        // so for that we need to form graph first using favorite[] but direction should be in reverse order 
        // (i.e., favorite[i] --> i) in order to apply graph traversal algo 
        int V = favorite.length;

        List<List<Integer>> adj = new ArrayList<>();

        for(int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        // Now we'll connect the nodes but in reverse order (favorite[i] --> i)
        for(int i = 0; i < V; i++) {
            int u = favorite[i];
            int v = i;

            adj.get(u).add(v);
        }

        // Step 2: There will always be cycle so if there is only cycles in components of graph than the component
        // having max nodes in cycle will be consider as more than one cycle can't exist in round table

        // Step 3: And if cycle length is 2 than these are Happy Couple in which all the happy couple component 
        // will take part in round table and traversal from both nodes till max length will contribute to overall 
        // length of nodes (in that particular component) needed to be sitted in table.

        boolean[] visited = new boolean[V]; // Global visited[] 

        int maxLengthOfCycle = 0;
        int totalHappyCouplesNodesLength = 0;

        // Now going through each and every component of graphs
        for(int i = 0; i < V; i++) {
            // only when is non-visited
            if(!visited[i]) {
                // Now at each component we need to find no. of nodes in cyclic graph
                int currentNode = i;
                int currentNodeCount = 0;

                // As we need to store {node, count of nodes so far} so we'll use HashMap
                Map<Integer, Integer> nodeMap = new HashMap<>();

                // Running while loop till we encounter currentNode (i.e., i) again
                while(!visited[currentNode]) {
                    visited[currentNode] = true;

                    // Storing current node so far corresponding to currentNode
                    nodeMap.put(currentNode, currentNodeCount);

                    // Next node will be given by currentNode favorite i.e., favorite[currentNode]
                    int nextNode = favorite[currentNode];
                    currentNodeCount++;

                    // Now we'll check if nextNode is already visited or not in map
                    if(nodeMap.containsKey(nextNode)) {
                        // means nextNode is already visited as its there in map, so we'll find the cycle length
                        int cycleLength = currentNodeCount - nodeMap.get(nextNode);

                        // Tracking max no. of nodes in cycle
                        maxLengthOfCycle = Math.max(maxLengthOfCycle, cycleLength);

                        // if its a Happy Couple than add its length to totalHappyCouplesNodesLength
                        if(cycleLength == 2) {
                            boolean[] happyCoupleVisited = new boolean[V];
                            happyCoupleVisited[currentNode] = true;
                            happyCoupleVisited[nextNode] = true;

                            // Tracking total no. of nodes so far in components having Happy Couples
                            totalHappyCouplesNodesLength += 2 + bfs(currentNode, adj, happyCoupleVisited) + bfs(nextNode, adj, happyCoupleVisited);
                        }

                        // As we got the cycle & its length so coming out from while loop 
                        break;
                    } else {
                        // If cycle is not detected yet than make nextNode as currentNode to detect cycle further
                        currentNode = nextNode;
                    }
                }
            }
        }

        return Math.max(maxLengthOfCycle, totalHappyCouplesNodesLength);
    }
    
    // BFS() to find length from src to farthest node so far
    private int bfs(int src, List<List<Integer>> adj, boolean[] happyCoupleVisited) {
        // As we're using BFS so we need queue and elements should pair like {node <-> distance from src}
        Queue<Pair> queue = new LinkedList<>();
        queue.offer(new Pair(src, 0));

        int maxDistance = 0;

        while(!queue.isEmpty()) {
            Pair p = queue.poll();

            int currentNode = p.node;
            int currentDistance = p.distance;

            // Now we'll go tp adjacent nodes
            for(Integer adjacent: adj.get(currentNode)) {
                // if adjacent node is not yet visited
                if(!happyCoupleVisited[adjacent]) {
                    // marking adjacent node as visited
                    happyCoupleVisited[adjacent] = true;
                    
                    // keeping track of maxDistance from src
                    maxDistance = Math.max(maxDistance, currentDistance + 1);

                    // Adding back the new adjacent node
                    queue.offer(new Pair(adjacent, currentDistance + 1));
                }
            }
        }

        return maxDistance;
    }

    static class Pair {
        int node;
        int distance;

        Pair(int node, int distance) {
            this.node = node;
            this.distance = distance;
        }
    }
}