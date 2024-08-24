/*
struct Node{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
public:
    vector<int> topView(Node *root){
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            Node* frontNode = node.first;
            int line = node.second;
            if(!mp.count(line)){
                mp[line] = frontNode->data;
            }
            if(frontNode->left){
                q.push({frontNode->left, line - 1});
            }
            if(frontNode->right){
                q.push({frontNode->right, line + 1});
            }
        }
        vector<int> ans;
        for(auto& i: mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};
