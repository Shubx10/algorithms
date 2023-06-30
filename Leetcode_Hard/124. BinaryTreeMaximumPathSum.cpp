class Solution {
public:
    int height(TreeNode* root, int &maxi){
        if(root == NULL) return 0;
        int maxL = max(0, height(root->left, maxi));
        int maxR = max(0, height(root->right, maxi));
        maxi = max(maxi, root->val + maxL + maxR);
        return root->val + max(maxL, maxR);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        height(root, maxi);
        return maxi;
    }
};
