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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        dfs(root,0,view);
        return view;
    }

    void dfs(TreeNode *cur,int level,vector<int> &view)
    {
    	if (cur == NULL)
    		return;

    	if (level >= view.size())
    		view.push_back(cur->val);

		dfs(cur->right,level+1,view);
    	dfs(cur->left,level+1,view);
    }
};
