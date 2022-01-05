#include<iostream>
#include<vector>
#include<algorithm>
// Striver Graph Series : Krushkal's Algorithm - Used to find MSP using Disjoint Set instead of Adjacency List
// TC - O(ElogV)

// creating Node structure {u, v, wt}
struct Node{
    int u;
    int v;
    int wt;
    
    Node(int first, int second, int weight){
        u = first;
        v = second;
        wt = weight;
    }
};

// Function to find parent of Node
int findParent(int u, std::vector<int> &parent){
    if(u == parent[u])
        return u;
    
    return parent[u] = findParent(parent[u], parent);
}

// unionNodes() -> to unite two nodes belonging to two different components
void unionNodes(int u, int v, std::vector<int> &parent, std::vector<int> &rank){
    u = findParent(u, parent);
    v = findParent(v, parent);

    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[v] < rank[u]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

// comp() to compare Nodes based on there wt
bool comp(Node a, Node b){
    return a.wt < b.wt;
}

void krushkal(int V, std::vector<Node> edges){
    // First sort the edges<Node> acc to asc order of its weight
    std::sort(edges.begin(), edges.end(), comp);

    std::vector<int> rank(V, 0);
    std::vector<int> parent(V);
    for (int i = 0; i < V; i++){
        parent[i] = i;
    }

    int cost = 0;
    std::vector<std::pair<int, int>> mst;

    for (auto it : edges){
        // Checking if both (u,v) belongs to two different component(i.e., Not making cycle in mst)
        if(findParent(it.u, parent) != findParent(it.v, parent)){
            cost += it.wt;
            mst.push_back({it.u, it.v});    // Considering edge u->v into mst
            unionNodes(it.u, it.v, parent, rank);   // Making parent u/v of v/u & increasing rank of parent if rank is same
        }
    }
    
    std::cout << cost << "\n";
    for (auto it : mst){
        std::cout << it.first << " - " << it.second << "\n";
    }
}

int main(){
    int N, M;
    std::cin >> N >> M;
    // Storing edges in linear DS
    std::vector<Node> edges;
    for (int i = 0; i < M; i++){
        int u, v, wt;
        std::cin >> u >> v >> wt;
        edges.push_back(Node(u, v, wt));
    }
    
    krushkal(N, edges);

    return 0;
}