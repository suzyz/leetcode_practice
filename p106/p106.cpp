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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i = postorder.size() - 1, p = postorder.size() - 1; // inorder and postorder

       	return build_tree(i,p,NULL,inorder,postorder);
    }

    TreeNode* build_tree(int &i,int &p,TreeNode *stop,vector<int>& inorder, vector<int>& postorder)
    {
    	if (i >= 0 && (stop == NULL || inorder[i] != stop->val))
    	{
    		TreeNode *root = new TreeNode(postorder[p]);
    		--p;

    		root->right = build_tree(i,p,root,inorder,postorder);
    		--i;
    		root->left = build_tree(i,p,stop,inorder,postorder);

    		return root;
    	}
    	else 
    		return NULL;
    }
};
