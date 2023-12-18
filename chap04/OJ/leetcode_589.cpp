/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(root == nullptr)return ans;
        ans.push_back(root->val);
        for(auto x : root->children){
            //用递归
            vector<int> tmp  = preorder(x);
            //拷贝数据
            for(auto y : tmp)ans.push_back(y);
        }
        return ans;
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    //封装+传引用：避免数据重复拷贝
    void __preorder(Node *root, vector<int>& ans){
        if(root == nullptr)return;
        ans.push_back(root->val);
        //循环+递归
        for(auto x : root->children){
            __preorder(x, ans);
        }
        return;
    }

    vector<int> preorder(Node* root) {
        vector<int> ans;
        __preorder(root, ans);
        return ans;
    }
};
