// Pre-order traverse and reconstruct the tree.
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
    void flatten(TreeNode* root) {
    	vector<int> res;
        preorder(root,res);
        convert_to_list(root,res);
    }

    void preorder(TreeNode *root,vector<int> &res)
    {
    	if (root == NULL)
    		return;

    	res.push_back(root->val);
    	preorder(root->left,res);
    	preorder(root->right,res);
    }

    void convert_to_list(TreeNode *root,vector<int> &res)
    {
    	//TreeNode *new_root = new TreeNode(0);
    	TreeNode *p = root;
    	for (int i = 0; i < res.size(); ++i)
    	{
    		p->left = NULL;
    		p->val = res[i];
    		if (i < res.size() - 1)
    			p->right = new TreeNode(0);
    		p = p->right;
    	}
    }
};
