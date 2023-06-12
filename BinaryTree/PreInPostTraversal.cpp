// Preorder Inorder and Postorder in single Traversal
//
//
//Iterative version
class Solution {
public:
    vector<int> PreInPostTraversal(TreeNode* root) {
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        vector<int> pre, in, post;
        if(root == NULL) return;
        while(!st.empty()){
            auto it = st.top();
            st.pop();
            //this is part of preorder
            //increment 1 to 2
            //push the left side of the tree
            if(it.second == 1){
                pre.push_back(it.first->val);
                it.second++;
                st.push(it);
                if(it.first->left){
                    st.push({it.first->left, 1});
                }
            }
            //this is part of inorder
            //increment 2 to 3
            //push the right side of the tree
            else if(it.second == 2){
                in.push_back(it.first->val);
                it.second++;
                st.push(it);
                if(it.first->right){
                    st.push({it.first->right, 1});
                }
            }else{
                post.push_back(it.first->val);
            }
        }
    }
};
//
//
// Recursive version
void trav(TreeNode* root,vector<int> &in, vector<int> &pre, vector<int> &post){
    if(!root) return;
    pre.push_back(root->data);
    trav(root->left, in, pre, post);
    in.push_back(root->data);
    trav(root->right, in, pre, post);
    post.push_back(root->data);
}
