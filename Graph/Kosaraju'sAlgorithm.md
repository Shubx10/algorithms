## Kosaraju's Algorithm 🚀
- strongly connected component (SCC) - In a directed graph a strongly connected component is a component of the graph in which there is a path between every pair of vertices.
- Kosaraju algorithm is used to find the number of strongly component in a directed graph using DFS on the graph.
- Time Complexity - O($V + E$)
- Space Complexity - O($V$)
<br>

```cpp
class Solution{
  public:
  void dfs(int node, vector<bool> &vis, stack<int> &st, vector<vector<int>> &adj){
      vis[node] = 1;
      for(auto it: adj[node]){
          if(!vis[it]){
              dfs(it, vis, st, adj);
          }
      }
      st.push(node);
  }
  void dfs2(int node, vector<bool> &vis, vector<vector<int>> &adjT){
      vis[node] = 1;
      for(auto it: adjT[node]){
          if(!vis[it]){
              dfs2(it, vis, adjT);
          }
      }
  }
  int kosaraju(int V, vector<vector<int>>& adj){
      vector<bool> vis(V);
      stack<int> st;
      for(int i = 0; i < V; ++i){
          if(!vis[i]){
              dfs(i, vis, st, adj);
          }
      }
      vector<vector<int>> adjT(V);
      for(int i = 0; i < V; ++i){
          vis[i] = 0;
          for(auto it: adj[i]){
              adjT[it].push_back(i);
          }
      }
      int scc = 0;
      while(!st.empty()){
          int node = st.top();
          st.pop();
          if(!vis[node]){
              scc++;
              dfs2(node, vis, adjT);
          }
      }
      return scc;
  }
};
```
