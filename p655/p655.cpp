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
    
    pair<int, int> getSize(TreeNode *root) {
        if (root == NULL)
            return make_pair(0, 0);
        
        pair<int, int> l = getSize(root->left), r = getSize(root->right);
        return make_pair(max(l.first, r.first) + 1, max(l.second, r.second) * 2 + 1);
    }
    
    void print(TreeNode *root, int level, int st, int en, vector<vector<string>>& res) {
        if (root == NULL)
            return;
        
        int mid = (st+en)>>1;
        res[level][mid] = to_string(root->val);
        print(root->left, level+1, st, mid-1, res);
        print(root->right, level+1, mid+1, en, res);
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        pair<int, int> sz = getSize(root);
        vector<vector<string>> res(sz.first, vector<string>(sz.second));
        
        print(root, 0, 0, res[0].size()-1, res);
        
        return res;
    }
};