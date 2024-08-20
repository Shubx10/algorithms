class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<P, vector<P>, greater<P>> pq;
        int maxi = INT_MIN;
        for(int i = 0; i < n; ++i){
            pq.push({nums[i][0], {i, 0}});
            maxi = max(maxi, nums[i][0]);
        }
        int start, end, range = 1e9;
        while(!pq.empty()){
            int mini = pq.top().first;
            int listNo = pq.top().second.first;
            int listIndex = pq.top().second.second;
            pq.pop();
            if(range > maxi - mini){
                start = mini;
                end = maxi;
                range = maxi - mini;
            }
            if(listIndex >= nums[listNo].size()) break;
            pq.push({nums[listNo][listIndex], {listNo, listIndex + 1}});
            maxi = max(maxi, nums[listNo][listIndex]);
        }
        return {start, end};
    }
};
