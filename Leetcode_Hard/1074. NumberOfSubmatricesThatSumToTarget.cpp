class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_map<int, int> mp;
        int cnt = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 1; j < n; ++j){
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        for(int k = 0; k < n; ++k){
            for(int j = k; j < n; ++j){
                mp.clear();
                mp[0] = 1;
                int curr_sum = 0;
                for(int i = 0; i < m; ++i){
                    int prev_sum = k > 0 ? matrix[i][k - 1] : 0;
                    curr_sum += matrix[i][j] - prev_sum;
                    cnt += mp[curr_sum - target];
                    mp[curr_sum]++;
                }
            }
        }
        return cnt;
    }
};
