class Solution {
public:
    // int memo(int i, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp){
    //     if(i == prices.size() || cap == 0) return 0;
    //     if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
    //     if(buy){
    //         return dp[i][buy][cap] = max(-prices[i] + memo(i + 1, 0, cap, prices, dp), memo(i + 1, 1, cap, prices, dp));
    //     }
    //     return dp[i][buy][cap] = max(prices[i] + memo(i + 1, 1, cap - 1, prices, dp), memo(i + 1, 0, cap, prices, dp));
    // }
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        // return memo(0, 1, 2, prices, dp);

        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        // for(int i = n - 1; i >= 0; --i){
        //     for(int buy = 0; buy <= 1; ++buy){
        //         for(int cap = 1; cap <= 2; ++cap){
        //             if(buy){
        //                 dp[i][buy][cap] = max(-prices[i] + dp[i + 1][0][cap], dp[i + 1][1][cap]);
        //             }else{
        //                 dp[i][buy][cap] = max(prices[i] + dp[i + 1][1][cap - 1], dp[i + 1][0][cap]);
        //             }
        //         }
        //     }
        // }
        // return dp[0][1][2];

        if(prices.size() == 0) return 0;
        int buy1 = INT_MAX, buy2 = INT_MAX;
        int profit1 = INT_MIN, profit2 = INT_MIN;
        for(int i = 0; i < prices.size(); i++){
            buy1 = min(buy1, prices[i]);
            profit1 = max(profit1, prices[i] - buy1);
            buy2 = min(buy2, prices[i] - profit1);
            profit2 = max(profit2, prices[i] - buy2);
        }
        return profit2;
    }
};
