#include<iostream>
// Striver Graph Series - Disjoint Set(DS used in Krushkal Algorithm) Using Union Rank & Path Compression
// Disjoint Set is used to join different components of Graph into 1 single component
// It has 2 functions - (i) findParent(), (ii) union()
// TC - O(4 alpha) ~ O(4) - Mathematically Proven

// Making parent[] & rank[] as global variable
int parent[100000];
int rank[100000];

// Initially making parent node of each element as itself & rank as 0
void makeSet(int n){
    for (int i = 1; i <= n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int node){
    if(node == parent[node])
        return node;

    // Path Compression - 7->6->2 as here 7 has parent 2 so instead of going through 6 again & again in order to get parent of 7 we do 
    // PC so every time we need parent of 7 we can directly get it as 2 (i.e., 7->2 after path compression)
    return parent[node] = findParent(parent[node]);
}

void unionFunc(int u, int v){
    u = findParent(u);
    v = findParent(v);

    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[v] < rank[u]){
        parent[v] = u;
    }
    else{
        // As both u & v are equal so making anyone as parent of another
        parent[v] = u;  // Making u as parent of v
        rank[u]++;  // Increasing the rank of parent node i.e., u by 1
    }
}

int main(){
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