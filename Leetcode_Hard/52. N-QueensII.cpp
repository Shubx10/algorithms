class Solution {
public:
    bool isSafe(int row, int col, vector<string>& chess, int n){
        int r = row;
        int c = col;
        while(r >= 0 && c >= 0){
            if(chess[r][c] == 'Q') return false;
            r--, c--;
        }

        r = row;
        c = col;
        while(c >= 0){
            if(chess[r][c] == 'Q') return false;
            c--;
        }

        r = row;
        c = col;
        while(r < n && c >= 0){
            if(chess[r][c] == 'Q') return false;
            r++, c--;
        }

        return true;
    }

    void solve(int col, vector<string>& chess, int& ans, int n){
        if(col == n){
            ans++;
            return;
        }
        for(int row = 0; row < n; ++row){
            if(isSafe(row, col, chess, n)){
                chess[row][col] = 'Q';
                solve(col + 1, chess, ans, n);
                chess[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        int ans = 0;
        string s(n, '.');
        vector<string> chess(n, s);
        solve(0, chess, ans, n);
        return ans;
    }
};
