// DAG - Directed Acyclic Graph (weighted)
class Solution {
public:
    void topoSort(int node, vector<vector<pair<int, int>>> adj, vector<bool> &vis, stack<int> &st){ 
        vis[node] = 1;
        for (auto it: adj[node]) {
            int v = it.first;
            if (!vis[v]) {
                topoSort(v, adj, vis, st);
            }
        }
        st.push(node);
    }
    
    vector<int> shortestPath(int N, vector<vector<int>>& edges){
        vector<vector<pair<int, int>>> adj(N);
        for(int i = 0; i < edges.size(); ++i){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt}); 
        }

        vector<bool> vis(N);
        stack<int> st;
        vector<int> dist(N, 1e9);

        for(int i = 0; i < N; ++i){
            if(!vis[i]){
                topoSort(i, adj, vis, st);
            }
        }

        dist[0] = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
        
            for (auto it: adj[node]) {
                int v = it.first;
                int wt = it.second;
            
                if (dist[v] > dist[node] + wt){
                    dist[v] = wt + dist[node];
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};
