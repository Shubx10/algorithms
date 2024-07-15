/*
  -- Kruskal's algorithm is used to find the Minimum Spanning Tree of a connected, undirected graph
  -- Implemented using Disjoint Set (Union-Find) data structure
  -- {TC, (ElogE)} {SC, (E + V)}
  -- Kruskal works well with edge lists while Prim works well with adjacency matrices or adjacency lists
  -- Kruskal is generally more efficient for sparse graphs(graphs with fewer edges) whereas Prim is more efficient for dense graphs(graphs with many edges)
*/
class DisjointSet {
    vector<int> parent, size; 
public: 
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n); 
        for(int i = 0; i < n; ++i){
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]); 
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};
class Solution {
public:
	  //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<pair<int, pair<int, int>>> edges;
        for(int i = 0; i < V; ++i){
            for(auto& it: adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                edges.push_back({wt, {node, adjNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstWeight = 0;
        for(auto& it: edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(ds.findUPar(u) != ds.findUPar(v)){
                mstWeight += wt;
                ds.unionBySize(u, v);
            }
        }
        return mstWeight;
    }
};
