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
	int max_sum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max_sum;
    }

    int dfs(TreeNode *cur)
    {
    	if (cur == NULL)
    		return 0;

    	int l = dfs(cur->left);
    	int r = dfs(cur->right);

    	int x = max(0,max(l,r)) + cur->val;
    	int y = l + r + cur->val;

    	max_sum = max(max_sum,max(x,y));
    	return x;
    }
};
