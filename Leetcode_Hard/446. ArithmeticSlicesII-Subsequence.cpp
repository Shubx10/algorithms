class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        int res = 0;
        vector<unordered_map<int, int>> dp(n);
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                int cnt = 0;
                long long diff = (long long)nums[i] - (long long)nums[j];
                if(diff > INT_MAX || diff < INT_MIN) continue;
                if(dp[j].find(diff) != dp[j].end()){
                    cnt = dp[j][diff];
                }
                dp[i][diff] += cnt + 1;
                res += cnt;
            }
        }
        return res;
    }
};
