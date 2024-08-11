class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<bool>>& vis, vector<vector<int>>& grid){
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 || vis[i][j]) return;
        vis[i][j] = true;
        dfs(i + 1, j, n, m, vis, grid);
        dfs(i - 1, j, n, m, vis, grid);
        dfs(i, j + 1, n, m, vis, grid);
        dfs(i, j - 1, n, m, vis, grid);
    }
    int countIslands(int n, int m, vector<vector<int>>& grid){
        int islands = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(!vis[i][j] && grid[i][j] == 1){
                    dfs(i, j, n, m, vis, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int initialIslands = countIslands(n, m, grid);
        if(initialIslands != 1){
            return 0;
        } 
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 0) continue;
                grid[i][j] = 0;
                int newIslandCount = countIslands(n, m, grid);
                if(newIslandCount != 1){
                    return 1;
                }
                grid[i][j] = 1;
            }
        }
        return 2;
    }
};
