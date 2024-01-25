# 🚀Kadane's Algorithm and it's variations
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
<h3><a href="https://leetcode.com/problems/maximum-sum-circular-subarray/">3. Largest Sum Subarray of Size at least K</a></h3>

> Given an array `a` of length `n` and a number `k`, find the largest sum of the subarray containing `at least k` numbers.

```cpp
class Solution {
public:    
    long long int maxSumWithK(vector<long long int>& a, long long int n, long long int k) {
        vector<long long int> pref(n);
        long long int sum = 0, maxi = LONG_MIN;
        for(int i = 0; i < n; ++i){
            sum += a[i];
            pref[i] = sum;
            if(sum < 0) sum = 0;
        }
        sum = 0;
        for(int i = 0; i < k; ++i) sum += a[i];
        maxi = max(maxi, sum);
        for(int j = k; j < n; ++j){
            sum += a[j];
            sum -= a[j - k];
            maxi = max(maxi, sum);
            maxi = max(maxi, sum + pref[j - k]);
        }
        return maxi;
    }
};
```
<h3><a href="https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/">4. Maximum Absolute Sum of Any Subarray</a></h3>

> You are given an integer array nums. The absolute sum of a subarray `[numsl, numsl+1, ..., numsr-1, numsr]` is `abs(numsl + numsl+1 + ... + numsr-1 + numsr)`.

> Return the maximum absolute sum of any (possibly empty) subarray of nums.

```cpp
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0], mini = nums[0];
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < n; ++i){
            sum1 += nums[i];
            sum2 += nums[i];
            maxi = max(maxi, sum1);
            mini = min(mini, sum2);
            if(sum1 < 0) sum1 = 0;
            if(sum2 > 0) sum2 = 0;
        }
        return max(maxi, abs(mini));
    }
};
```
