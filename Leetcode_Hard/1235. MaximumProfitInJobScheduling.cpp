class Solution {
public:
    int nextInd(vector<vector<int>>& jobs, int ind){
        int endtime = jobs[ind][1];
        int low = ind, high = jobs.size() - 1;
        int ans = high + 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(jobs[mid][0] >= endtime){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
    int recur(vector<vector<int>>& jobs, int ind, vector<int>& dp){
        if(ind >= jobs.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
        int excl = recur(jobs, ind + 1, dp);
        int incl = jobs[ind][2] + recur(jobs, nextInd(jobs, ind), dp);
        return dp[ind] = max(incl, excl);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> jobs;
        for(int i = 0; i < n; ++i) jobs.push_back({startTime[i], endTime[i], profit[i]});
        sort(jobs.begin(), jobs.end());
        vector<int> dp(n + 1, -1);
        return recur(jobs, 0, dp);
    }
};
