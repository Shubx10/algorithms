class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(s.length() == 0 || words.size() == 0 || words[0].length() == 0){
            return ans;
        }
        int n = s.size();
        int numWords = words.size();
        int wordLen = words[0].length();
        int substringLength = wordLen * numWords;
        unordered_map<string, int> mp;
        for(string& word: words){
            mp[word]++;
        }
        for(int i = 0; i < wordLen; ++i){
            unordered_map<string, int> seenWords;
            int left = i;
            int cnt = 0;
            for(int j = i; j <= n - wordLen; j += wordLen){
                string word = s.substr(j, wordLen);
                if(mp.count(word)){
                    seenWords[word]++;
                    cnt++;
                    while(seenWords[word] > mp[word]){
                        string leftWord = s.substr(left, wordLen);
                        seenWords[leftWord]--;
                        cnt--;
                        left += wordLen;
                    }
                    if(cnt == numWords){
                        ans.push_back(left);
                    }
                }else{
                    seenWords.clear();
                    cnt = 0;
                    left = j + wordLen;
                }
            }
        }
        return ans;
    }
};
