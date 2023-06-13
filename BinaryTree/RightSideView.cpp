class Solution {
public:
    void rightView(TreeNode* root, vector<int> &ans, int level){
        if(root == NULL) return;
        if(ans.size() == level) ans.push_back(root->val);

        rightView(root->right, ans, level+1);
        rightView(root->left, ans, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rightView(root, ans, 0);
        return ans;
    }
};
