class Solution {
public:
    // int recur(int i, int j1, int j2, int m, int n, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
    //     if(j1 < 0 || j2 < 0 || j1 >= n || j2 >= n) return -1e8;
    //     if(i == m - 1){
    //         if(j1 == j2) return grid[i][j1];
    //         else return grid[i][j1] + grid[i][j2];
    //     }
    //     if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    //     int maxi = -1e8;
    //     for(int k1 = -1; k1 <= 1; ++k1){
    //         for(int k2 = -1; k2 <= 1; ++k2){
    //             int val = 0;
    //             if(j1 == j2) val = grid[i][j1];
    //             else val = grid[i][j1] + grid[i][j2];
    //             val += recur(i + 1, j1 + k1, j2 + k2, m, n, grid, dp);
    //             maxi = max(maxi, val);
    //         }
    //     }
    //     return dp[i][j1][j2] = maxi;
    // }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // return recur(0, 0, n - 1, m, n, grid);
        // vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        // return recur(0, 0, n - 1, m, n, grid, dp);

        //Tabulation
        // vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
        // for(int j1 = 0; j1 < n; ++j1){
        //     for(int j2 = 0; j2 < n; ++j2){
        //         if(j1 == j2) dp[m - 1][j1][j2] = grid[m - 1][j1];
        //         else dp[m - 1][j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
        //     }
        // }
        // for(int i = m - 2; i >= 0; --i){
        //     for(int j1 = 0; j1 < n; ++j1){
        //         for(int j2 = 0; j2 < n; ++j2){
        //             int maxi = -1e8;
        //             for(int k1 = -1; k1 <= 1; ++k1){
        //                 for(int k2 = -1; k2 <= 1; ++k2){
        //                     int val = 0;
        //                     if(j1 == j2) val = grid[i][j1];
        //                     else val = grid[i][j1] + grid[i][j2];
        //                     if(j1 + k1 >= 0 && j1 + k1 < n && j2 + k2 >= 0 && j2 + k2 < n) val += dp[i + 1][j1 + k1][j2 + k2];
        //                     else val += -1e8;
        //                     maxi = max(maxi, val);
        //                 }
        //             }
        //             dp[i][j1][j2] = maxi;
        //         }
        //     }
        // }
        // return dp[0][0][n - 1];

        //space optimization
        vector<vector<int>> front(n, vector<int>(n));
        vector<vector<int>> curr(n, vector<int>(n));
        for(int j1 = 0; j1 < n; ++j1){
            for(int j2 = 0; j2 < n; ++j2){
                if(j1 == j2) front[j1][j2] = grid[m - 1][j1];
                else front[j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
            }
        }
        for(int i = m - 2; i >= 0; --i){
            for(int j1 = 0; j1 < n; ++j1){
                for(int j2 = 0; j2 < n; ++j2){
                    int maxi = -1e8;
                    for(int k1 = -1; k1 <= 1; ++k1){
                        for(int k2 = -1; k2 <= 1; ++k2){
                            int val = 0;
                            if(j1 == j2) val = grid[i][j1];
                            else val = grid[i][j1] + grid[i][j2];
                            if(j1 + k1 >= 0 && j1 + k1 < n && j2 + k2 >= 0 && j2 + k2 < n) val += front[j1 + k1][j2 + k2];
                            else val += -1e8;
                            maxi = max(maxi, val);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            front = curr;
        }
        return front[0][n - 1];
    }
};
