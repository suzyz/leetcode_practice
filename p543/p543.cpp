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
	int res = 0;
	unordered_map<TreeNode *,int> via_root, not_via_root; // count the maximal number of nodes in the paths
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
        	return 0;

        via_root[root] = not_via_root[root] = 0;

        dfs(root);
        return res-1;
    }

    void dfs(TreeNode *cur)
    {
    	if (cur->left != NULL)
    		dfs(cur->left);
    	if (cur->right != NULL)
    		dfs(cur->right);

    	via_root[cur] = not_via_root[cur->left] + not_via_root[cur->right] + 1;
    	not_via_root[cur] = max(not_via_root[cur->left],not_via_root[cur->right]) + 1;

    	res = max(res,max(via_root[cur],not_via_root[cur]));
    }
};
