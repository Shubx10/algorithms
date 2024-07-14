class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();
        stack<unordered_map<string, int>> st;
        st.push(unordered_map<string, int>());
        int i = 0;
        while(i < n){
            if(formula[i] == '('){
                st.push(unordered_map<string, int>());
                i++;
            }else if(formula[i] == ')'){
                unordered_map<string, int> mp = st.top();
                st.pop();
                i++;
                string multiplier;
                while(i < n && isdigit(formula[i])){
                    multiplier += formula[i];
                    i++;
                }
                if(multiplier.size()){
                    int mult = stoi(multiplier);
                    for(auto& it: mp){
                        it.second *= mult;
                    }
                }
                for(auto& it: mp){
                    st.top()[it.first] += it.second;
                }
            }else{
                string currAtom;
                currAtom += formula[i];
                i++;
                while(i < n && islower(formula[i])){
                    currAtom += formula[i];
                    i++;
                }
                string currCount;
                while(i < n && isdigit(formula[i])){
                    currCount += formula[i];
                    i++;
                }
                int count = currCount.empty() ? 1 : stoi(currCount);
                st.top()[currAtom] += count;
            }
        }
        map<string, int> finalMap(st.top().begin(), st.top().end());
        string ans;
        for(auto& it: finalMap){
            ans += it.first;
            if(it.second > 1){
                ans += to_string(it.second);
            }
        }
        return ans;
    }
};
