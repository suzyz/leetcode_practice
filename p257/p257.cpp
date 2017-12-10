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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        binary_tree_paths(root,"",res);
        return res;
    }
    void binary_tree_paths(TreeNode *root,string cur,vector<string> &res)
    {
    	if (root == NULL)
    		return;

		if (cur.length() > 0)
    		cur += "->";
    	cur += to_string(root->val);

    	if (root->left == NULL && root->right == NULL)
    	{
    		res.push_back(cur);
    		return;
    	}
    	if (root->left != NULL)
    		binary_tree_paths(root->left,cur,res);
    	if (root->right != NULL)
    		binary_tree_paths(root->right,cur,res);
    }
};
