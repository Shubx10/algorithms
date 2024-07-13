class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<int, int>> actualInd;
        for(int i = 0; i < n; ++i){
            actualInd.push_back({positions[i], i});
        }
        sort(actualInd.begin(), actualInd.end());
        stack<int> st;
        for(int i = 0; i < n; ++i){
            int ind = actualInd[i].second;
            if(directions[ind] == 'R'){
                st.push(ind);
            }else{
                while(!st.empty() && healths[ind] > 0){
                    if(healths[st.top()] > healths[ind]){
                        healths[ind] = 0;
                        healths[st.top()]--;
                    }else if(healths[st.top()] < healths[ind]){
                        healths[ind]--;
                        healths[st.top()] = 0;
                        st.pop();
                    }else{
                        healths[ind] = 0;
                        healths[st.top()] = 0;
                        st.pop();
                    }
                }
            }
        }
        vector<int> ans;
        for(int& health: healths){
            if(health > 0){
                ans.push_back(health);
            }
        }
        return ans;
    }
};
