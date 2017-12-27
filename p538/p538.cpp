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
    TreeNode* convertBST(TreeNode* root) {

    	dfs(root);

        return root;
    }

    void dfs(TreeNode*cur)
    {
    	if (cur == NULL)
    		return;

    	dfs(cur->right);

    	cur->val += sum;
    	sum = cur->val;
    	
    	dfs(cur->left);
    }
};
