bool detectCycleInDirectedGraph(int vertex, vector<pair<int, int>> &edges){
    vector<vector<int>> adj(vertex);
    vector<int> indegree(vertex);
    queue<int> q;

    for(int i = 0; i < edges.size(); ++i){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }

    for(int i = 0; i < vertex; ++i){
        for(auto j: adj[i]){
            indegree[j]++;
        }
    }

    for(int i = 0; i < vertex; ++i){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    int cnt = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        cnt++;

        for(auto neighbour: adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    if(cnt == vertex) return false;
    return true;
}
