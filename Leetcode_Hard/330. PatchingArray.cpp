class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int m = nums.size();
        long long reachable = 0, patch = 0;
        int i = 0;
        while(reachable < n){
            if(i < m && nums[i] <= reachable + 1){
                reachable += nums[i];
                i++;
            }else{
                patch++;
                reachable += reachable + 1;
            }
        }
        return patch;
    }
};
