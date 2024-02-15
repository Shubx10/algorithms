class Solution {
public:
    void inorder(TreeNode* root, int& ans, int& cnt, int k){
        if(root == NULL) return;
        inorder(root->left, ans, cnt, k);
        cnt++;
        if(cnt == k){
            ans = root->val;
            return;
        }
        inorder(root->right, ans, cnt, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1, cnt = 0;
        inorder(root, ans, cnt, k);
        return ans;
    }
};
