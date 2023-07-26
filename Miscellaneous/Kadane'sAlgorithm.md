# Kadane's Algorithm and it's variations
<ul>
  <li>Time Complexity - O(n)</li>
  <li>Space Complexity - O(1)</li>
</ul>

<h3><a href="https://leetcode.com/problems/maximum-subarray/">1. Maximum Subarray</a></h3>

> Given an integer array `nums` , find the contiguous subarray with the largest sum, and return its sum.

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
<h3><a href="https://leetcode.com/problems/maximum-sum-circular-subarray/">2. Maximum Sum Circular Subarray</a></h3>

> Given a circular integer array `nums` of length `n` , return the maximum possible sum of a non-empty subarray of `nums`.

> A circular array means the end of the array connects to the beginning of the array. Formally, the next element of `nums[i]` is `nums[(i + 1) % n]` and the previous element of `nums[i]` is `nums[(i - 1 + n) % n]` .

> A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray `nums[i] , nums[i + 1], ..., nums[j]` , there does not exist `i <= k1` , `k2 <= j` with `k1 % n == k2 % n`.

```cpp
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, sum1 = 0, sum2 = 0, maxi = INT_MIN, mini = INT_MAX;
        for(auto &x: nums){
            total += x;
            sum1 += x;
            sum2 += x;
            maxi = max(maxi, sum1);
            if(sum1 < 0) sum1 = 0;
            mini = min(mini, sum2);
            if(sum2 > 0) sum2 = 0;
        }
        return (total == mini) ? maxi : max(maxi, total - mini);
    }
};
```
