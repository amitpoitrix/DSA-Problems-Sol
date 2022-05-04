#include<iostream>
// Striver Graph Series - Disjoint Set(DS used in Krushkal Algorithm) Using Union Rank & Path Compression
// Disjoint Set is used to join different components of Graph into single component
// It has 2 functions:
// (i) findParent(): This function will return the parent node of current node being passed as parameter  
// (ii) union(): It combines two components of graph into single component having single same parent for whole element
// TC - O(4 alpha) ~ O(4) - Mathematically Proven

// Disjoint Set:
// 1. This Data Structure is generally useful when we are given two nodes & we want to find whether they belongs to same 
// component or not
// 2. We assume all the vertices to be in different component initially(i.e., all are parents of themselves)
// 3. If there is an eddge between two nodes then we combined them in a single component by making one of them as parent of 
// both this is called as Union operation of two nodes

// "Path Compression" is used to implement it efficiently
// Also we connect less rank node to the node with higher rank to reduce the height of tree.
// "Union by Rank": If rank is same, then connect any node to other, also increment the rank of the node to which other node
// is connected(i.e., Parent Node) as height of tree will be increased by 1.

// If parent of u & v are same than they belongs to same component


// Making parent[] & rank[] as global array variable
int parent[100000];
int rank[100000];

// Initially making parent node of each element as itself & rank as 0 & starting traversing nodes from 1 instead of 0
void makeSet(int n){
    for (int i = 1; i <= n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int node){
    if(node == parent[node])
        return node;

    // Path Compression - 7->6->2 as here 7 has parent 2 so instead of going through 6 again & again in order to get parent 
    // of 7 we do PC so every time we need parent of 7 we can directly get it as 2 (i.e., 7->2 after path compression)
    return parent[node] = findParent(parent[node]);
}

void unionFunc(int u, int v){
    u = findParent(u);
    v = findParent(v);

    // The node having higher rank will be the parent node of other smaller rank node
    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[v] < rank[u]){
        parent[v] = u;
    }
    else{
        // As rank of both u & v are equal so making anyone as parent of another
        parent[v] = u;  // Making u as parent of v
        rank[u]++;  // Increasing the rank of parent node i.e., u by 1
    }
}

int main(){
    // Here n is no. of nodes & m is no. of edge
    int n, m;
    std::cin >> n >> m;

    makeSet(n);

    while (m--){
        int u, v;
        std::cin >> u >> v;
        unionFunc(u, v);
    }
    
    // If 7 & 3 belong to same component or not
    // We'll make use of findParent() instead of parent[] as later one will give wrong ans
    if(findParent(7) != findParent(3))
        std::cout << "Different Component";
    else
        std::cout << "Same component";

    return 0;
}