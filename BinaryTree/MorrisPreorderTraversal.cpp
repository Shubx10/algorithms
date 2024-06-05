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
    vector<int> preorderTraversal(TreeNode* root) {
        //Morris Traversal
        vector<int> preorder;
        TreeNode* curr = root;
        while(curr){
            if(curr->left == NULL){
                preorder.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode* rightMost = curr->left;
                while(rightMost->right && rightMost->right != curr){
                    rightMost = rightMost->right;
                }
                if(rightMost->right == NULL){
                    rightMost->right = curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }else{
                    rightMost->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};
