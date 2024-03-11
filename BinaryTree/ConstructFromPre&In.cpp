// class Solution {
// public:
//     TreeNode* preInTree(vector<int>& preorder, vector<int>& inorder,int& preInd, int is, int ie){
//         if(preInd >= preorder.size() || is > ie) return NULL;
//         TreeNode* root = new TreeNode(preorder[preInd++]);
//         int pos;
//         for(int i=is; i<ie; ++i){
//             if(inorder[i] == root->val){
//                 pos = i;
//                 break;
//             }
//         }
//         root->left = preInTree(preorder, inorder, preInd, is, pos-1);
//         root->right = preInTree(preorder, inorder, preInd, pos+1, ie);
//         return root;
//     }
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         int preInd = 0;
//         TreeNode* ans = preInTree(preorder, inorder, preInd, 0, inorder.size());
//         return ans;
//     }
// };
class Solution {
public:
    TreeNode* preInTree(vector<int>& preorder, unordered_map<int, int>& mp, int preStart, int preEnd, int inStart, int inEnd){
        if(preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = mp[root->val];
        int numsLeft = inRoot - inStart;
        root->left = preInTree(preorder, mp, preStart + 1, preStart + numsLeft, inStart, inRoot - 1);
        root->right = preInTree(preorder, mp, preStart + numsLeft + 1, preEnd, inRoot + 1, inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i) mp[inorder[i]] = i;
        TreeNode* root = preInTree(preorder, mp, 0, n - 1, 0, n - 1);
        return root;
    }
};
