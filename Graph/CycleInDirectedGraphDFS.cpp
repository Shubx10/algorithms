bool checkCycleDFS(int node, vector<bool> &visited, vector<bool> &dfsvisited, vector<vector<int>> &adj){
    visited[node] = true;
    dfsvisited[node] = true;
    
    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            bool cycledetected = checkCycleDFS(neighbour, visited, dfsvisited, adj);
            if(cycledetected){
                return true;
            }
        }
        else if(dfsvisited[neighbour]){
            return true;
        }
    }
    dfsvisited[node] = false;
    return false;
}

bool detectCycleInDirectedGraph(int vertex, vector<pair<int, int>> &edges){
    vector<vector<int>> adj(vertex);
    vector<bool> visited(vertex);
    vector<bool> dfsvisited(vertex);

    for(int i = 0; i < edges.size(); ++i){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }
    
    for(int i = 0; i < vertex; ++i){
        if(!visited[i]){
            bool cyclefound = checkCycleDFS(i, visited, dfsvisited, adj);
            if(cyclefound){
                return true;
            }
        }
    }
    return false;
}
