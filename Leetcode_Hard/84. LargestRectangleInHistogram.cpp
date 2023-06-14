class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsr(heights.size()), nsl(heights.size());
        stack<int> str, stl;
        for(int i=heights.size()-1; i>=0; --i){
            if(str.empty()){
                nsr[i] = heights.size();
            }else{
                while(!str.empty() && heights[str.top()]>=heights[i]){
                    str.pop();
                }
                if(str.empty()) nsr[i] = heights.size();
                else nsr[i] = str.top();
            }
            str.push(i);
        }
        for(int i=0; i<heights.size(); ++i){
            if(stl.empty()){
                nsl[i] = -1;
            }else{
                while(!stl.empty() && heights[stl.top()]>=heights[i]){
                    stl.pop();
                }
                if(stl.empty()) nsl[i] = -1;
                else nsl[i] = stl.top();
            }
            stl.push(i);
        }
        int maxi = 0;
        for(int i=0; i<heights.size(); ++i){
            int area = heights[i] * (nsr[i] - nsl[i] -1);
            maxi = max(maxi, area);
        }
        return maxi;
    }
};
