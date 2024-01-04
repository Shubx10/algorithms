class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string st = s;
        reverse(st.begin(), st.end());
        vector<vector<int>> dp(n + 1, vector<int> (n + 1));
        for(int i = 1; i < n + 1; ++i){
            for(int j = 1; j < n + 1; ++j){
                if(s[i - 1] == st[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return n - dp[n][n];
    }
};
