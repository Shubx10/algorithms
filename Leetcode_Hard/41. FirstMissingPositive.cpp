class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            if(nums[i] > 0 && nums[i] <= n){
                int crtInd = nums[i] - 1;
                while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[crtInd]){
                    swap(nums[i], nums[crtInd]);
                    crtInd = nums[i] - 1;
                }
            }
        }
        for(int i = 0; i < n; ++i){
            if(nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};
