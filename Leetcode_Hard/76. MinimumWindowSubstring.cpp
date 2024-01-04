class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        vector<int> mp(128, 0);
        for(char c: t) mp[c]++;
        int cnt = t.size(), i = 0, j = 0, mini = INT_MAX, start = 0;
        while(j < s.size()){
            if(mp[s[j]] > 0) cnt--;
            mp[s[j]]--;
            while(cnt == 0){
                if(j - i + 1 < mini){
                    start = i;
                    mini = j - i + 1;
                }
                if(mp[s[i]] == 0) cnt++;
                mp[s[i]]++;
                i++;
            }
            j++;
        }
        return mini == INT_MAX ? "" : s.substr(start, mini);
    }
};
