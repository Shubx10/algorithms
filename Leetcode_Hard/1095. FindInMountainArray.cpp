class Solution {
public:
    int bs_first(int target, MountainArray &mountainArr, int pivot){
        int i = 0, j = pivot;
        while(i <= j){
            int mid = i + (j - i) / 2;
            int val = mountainArr.get(mid);
            if(val == target){
                return mid;
            }else if(val < target){
                i = mid + 1;
            }else{
                j = mid - 1;
            }
        }
        return -1;
    }
    int bs_second(int target, MountainArray &mountainArr, int pivot){
        int i = pivot + 1, j = mountainArr.length() - 1;
        while(i <= j){
            int mid = i + (j - i) / 2;
            int val = mountainArr.get(mid);
            if(val == target){
                return mid;
            }else if(val < target){
                j = mid - 1;
            }else{
                i = mid + 1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int i = 0, j = mountainArr.length() - 1;
        while(i < j){
            int mid = i + (j - i) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)){
                i = mid + 1;
            }else{
                j = mid;
            }
        }
        int pivot = i;
        int ans = -1;
        ans = bs_first(target, mountainArr, pivot);
        return ans > -1 ? ans : bs_second(target, mountainArr, pivot);
    }
};
