/*
 * 2924. Find Champion II
 * Link: https://leetcode.com/problems/find-champion-ii/description/?envType=daily-question&envId=2024-11-26
 * 
 * 
 * The goal of this approach is to identify the "champion" node in a directed graph, defined as a node with no
 * incoming edges (indegree = 0). Here's how it works:
 * 
 * Indegree Calculation:
 * Initialize an array indegree to track the number of incoming edges for each node.
 * For each edge in the graph (u to v), increment the indegree of the destination node v.
 * 
 * Champion Identification:
 * Traverse through all nodes and identify those with indegree = 0.
 * If exactly one node has indegree = 0, it is the champion.
 * If more than one node has indegree = 0, return -1, as there is no unique champion.
 * 
 * Edge Cases:
 * If no node has indegree = 0, return -1 (no champion exists).
 */

class Solution {
    public int findChampion(int n, int[][] edges) {
        int[] inDegree = new int[n];

        for(int i = 0; i < edges.length; i++) {
            inDegree[edges[i][1]]++;
        }

        int champion = -1;
        int countChampion = 0;
        for(int i = 0; i < n; i++) {
            if(inDegree[i] == 0) {
                champion = i;
                countChampion++;
            }
        }

        return countChampion == 1 ? champion: -1;
    }
}