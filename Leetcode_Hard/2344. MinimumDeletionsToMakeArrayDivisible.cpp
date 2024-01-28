class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n = nums.size(), div = 0;
        for(int i: numsDivide) div = __gcd(div, i);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; ++i){
            if(div % nums[i] == 0) return i;
        }
        return -1;
    }
};
