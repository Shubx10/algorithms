class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxInd = 0;
        int level = 0, cnt = 0;
        for(int i = 0; i < n - 1; ++i){
            maxInd = max(maxInd, nums[i] + i);
            if(maxInd >= n - 1){
                cnt++;
                break;
            }
            if(level == i){
                cnt++;
                level = maxInd;
            }
        }
        return cnt;
    }
};
