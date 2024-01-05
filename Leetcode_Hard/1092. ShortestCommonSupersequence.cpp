class Solution {
public:
    string printSCS(string s1, string s2){
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1));
        for(int i = 1; i < n + 1; ++i){
            for(int j = 1; j < m + 1; ++j){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        string ans = "";
        int i = n, j = m;
        while(i > 0 && j > 0){
            if(s1[i - 1] == s2[j - 1]){
                ans += s1[i - 1];
                i--;
                j--;
            }else if(dp[i - 1][j] > dp[i][j - 1]){
                ans += s1[i - 1];
                i--;
            }else{
                ans += s2[j - 1];
                j--;
            }
        }
        while(i > 0){
            ans += s1[i - 1];
            i--;
        }
        while(j > 0){
            ans += s2[j - 1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        return printSCS(str1, str2);
    }
};
