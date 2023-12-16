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

    void dfs(TreeNode *root, int k, vector<vector<int>>& ans){
        if(root == nullptr)return;
        if(ans.size() + 1 == k)ans.push_back(vector<int>());
        ans[k - 1].push_back(root->val);
        dfs(root->left, k + 1, ans);
        dfs(root->right, k + 1, ans);
        return;
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, 1, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        //防止对空解引用
        if(root == nullptr)return ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int levelSize = q.size();
            vector<int> tmp;
            for(int i = 0; i < levelSize; i++){
                TreeNode* node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            ans.push_back(tmp);
        }
        //reverse
        for(int i = 0, j = ans.size() - 1; i < j; i++, j--){
            swap(ans[i], ans[j]);
        }
        return ans;
    }
};