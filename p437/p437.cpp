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
    int pathSum(TreeNode* root, int sum) {
    	if (root == NULL)
    		return 0;
        return pathSum(root->left,sum) + pathSum(root->right,sum) + path_sum_from_root(root,sum);
    }

    int path_sum_from_root(TreeNode *root,int sum)
    {
    	if (root == NULL)
    		return 0;
    	if (root->val == sum)
    		return 1 + path_sum_from_root(root->left,0) + path_sum_from_root(root->right,0);
    	else
    		return path_sum_from_root(root->left,sum-root->val) + path_sum_from_root(root->right,sum-root->val);
    }
};
