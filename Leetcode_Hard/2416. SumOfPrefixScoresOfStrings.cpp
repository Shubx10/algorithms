class TrieNode{
public:
    TrieNode* links[26];
    int cnt;
    TrieNode(){
        for(auto& a: links){
            a = nullptr;
        }
        cnt = 0;
    }
};
class Solution {
    TrieNode* root = new TrieNode();
    void insert(string& word){
        TrieNode* node = root;
        for(char& c: word){
            if(!node->links[c - 'a']){
                node->links[c - 'a'] = new TrieNode();
            }
            node = node->links[c - 'a'];
            node->cnt++;
        }
    }
    int getScore(string& word){
        int score = 0;
        TrieNode* node = root;
        for(char& c: word){
            node = node->links[c - 'a'];
            score += node->cnt;
        }
        return score;
    }
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        for(auto& word: words){
            insert(word);
        }
        vector<int> ans;
        for(auto& word: words){
            int score = getScore(word);
            ans.push_back(score);
        }
        return ans;
    }
};
