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
    int rob(TreeNode* root) {
    	if (root == NULL)
    		return 0;

        unordered_map<TreeNode *,int> rob_this, not_rob_this;
        rob_this[NULL] = not_rob_this[NULL] = 0;

        dfs(root,rob_this,not_rob_this);
        return max(rob_this[root], not_rob_this[root]);
    }

    void dfs(TreeNode *cur,unordered_map<TreeNode *,int> &rob_this,unordered_map<TreeNode *,int> &not_rob_this)
    {
    	if (cur->left != NULL)
    		dfs(cur->left,rob_this,not_rob_this);
    	if (cur->right != NULL)
    		dfs(cur->right,rob_this,not_rob_this);

    	rob_this[cur] = not_rob_this[cur->left] + not_rob_this[cur->right] + cur->val;
    	not_rob_this[cur] = max(rob_this[cur->left],not_rob_this[cur->left]) + max(rob_this[cur->right],not_rob_this[cur->right]);
    }
};
