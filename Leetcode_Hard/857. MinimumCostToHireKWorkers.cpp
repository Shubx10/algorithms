class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = wage.size();
        vector<pair<double, int>> ratio;
        for(int i = 0; i < n; ++i){
            ratio.push_back({wage[i] / (double)quality[i], quality[i]});
        }
        sort(ratio.begin(), ratio.end());
        double cost = INT_MAX;
        priority_queue<int> pq;
        double total_quality = 0;
        for(int i = 0; i < n; ++i){
            pq.push(ratio[i].second);
            total_quality += ratio[i].second;
            if(pq.size() > k){
                total_quality -= pq.top();
                pq.pop();
            }
            if(pq.size() == k){
                cost = min(cost, total_quality * ratio[i].first);
            }
        }
        return cost;
    }
};
