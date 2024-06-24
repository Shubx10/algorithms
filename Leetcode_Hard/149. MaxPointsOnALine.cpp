class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // int n = points.size();
        // if(n == 1) return 1;
        // int maxPoints = 0;
        // for(int i = 0; i < n; ++i){
        //     for(int j = i + 1; j < n; ++j){
        //         int cnt = 2;
        //         int dx = points[j][0] - points[i][0];
        //         int dy = points[j][1] - points[i][1];
        //         /*
        //             dy / dx = dy_ / dx_
        //             dy * dx_ = dy_ * dx
        //         */
        //         for(int k = 0; k < n; ++k){
        //             if(k != i && k != j){
        //                 int dx_ = points[k][0] - points[j][0];
        //                 int dy_ = points[k][1] - points[j][1];
        //                 if(dy * dx_ == dy_ * dx) cnt++;
        //             }
        //         }
        //         maxPoints = max(maxPoints, cnt);
        //     }
        // }
        // return maxPoints;
        int n = points.size();
        int maxPoints = 0;
        for(int i = 0; i < n; ++i){
            unordered_map<double, int> mp;
            for(int j = 0; j < n; ++j){
                if(j == i){
                    continue;
                }
                double dx = points[j][0] - points[i][0];
                double dy = points[j][1] - points[i][1];
                if(dx == 0){
                    mp[INT_MAX]++;
                }else{
                    double slope = dy / dx;
                    mp[slope]++;
                }
            }
            int currMax = 0;
            for(auto& ele: mp){
                currMax = max(currMax, ele.second);
            }
            maxPoints = max(maxPoints, currMax);
        }
        return maxPoints + 1;
    }
};
//Brute Force - O(n3)
//Optimized Approach - O(n2)
