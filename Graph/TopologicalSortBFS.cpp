// Kahn's Algorithm
vector<int> topologicalSort(int vertex, vector<vector<int>> &edges){
    vector<vector<int>> adj(vertex);
    vector<int> indegree(vertex);
    queue<int> q;
    vector<int> ans;

    for(int i = 0; i < edges.size(); ++i){
        int u = edges[i][0];
        int v = edges[i][1];
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

    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(auto neighbour: adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    return ans;
}
