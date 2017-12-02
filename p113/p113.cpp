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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur;
        search(root,sum,cur,res);
        return res;
    }

    void search(TreeNode *root,int target,vector<int> &cur,vector<vector<int>> &res)
    {
    	if (root == NULL)
    		return;
    	if (root->left == NULL && root->right == NULL)
    	{
    		if (root->val == target)
    		{
    			cur.push_back(root->val);
    			res.push_back(cur);
    			cur.pop_back();
    		}
    		return;
    	}

    	cur.push_back(root->val);
    	search(root->left,target - root->val,cur,res);
    	search(root->right,target - root->val,cur,res);
    	cur.pop_back();
    }
};
