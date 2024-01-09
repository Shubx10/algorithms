class Solution {
public:
    // bool memo(int i, int j, string& s, string& p, vector<vector<int>>& dp){
    //     if(i == -1 && j == -1) return 1;
    //     if(j == -1 && i >= 0) return 0;
    //     if(i == -1 && j >= 0){
    //         for(int t = 0; t <= j; ++t){
    //             if(p[t] != '*') return 0;
    //         }
    //         return 1;
    //     }
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if((s[i] == p[j]) || (p[j] == '?')) return dp[i][j] = memo(i - 1, j - 1, s, p, dp);
    //     else if(p[j] == '*') return dp[i][j] = memo(i - 1, j, s, p, dp) || memo(i, j - 1, s, p, dp);
    //     return dp[i][j] = 0;
    // }
    bool isMatch(string s, string p) {
        // int n = s.size(), m = p.size();
        // vector<vector<int>> dp(n, vector<int> (m, -1));
        // return memo(n - 1, m - 1, s, p, dp);

        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1));
        dp[0][0] = 1;
        for(int j = 1; j < m + 1; ++j){
            bool flag = 1;
            for(int t = 1; t <= j; ++t){
                if(p[t - 1] != '*'){
                    flag = 0;
                    break;
                }
            }
            dp[0][j] = flag;
        }
        for(int i = 1; i < n + 1; ++i){
            for(int j = 1; j < m + 1; ++j){
                if((s[i - 1] == p[j - 1]) || (p[j - 1] == '?')){
                    dp[i][j] = dp[i - 1][j - 1];
                }else if(p[j - 1] == '*'){
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp[n][m];
    }
};
