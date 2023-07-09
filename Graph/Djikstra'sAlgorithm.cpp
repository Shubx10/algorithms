vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int source){
    vector<vector<pair<int, int>>> adj(vertices);
    for(int i = 0; i < vec.size(); ++i){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(vertices, INT_MAX);
    set<pair<int, int>> st;
    dist[source] = 0;
    st.insert({0, source});

    while(!st.empty()){
        auto top = *(st.begin());
        int nodeDist = top.first;
        int nodeVal = top.second;
        st.erase(st.begin());
        for(auto neighbour: adj[nodeVal]){
            if(nodeDist + neighbour.second < dist[neighbour.first]){
                if(dist[neighbour.first] != INT_MAX){
                    st.erase({dist[neighbour.first], neighbour.first});
                }
                dist[neighbour.first] = nodeDist + neighbour.second;
                st.insert({dist[neighbour.first], neighbour.first});
            }
        }
    }
    return dist;
}
