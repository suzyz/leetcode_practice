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
	int max_freq = 0;
	vector<int> res;
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return res;
    }

    void dfs(TreeNode *cur)
    {
    	if (cur == NULL)
    		return;

    	int freq = 1 + helper(cur->left,cur->val) + helper(cur->right,cur->val);
    	
    	if (freq > max_freq)
    	{
    		max_freq = freq;
    		res.clear();
    		res.push_back(cur->val);
    	}
    	else
    	if (freq == max_freq)
    		res.push_back(cur->val);

    	dfs(cur->left);
    	dfs(cur->right);
    }

    int helper(TreeNode *cur,int v)
    {
    	if (cur == NULL)
    		return 0;

    	if (cur->val == v)
    		return 1 + helper(cur->left,v) + helper(cur->right,v);
    	else
    	if (cur->val < v)
    		return helper(cur->right,v);
    	else
    		return helper(cur->left,v);
    }
};
