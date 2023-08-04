class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();
            if(vec.size() > level){
                level++;
                for(auto it: usedOnLevel){
                    st.erase(it);
                }
                usedOnLevel.clear();
            }
            string word = vec.back();
            if(word == endWord){
                if(ans.size() == 0){
                    ans.push_back(vec);
                }else if(ans[0].size() == vec.size()){
                    ans.push_back(vec);
                }
            }
            for(int i = 0; i < word.size(); ++i){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ++ch){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};
