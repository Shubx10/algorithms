class Solution {
public:
    TreeNode* postInTree(vector<int>& postorder, unordered_map<int, int>& mp, int postStart, int postEnd, int inStart, int inEnd){
        if(postStart > postEnd || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = mp[root->val];
        int sizeLeft = inRoot - inStart;
        root->left = postInTree(postorder, mp, postStart, postStart + sizeLeft - 1, inStart, inRoot - 1);
        root->right = postInTree(postorder, mp, postStart + sizeLeft, postEnd - 1, inRoot + 1, inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i) mp[inorder[i]] = i;
        TreeNode* root = postInTree(postorder, mp, 0, n - 1, 0, n - 1);
        return root;
    }
};
