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

    void dfs(TreeNode* root, int k, vector<vector<int>>& ans){
        if(root == nullptr)return;
        if(k == ans.size())ans.push_back(vector<int>());
        ans[k].push_back(root->val);
        dfs(root->left, k + 1, ans);
        dfs(root->right, k + 1, ans);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        //偶数层逆置
        for(int i = 1; i < ans.size(); i += 2){
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)return ans;
        queue<TreeNode *> que;
        que.push(root);
        while(!que.empty()){
            int k = que.size();
            vector<int> tmp;
            for(int i = 0; i < k; i++){
                TreeNode *node = que.front();
                que.pop();
                tmp.push_back(node->val);
                if(node->left)que.push(node->left);
                if(node->right)que.push(node->right);
            }
            ans.push_back(tmp);
        }
        for(int k = 1; k < ans.size(); k += 2){
            for(int i = 0, j = ans[k].size() - 1; i < j; i++, j--){
                swap(ans[k][i], ans[k][j]);
            }
        }
        return ans;
    }
};