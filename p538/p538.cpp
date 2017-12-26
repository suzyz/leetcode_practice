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
    TreeNode* convertBST(TreeNode* root) {
    	unordered_map<TreeNode*,int> old_value;

        dfs1(root,old_value);
        dfs2(root,old_value);

        return root;
    }
    void dfs1(TreeNode*cur, unordered_map<TreeNode*,int> &old_value)
    {
    	if (cur == NULL)
    		return;

    	old_value[cur] = cur->val;
    	dfs1(cur->left,old_value);
    	dfs1(cur->right,old_value);
    }

    void dfs2(TreeNode *cur,)
    {
    	if (cur == NULL)
    		return;

    	dfs3(cur->left)
    }
};
