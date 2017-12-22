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
	int sum = 0;
    int findTilt(TreeNode* root) {
    	int l = 0, r = 0;
        dfs(root);

        return sum;
    }

    int dfs(TreeNode *cur)
    {
    	if (cur == NULL)
    		return 0;

    	int l = dfs(cur->left);
    	int r = dfs(cur->right);

    	if (l > r)
    		sum += l-r;
    	else
    		sum += r-l;

    	return l + r + cur->val;
    }
};
