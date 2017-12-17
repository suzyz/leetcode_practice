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
	int leftmost = 0, maxlevel = -1;
    int findBottomLeftValue(TreeNode* root) {
        dfs(root,0);
        return leftmost;
    }

    void dfs(TreeNode *cur,int level)
    {
    	if (cur->left)
    		dfs(cur->left,level+1);
    	
    	if (cur->right)
    		dfs(cur->right,level+1);
    	
    	if (maxlevel < level)
    	{
    		maxlevel = level;
    		leftmost = cur->val;
    	}
    }
};
