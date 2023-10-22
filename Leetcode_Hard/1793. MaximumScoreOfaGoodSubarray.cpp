class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int i = k, j = k;
        int mini = nums[k];
        int maxi = mini * (j - i + 1);
        while(j < n - 1 || i > 0){
            int right = j < n - 1 ? min(mini, nums[j + 1]) * (j - i + 2) : INT_MIN;
            int left = i > 0 ? min(mini, nums[i - 1]) * (j - i + 2) : INT_MIN;
            if(right > left){
                j++;
                mini = min(mini, nums[j]);
            }else{
                i--;
                mini = min(mini, nums[i]);
            }
            maxi = max(maxi, mini * (j - i + 1));
        }
        return maxi;
    }
};
