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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    	vector<vector<int>> res;

        dfs(root,0,res);
        zigzag(res);
        return res;
    }

    void dfs(TreeNode *cur, int level, vector<vector<int>> &res)
    {
    	if (cur == NULL)
    		return;

    	if (level >= res.size())
    		res.push_back(vector<int>());

    	res[level].push_back(cur->val);

    	dfs(cur->left,level+1,res);
    	dfs(cur->right,level+1,res);
    }

    void zigzag(vector<vector<int>> &res)
    {
    	for (int i = 1; i < res.size(); i += 2)
    		reverse(res[i].begin(),res[i].end());
    }
};
