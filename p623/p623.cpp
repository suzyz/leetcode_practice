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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode *tmp = new TreeNode(v);
            tmp->left = root;
            return tmp;
        }
        
        dfs(root, d-2, v);
        
        return root;
    }
    
    void dfs(TreeNode *cur, int rem, int v) {
        if (cur == NULL)
            return;
        
        if (rem == 0) {
            TreeNode *l = cur->left, *r = cur->right;
            cur->left = new TreeNode(v);
            cur->right = new TreeNode(v);
            cur->left->left = l;
            cur->right->right = r;
            
            return;
        }
        
        dfs(cur->left, rem-1, v);
        dfs(cur->right, rem-1, v);
    }
};