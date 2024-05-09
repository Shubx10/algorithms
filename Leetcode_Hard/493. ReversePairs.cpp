class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high, int& pairs){
        int j = mid + 1;
        for(int i = low; i <= mid; ++i){
            while(j <= high && nums[i] > 2 * 1LL * nums[j]){
                j++;
            }
            pairs += j - (mid + 1);
        }
        int size = high - low + 1;
        vector<int> temp(size, 0);
        int left = low, right = mid + 1, k = 0;
        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp[k++] = nums[left++];
            }else{
                temp[k++] = nums[right++];

            }
        }
        while(left <= mid){
            temp[k++] = nums[left++];
        }
        while(right <= high){
            temp[k++] = nums[right++];
        }
        int p = 0;
        for(int i = low; i <= high; ++i){
            nums[i] = temp[p++];
        }
    }
    void mergeSort(vector<int>& nums, int low, int high, int& pairs){
        if(low >= high){
            return;
        }
        int mid = (low + high) / 2;
        mergeSort(nums, low, mid, pairs);
        mergeSort(nums, mid + 1, high, pairs);
        merge(nums, low, mid, high, pairs);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int pairs = 0;
        mergeSort(nums, 0, n - 1, pairs);
        return pairs;
    }
};
