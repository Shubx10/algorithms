class TrieNode{
public:
    TrieNode* links[2];
    
    TrieNode(){
        links[0] = nullptr;
        links[1] = nullptr;
    }
};

class Trie{
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }

    void insert(int num){
        TrieNode* node = root;
        for(int i = 31; i >= 0; --i){
            int bit = (num >> i) & 1;
            if(!node->links[bit]){
                node->links[bit] = new TrieNode();
            }
            node = node->links[bit];
        }
    }

    int getMax(int num){
        TrieNode* node = root;
        int maxi = 0;
        for(int i = 31; i >= 0; --i){
            int bit = (num >> i) & 1;
            if(node->links[1 - bit]){
                maxi = maxi | (1 << i);
                node = node->links[1 - bit];
            }else{
                node = node->links[bit];
            }
        }
        return maxi;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        vector<pair<int, pair<int, int>>> offlineQueries;
        for(int i = 0; i < q; ++i){
            offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(nums.begin(), nums.end());
        sort(offlineQueries.begin(), offlineQueries.end());
        vector<int> ans(q, 0);
        Trie trie;
        int ind = 0;
        for(int i = 0; i < q; ++i){
            int m = offlineQueries[i].first;
            int x = offlineQueries[i].second.first;
            int qInd = offlineQueries[i].second.second;
            while(ind < n && nums[ind] <= m){
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind == 0){
                ans[qInd] = -1;
            }else{
                ans[qInd] = trie.getMax(x);
            }
        }
        return ans;
    }
};
