# Kadane's Algorithm
<ul>
  <li>Time Complexity - O(n)</li>
  <li>Space Complexity - O(1)</li>
</ul>

## Problem Statement
Given an integer array nums, find the contiguous subarray with the largest sum, and return its sum.

## Code

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxi = nums[0];
        for(int x: nums){
            sum += x;
            maxi = max(maxi, sum);
            if(sum < 0) sum = 0;
        }
        return maxi;
    }
};
```
