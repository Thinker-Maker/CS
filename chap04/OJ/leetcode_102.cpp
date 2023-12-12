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
        //一层的开头
        //constructor: vector<int>()
        if(k == ans.size() + 1)ans.push_back(vector<int>());
        //层数和数组下标差1
        ans[k - 1].push_back(root->val);
        dfs(root->left, k + 1, ans);
        dfs(root->right, k + 1, ans);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, 1, ans);
        return ans;
    }
};

class Solution {
public:
//bfs Kth_level
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        //不加下面这句 会导致26行对空解引用nullptr->val
        if(root == NULL)return ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            vector<int> tmp;
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++){
                TreeNode *node = q.front();
                tmp.push_back(node->val);
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};