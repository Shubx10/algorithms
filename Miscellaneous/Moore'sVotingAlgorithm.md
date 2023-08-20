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
