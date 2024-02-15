class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if(!root) return node;
        TreeNode* temp = root;
        while(true){
            if(temp->val < val){
                if(temp->right) temp = temp->right;
                else{
                    temp->right = node;
                    break;
                } 
            }else{
                if(temp->left) temp = temp->left;
                else{
                    temp->left = node;
                    break;
                } 
            }
        }
        return root;
    }
};
