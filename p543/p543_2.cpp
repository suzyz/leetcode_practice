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
	int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
        	return 0;

        dfs(root);
        return res;
    }

    int dfs(TreeNode *cur)
    {
        int l = 0, r = 0;
    	if (cur->left != NULL)
    		l = dfs(cur->left) + 1;
    	if (cur->right != NULL)
    		r = dfs(cur->right) + 1;

    	res = max(res,l+r);
    	return max(l,r);
    }
};
