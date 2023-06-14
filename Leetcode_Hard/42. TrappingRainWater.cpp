class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxR(height.size()), maxL(height.size());
        maxR[0] = height[0];
        maxL[maxL.size()-1] = height[height.size()-1];
        for(int i=1; i<height.size(); ++i){
            maxR[i] = max(maxR[i-1], height[i]);
        }
        for(int i=height.size()-2; i>=0; --i){
            maxL[i] = max(maxL[i+1], height[i]);
        }
        int area = 0;
        for(int i=0; i<height.size(); ++i){
            area += min(maxR[i], maxL[i]) - height[i];
        }
        return area;
    }
};
