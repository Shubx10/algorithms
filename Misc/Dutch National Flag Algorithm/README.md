# Dutch National Flag Algorithm 

<ul>
  <li> Time Complexity - O(n)
  <li>Space Complexity - O(1)
</ul>

## Problem Statement
<p>Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.</p>

## Test Cases
```
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```
```
Input: nums = [2,0,1]
Output: [0,1,2]
```

## Algorithm
```cpp
class Solution {
public:
    void dutchFlagAlgorithm(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }else if(nums[mid] == 1){
                mid++;
            }else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
```
