class TrieNode{
public:
    TrieNode* links[26];
    bool isEnd;
    string word;

    TrieNode(){
        for(auto& a: links){
            a = nullptr;
        }
        isEnd = false;
        word = "";
    }
};

class Solution {
    TrieNode* root = new TrieNode();
public:
    void insert(string& word){
        TrieNode* node = root;
        for(char& c: word){
            if(!node->links[c - 'a']){
                node->links[c - 'a'] = new TrieNode();
            }
            node = node->links[c - 'a'];
        }
        node->isEnd = true;
        node->word = word;
    }
    bool isValid(int i, int j, int n, int m, vector<vector<char>>& board){
        return i >= 0 && i < n && j >= 0 && j < m && board[i][j] != '#';
    }
    void dfs(int i, int j, int n, int m, TrieNode* node, vector<vector<char>>& board, vector<string>& ans){
        char val = board[i][j];
        node = node->links[val - 'a'];
        if(node == NULL){
            return;
        }
        if(node->isEnd == true){
            ans.push_back(node->word);
            node->isEnd = false;
        }
        board[i][j] = '#';
        if(isValid(i + 1, j, n, m, board)){
            dfs(i + 1, j, n, m, node, board, ans);
        }
        if(isValid(i - 1, j, n, m, board)){
            dfs(i - 1, j, n, m, node, board, ans);
        }
        if(isValid(i, j + 1, n, m, board)){
            dfs(i, j + 1, n, m, node, board, ans);
        }
        if(isValid(i, j - 1, n, m, board)){
            dfs(i, j - 1, n, m, node, board, ans);
        }
        board[i][j] = val;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size(), m = board[0].size();
        vector<string> ans;
        for(auto& word: words){
            insert(word);
        }
        TrieNode* node = root;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(node->links[board[i][j] - 'a']){
                    dfs(i, j, n, m, node, board, ans);
                }
            }
        }
        return ans;
    }
};
