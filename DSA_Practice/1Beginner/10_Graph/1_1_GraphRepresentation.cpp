#include<iostream>
#include<vector>
// Striver graph series - Graph Representation

// 1. Using Adjacency Matrix - Not suitable for larger no. of nodes 
// int main(){
//     int n, m;   // n -> No. of Node/Vertex & m -> No. of Edges
//     std::cin >> n >> m;

//     // declare Adjacent Matrix
//     int adj[n+1][n+1];  // If its 1 based indexing

//     // Traversing till no. of edges
//     for (int i = 0; i < m; i++){
//         int u, v;
//         std::cin >> u >> v;
//         adj[u][v] = 1;
//         adj[v][u] = 1;  // this will comment out in case of directed graph
//     }
     
//     return 0;
// }

// 2. Using Adjacency List - Unweighted Undirected Graph
// int main(){
//     int n, m;   // n -> No. of Node/Vertex & m -> No. of Edges
//     std::cin >> n >> m;

//     // declare Adjacent List
//     std::vector<int> adj[n+1];  // If its 1 based indexing

//     // Traversing till no. of edges
//     for (int i = 0; i < m; i++){
//         int u, v;
//         std::cin >> u >> v;

//         adj[u].push_back(v);
//         adj[v].push_back(u);  // this will comment out in case of directed graph
//     }
     
//     return 0;
// }


// 3. Using Adjacency List - Weighted Undirected Graph
// int main(){
//     int n, m;   // n -> No. of Node/Vertex & m -> No. of Edges
//     std::cin >> n >> m;

//     // declare Adjacent List
//     std::vector<std::pair<int, int>> adj[n+1];  // If its 1 based indexing

//     // Traversing till no. of edges
//     for (int i = 0; i < m; i++){
//         int u, v, wt;
//         std::cin >> u >> v >> wt;

//         adj[u].push_back({v, wt});
//         adj[v].push_back({u, wt});  // this will comment out in case of directed graph
//     }
     
//     return 0;
//}

// From GFG
// 2. Using Adjacency List - Unweighted Undirected Graph
// Adding Edge for Undirected Graph
void addEdge(std::vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//Display Adjacency List (i.e, Graph)
void printGraph(std::vector<int> adj[], int V){
    for (int i = 0; i < V; i++){
        std::cout << "Adjacency List of Vertex " << i << "\n head";
        for (auto x : adj[i]){
            std::cout << "->"<< x;
        }
        std::cout<<"\n";
    }
}

int main(){
    int V = 5;
    std::vector<int> adj[V];    // 0 based indexing of Graph i.e., vertices from 0 to 4
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    // addEdge(adj, 1, 0);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    // addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    // addEdge(adj, 3, 1);
    // addEdge(adj, 3, 2);
    addEdge(adj, 3, 4);
    // addEdge(adj, 4, 0);
    // addEdge(adj, 4, 3);
    // addEdge(adj, 4, 1);

    printGraph(adj, V);

    return 0;
}