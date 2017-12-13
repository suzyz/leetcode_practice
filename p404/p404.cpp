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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL)
        	return 0;

        int k = sumOfLeftLeaves(root->right);

        if (root->left == NULL)
        	return k;
        else
        if (root->left->left == NULL && root->left->right == NULL)
        	return k + root->left->val;
        else
        	return k + sumOfLeftLeaves(root->left);
    }
};
