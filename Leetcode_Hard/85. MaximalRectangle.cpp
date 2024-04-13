class Solution {
public:
    int maxRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsr(n), nsl(n);
        stack<int> str, stl;
        for(int i = n - 1; i >= 0; --i){
            while(!str.empty() && heights[str.top()] >= heights[i]){
                str.pop();
            }
            nsr[i] = str.empty() ? n : str.top();
            str.push(i);
        }
        for(int i = 0; i < n; ++i){
            while(!stl.empty() && heights[stl.top()] >= heights[i]){
                stl.pop();
            }
            nsl[i] = stl.empty() ? -1 : stl.top();
            stl.push(i);
        }
        int maxi = 0;
        for(int i = 0; i < n; ++i){
            int area = heights[i] * (nsr[i] - nsl[i] - 1);
            maxi = max(maxi, area);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> heights(m);
        int maxArea = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(matrix[i][j] == '1'){
                    heights[j] += 1;
                }else{
                    heights[j] = 0;
                }
            }
            maxArea = max(maxArea, maxRectangleArea(heights));
        }
        return maxArea;
    }
};
