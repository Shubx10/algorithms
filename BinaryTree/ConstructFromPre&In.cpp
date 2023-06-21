class Solution {
public:
    TreeNode* preInTree(vector<int>& preorder, vector<int>& inorder,int& preInd, int is, int ie){
        if(preInd >= preorder.size() || is > ie) return NULL;
        TreeNode* root = new TreeNode(preorder[preInd++]);
        int pos;
        for(int i=is; i<ie; ++i){
            if(inorder[i] == root->val){
                pos = i;
                break;
            }
        }
        root->left = preInTree(preorder, inorder, preInd, is, pos-1);
        root->right = preInTree(preorder, inorder, preInd, pos+1, ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preInd = 0;
        TreeNode* ans = preInTree(preorder, inorder, preInd, 0, inorder.size());
        return ans;
    }
};
