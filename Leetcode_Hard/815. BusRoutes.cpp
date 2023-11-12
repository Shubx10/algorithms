class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        int n = routes.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; ++i){
            for(int j: routes[i]){
                mp[j].push_back(i);
            }
        }
        vector<bool> busNo(n);
        queue<int> q;
        q.push(source);
        int bus = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int stop = q.front();
                q.pop();
                if(stop == target) return bus;
                for(int i: mp[stop]){
                    if(!busNo[i]){
                        busNo[i] = 1;
                        for(int j: routes[i]){
                            q.push(j);
                        }
                    }
                }
            }
            bus++;
        }
        return -1;
    }
};
