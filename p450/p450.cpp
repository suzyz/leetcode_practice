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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
        	return NULL;

        if (root->val == key)
        {
        	if (root->left == NULL)
        		return root->right;
        	if (root->right == NULL)
        		return root->left;

        	TreeNode *p = root->left;
        	while (p->right != NULL)
        		p = p->right;

        	root->val = p->val;
        	root->left = deleteNode(root->left,p->val);

        	return root;
        }
        else
        if (root->val < key)
        {
        	root->right = deleteNode(root->right,key);
        	return root;
        }
        else
        {
        	root->left = deleteNode(root->left,key);
        	return root;
        }
    }
};
