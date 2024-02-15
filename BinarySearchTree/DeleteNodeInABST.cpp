class Solution {
public:
    TreeNode* findLastRight(TreeNode* root){
        while(root->right != NULL){
            root = root->right;
        }
        return root;
    }
    TreeNode* remaining(TreeNode* root){
        if(root->left == NULL){
            return root->right;
        }else if(root->right == NULL){
            return root->left;
        }
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key) return remaining(root);
        TreeNode* temp = root;
        while(root != NULL){
            if(root->val > key){
                if(root->left && root->left->val == key){
                    root->left = remaining(root->left);
                    break;
                }else{
                    root = root->left;
                }
            }else{
                if(root->right && root->right->val == key){
                    root->right = remaining(root->right);
                    break;
                }else{
                    root = root->right;
                }
            }
        }
        return temp;
    }
};
