## Bellman Ford Algorithm 🚀
- It is used to calculate the shortest paths from a single source vertex to all vertices in the graph.
- This algorithm also works on graphs with a negative edge weight cycle (It is a cycle of edges with weights that sums to a negative number), unlike Dijkstra which gives wrong answers for the shortest path between two vertices.
- Time Complexity - O(VE)
- Space Complexity - O(V)
<br>

| Bellman Ford | Dijkstra's |
|--------------|------------|
|Its implementation is inspired by the dynamic programming approach. It follows the bottom - up approach.|Its implementation is inspired by the greedy approach.|
|It is easier to implement in a distributive way.|It is quite complex to implement in a distributed way.|
|It also works when the given graph contains a negative edge weight cycle.|It fails if a graph contains a negative edge weight cycle.|
|It's is more time consuming than Dijkstra's. It's Time complexity is O(VE).|It's Time complexity is O(ELogV), where V = number of vertices and E = number of edges.|
<br>

```cpp
class Solution{
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src){
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        for(int i = 0; i < V - 1; ++i){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // Nth relaxation to check negative cycle
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
                return {-1};
            }
        }
        return dist;
    }
};
```
