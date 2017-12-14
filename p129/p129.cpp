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
    int sumNumbers(TreeNode* root) {
        int res = 0;
        dfs(root,0,res);

        return res;
    }

    void dfs(TreeNode *cur,int pre,int &res)
    {
    	if (cur == NULL)
    		return;

    	int now = pre*10 + cur->val;
    	if (cur->left == NULL && cur->right == NULL)
    	{
    		res += now;
    		return;
    	}

    	dfs(cur->left,now,res);
    	dfs(cur->right,now,res);
    }
};
