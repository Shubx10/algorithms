class Solution {
public:
    int countPairs(int mid, int n, vector<int> nums){
        int pairCnt = 0;
        int i = 0, j = 1;
        while(j < n){
            while(nums[j] - nums[i] > mid){
                i++;
            }
            pairCnt += (j - i);
            j++;
        }
        return pairCnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = -1;
        int low = 0, high = nums[n - 1] - nums[0];
        while(low <= high){
            int mid = low + (high - low) / 2;
            int pairs = countPairs(mid, n, nums);
            if(pairs < k){
                low = mid + 1;
            }else{
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};
