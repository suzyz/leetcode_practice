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
    TreeNode* pruneTree(TreeNode* root) {
        if (!dfs(root))
        	return NULL;
        else
        	return root;
    }

    bool dfs(TreeNode* p) {
    	if (p == NULL)
    		return false;

    	if (!dfs(p->left))
    		p->left = NULL;

    	if (!dfs(p->right))
    		p->right = NULL;

    	if (p->left == NULL && p->right == NULL && p->val == 0)
    		return false;
    	else
    		return true;
    }
};