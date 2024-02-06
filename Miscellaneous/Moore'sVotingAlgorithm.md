# Boyer - Moore Majority Voting Algorithm
<ul>
  <li>Time Complexity - O(n)</li>
  <li>Space Complexity - O(1)</li>
</ul>

<h3><a href="https://leetcode.com/problems/majority-element/">1. Majority Element</a></h3>

>Given an array `nums` of size `n`, return the majority element. The majority element is the element that appears more than `⌊n / 2⌋` times. If none of the elements is in majority, return `-1`.

```cpp
class Solution{
public:
    int majorityElement(vector<int>& nums){
        int cnt = 0;
        int element;
        for(int i = 0; i < nums.size(); ++i){
            if(cnt == 0){
                element = nums[i];
                cnt++;
            }else if(nums[i] == element){
                cnt++;
            }else{
                cnt--;
            }
        }
        int c = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == element) c++;
        }
        return c > nums.size() / 2 ? element : -1;
    }
};
```

<h3><a href="https://leetcode.com/problems/majority-element/">2. Majority Element II</a></h3>

>Given an integer array of size `n`, find all elements that appear more than `⌊n / 3⌋` times.

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;
        for(int i = 0; i < n; ++i){
            if(cnt1 == 0 && el2 != nums[i]){
                cnt1++;
                el1 = nums[i];
            }else if(cnt2 == 0 && el1 != nums[i]){
                cnt2++;
                el2 = nums[i];
            }else if(nums[i] == el1){
                cnt1++;
            }else if(nums[i] == el2){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; ++i){
            if(nums[i] == el1) cnt1++;
            else if(nums[i] == el2) cnt2++;
        }
        if(cnt1 > n / 3) ans.push_back(el1);
        if(cnt2 > n / 3) ans.push_back(el2);
        return ans;
    }
};
```
