class Graph {
    unordered_map<int, vector<pair<int, int>>> adj;
    int vectices = 0;
public:
    Graph(int n, vector<vector<int>>& edges) {
        for(auto i: edges) adj[i[0]].push_back({i[1], i[2]});
        vectices = n;
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dist(vectices, INT_MAX);
        set<pair<int, int>> st;
        dist[node1] = 0;
        st.insert({0, node1});
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
        return dist[node2] == INT_MAX ? -1 : dist[node2];
    }
};
