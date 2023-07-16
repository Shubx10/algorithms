void prepareAdjList(unordered_map<int, vector<int>> &adjList, vector<pair<int, int>> &edges){
    for(int i = 0; i < edges.size(); ++i){
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void dfs(unordered_map<int, vector<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node){
    visited[node] = 1;
    ans.push_back(node);

    for(auto i: adjList[node]){
        if(!visited[i]){
            dfs(adjList, visited, ans, i);
        }
    }
}

vector<int> DFS(int vertex, vector<pair<int, int>> edges){
    unordered_map<int, vector<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;
    
    prepareAdjList(adjList, edges);
    for(int i = 0; i < vertex; ++i){
        if(!visited[i]){
            dfs(adjList, visited, ans, i); 
        }
    }
   return ans; 
}
