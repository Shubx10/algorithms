class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxInd = 0;
        for(int i = 0; i < n - 1; ++i){
            maxInd = max(maxInd, nums[i] + i);
            if(maxInd <= i) return false;
        }
        return true;
    }
};
