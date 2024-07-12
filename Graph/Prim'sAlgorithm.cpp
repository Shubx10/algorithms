/*
  --Prim's algorithm is a classic greedy algorithm used to find the minimum spanning tree (MST) of a connected, undirected graph
  --Spanning tree - Having V vertices and (V - 1) edges
  --A spanning tree does not have any cycle
  --MST - A minimum spanning tree is defined as a spanning tree that has the minimum weight among all the possible spanning trees
  --{TC, ((V + E)log V)} {SC, (V + E)}
*/
class Solution{
public:
  int spanningTree(int V, vector<vector<int>> adj[]){
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      vector<int> vis(V);
      pq.push({0, 0});
      int minWeight = 0;
      while(!pq.empty()){
          int node = pq.top().second;
          int wt = pq.top().first;
          pq.pop();
          if(vis[node]){
              continue;
          }
          vis[node] = 1;
          minWeight += wt;
          for(auto& it: adj[node]){
              int adjNode = it[0];
              int adjWt = it[1];
              if(!vis[adjNode]){
                  pq.push({adjWt, adjNode});
              }
          }
      }
      return minWeight;
  }
};
