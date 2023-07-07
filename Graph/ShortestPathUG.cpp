// UG - Undirected Graph
// You are given an Undirected Graph having unit weight
// Find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src){
        vector<vector<int>> adj(N);
        for(auto i: edges){
            int u = i[0];
            int v = i[1];
            adj[i[0]].push_back(v);
            adj[i[1]].push_back(u);
        }
        
        vector<int> vis(N);
        vector<int> dist(N, -1);
        queue<int> q;
        
        vis[src] = 1;
        dist[src] = 0;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i: adj[node]){
                if(!vis[i]){
                    dist[i] = dist[node] + 1;
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
        return dist;
    }
};
