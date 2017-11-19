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
    bool isValidBST(TreeNode* root) {
        return is_valid_bst(root,-(((long long)1)<<32),((long long)1)<<32);
    }

    bool is_valid_bst(TreeNode *root,long long min,long long max)
    {
    	if (root == NULL)
    		return true;

    	if (root->val > max || root->val < min)
    		return false;

    	if (!is_valid_bst(root->left,min,(long long)root->val - 1))
        	return false;
        if (!is_valid_bst(root->right,(long long)root->val+1,max))
        	return false;
        return true;
    }
};
