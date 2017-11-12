// BFS

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    	vector<vector<int>> res;
    	if (root == NULL)
    		return res;

    	vector<TreeNode *> cur_level, next_level;
    	cur_level.push_back(root);
    	while (cur_level.size())
    	{
    		vector<int> tmp;
    		next_level.clear();
    		for (int i = 0; i < cur_level.size(); ++i)
    		{
    			tmp.push_back(cur_level[i]->val);
    			if (cur_level[i]->left)
    				next_level.push_back(cur_level[i]->left);
    			if (cur_level[i]->right)
    				next_level.push_back(cur_level[i]->right);
    		}
    		res.insert(res.begin(),tmp);
    		cur_level = next_level;
    	}
    	return res;
    }
};
