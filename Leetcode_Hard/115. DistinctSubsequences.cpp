class Solution {
public:
    // int memo(int i, int j, string s, string t, vector<vector<int>>& dp){
    //     if(j < 0) return 1;
    //     if(i < 0) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(s[i] == t[j]){
    //         return dp[i][j] = memo(i - 1, j - 1, s, t, dp) + memo(i - 1, j, s, t, dp);
    //     }
    //     return dp[i][j] = memo(i - 1, j, s, t, dp);
    // }
    int numDistinct(string s, string t) {
        // int n = s.size(), m = t.size();
        // vector<vector<int>> dp(n, vector<int> (m, -1));
        // return memo(n - 1, m - 1, s, t, dp);

        int n = s.size(), m = t.size(), mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int> (m + 1));
        for(int i = 0; i < n + 1; ++i) dp[i][0] = 1;
        for(int i = 1; i < n + 1; ++i){
            for(int j = 1; j < m + 1; ++j){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
                }else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};
