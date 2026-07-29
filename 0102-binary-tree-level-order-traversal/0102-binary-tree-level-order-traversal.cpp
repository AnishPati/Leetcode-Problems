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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>> ans;
        TreeNode *temp;

        if(root==NULL){return ans;}
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> level;

            while(size--){
                temp = q.front();
                q.pop();

                level.push_back(temp->val);
                //left side
                if(temp->left){
                    q.push(temp->left);
                }
                //right side
                if(temp->right){
                    q.push(temp->right);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};