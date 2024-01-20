class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = n - 1; i >= 0; --i){
            int cnt = 0;
            while(!st.empty() && st.top() < heights[i]){
                st.pop();
                cnt++;
            }
            ans[i] = st.empty() ? cnt : cnt + 1;
            st.push(heights[i]);
        }
        return ans;
    }
};
