class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int area = 0;
        vector<int> maxR(n), maxL(n);
        maxR[0] = height[0];
        maxL[n - 1] = height[n - 1];
        for(int i = 1; i < n; ++i){
            maxR[i] = max(maxR[i - 1], height[i]);
        }
        for(int i = n - 2; i >= 0; --i){
            maxL[i] = max(maxL[i + 1], height[i]);
        }
        for(int i = 0; i < n; ++i){
            area += min(maxR[i], maxL[i]) - height[i];
        }
        return area;
    }
};
