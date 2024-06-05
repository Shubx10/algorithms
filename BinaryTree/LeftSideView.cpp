class Solution {
public:
    void leftView(TreeNode* root, vector<int> &ans, int level){
        if(root == NULL) return;
        if(ans.size() == level){
            ans.push_back(root->val);
        }
        leftView(root->left, ans, level + 1);
        leftView(root->right, ans, level + 1);
    }
    vector<int> leftSideView(TreeNode* root) {
        vector<int> ans;
        leftView(root, ans, 0);
        return ans;
    }
};
