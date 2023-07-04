void preparedAdjList(unordered_map<int, vector<int>> &adjList, vector<pair<int, int>> &edges){
    for(int i = 0; i < edges.size(); ++i){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

bool iscyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, vector<int>> adjList){
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = 1;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(auto neighbour: adjList[front]){
            if(visited[neighbour] == true && neighbour != parent[front]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

bool iscyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, vector<int>> &adjList){
    visited[node] = true;
    for(auto neighbour: adjList[node]){
        if(!visited[neighbour]){
            bool cycledetected = iscyclicDFS(neighbour, node, visited, adjList);
            if(cycledetected){
                return true;
            }
        }
        else if(neighbour != parent){
            return true;
        }
    }
    return false;
}

bool cycleDetection(int vertex, vector<pair<int, int>>& edges){
    unordered_map<int, vector<int>> adjList;
    unordered_map<int, bool> visited;

    preparedAdjList(adjList, edges);
    for(int i = 0; i < vertex; ++i){
        if(!visited[i]){
            // bool ans = iscyclicBFS(i, visited, adjList);
            bool ans = iscyclicDFS(i, -1, visited, adjList);
            if(ans){
                return true;
            }      
        }
    }
    return false;
}
