class Solution {
public:
    bool traverse(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL) return left == right;
        if(left->val != right->val) return false;
        return traverse(left->left, right->right) && traverse(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return root == NULL || traverse(root->left, root->right);
    }
};
