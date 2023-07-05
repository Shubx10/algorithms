void topoSort(int node, vector<bool> &visited, stack<int> &s, vector<vector<int>> &adj){
    visited[node] = 1;
    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            topoSort(neighbour, visited, s, adj);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(int vertex, vector<vector<int>> &edges){
    vector<vector<int>> adj(vertex);
    vector<bool> visited(vertex);
    stack<int> s;

    for(int i = 0; i < edges.size(); ++i){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    for(int i = 0; i < vertex; ++i){
        if(!visited[i]){
            topoSort(i, visited, s, adj);
        }
    }

    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}
