// Kahn's Algorithm
vector<int> topologicalSort(vector<vector<int>> &edges, int v){
    vector<int> adj[v];
    vector<int> indegree(v);
    queue<int> q;
    vector<int> ans;

    for(int i = 0; i < edges.size(); ++i){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    for(int i = 0; i < v; ++i){
        for(auto j: adj[i]){
            indegree[j]++;
        }
    }

    for(int i = 0; i < v; ++i){
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
