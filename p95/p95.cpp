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
	TreeNode *cur_root = NULL;
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        for (int i = 1; i <= n; ++i)
        {
        	TreeNode *r = new TreeNode(i);
        	cur_root = r;
        	generate_binary_trees(1,)
        }
    }


};
