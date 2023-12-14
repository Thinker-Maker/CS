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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //递归出口
        if(preorder.size() == 0)return NULL;
        int pos = 0;
        while(inorder[pos] != preorder[0])pos++;
        vector<int> pre_part, in_part;
        for(int i = 1; i <= pos; i++){
            pre_part.push_back(preorder[i]);
        }
        for(int i = 0; i < pos; i++){
            in_part.push_back(inorder[i]);
        }
        TreeNode *root = new TreeNode(preorder[0]);
        root->left = buildTree(pre_part, in_part);
        pre_part.clear();
        in_part.clear();
        for(int i = pos + 1; i < preorder.size(); i++){
            pre_part.push_back(preorder[i]);
        }
        for(int i = pos + 1; i < inorder.size(); i++){
            in_part.push_back(inorder[i]);
        }
        root->right = buildTree(pre_part, in_part);
        return root;
    }
};