/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        map<int, map<int, vector<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();
            TreeNode* node = frontNode.first;
            int line = frontNode.second.first;
            int level = frontNode.second.second;
            mp[line][level].push_back(node->val);
            if(node->left){
                q.push({node->left, {line - 1, level + 1}});
            }
            if(node->right){
                q.push({node->right, {line + 1, level + 1}});
            }
        }
        vector<vector<int>> ans;
        for(auto& i: mp){
            vector<int> temp;
            for(auto& j: i.second){
                sort(j.second.begin(), j.second.end());
                for(auto& k: j.second){
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
