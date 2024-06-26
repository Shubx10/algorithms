class Solution {
public:
    int atmostDistinct(vector<int>& nums, int k){
        int n = nums.size();
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        int count = 0;
        while(j < n){
            mp[nums[j]]++;
            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            count += j - i + 1;
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostDistinct(nums, k) - atmostDistinct(nums, k - 1);
    }
};
