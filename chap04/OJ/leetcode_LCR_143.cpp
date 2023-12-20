/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool match_one(TreeNode *A, TreeNode *B){
        //B可为空
        if(B == NULL)return true;
        //B不为空， A为空
        if(A == NULL)return false;
        if(A->val != B->val)return false;
        return match_one(A->left, B->left)
            && match_one(A->right, B->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        //空树 不会是以 tree1 的某个节点为根的子树具有 相同的结构和节点值 。
        if(A == NULL || B == NULL)return false;
        if(A->val == B->val && match_one(A, B)){
            return true;
        }
        return isSubStructure(A->left, B)
            || isSubStructure(A->right, B);
    }
};