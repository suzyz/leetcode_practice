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
	TreeNode *p = NULL, *q = NULL, *pre = NULL;
    void recoverTree(TreeNode* root) {
    	if (root == NULL)
    		return;

    	dfs(root);

    	if (p && q)
    	{
    		int tmp = p->val;
    		p->val = q->val;
    		q->val = tmp;
    	}
    }

    void dfs(TreeNode *root)
    {
    	if (root == NULL)
    		return;

    	dfs(root->left);

    	if (pre != NULL && root->val < pre->val)
    	{
    		if (p == NULL)
    		{
    			p = pre;
    			q = root;
    		}
    		else
    			q = root;
    	}

    	pre = root;
    	dfs(root->right);
    }
};