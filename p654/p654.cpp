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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    	if (nums.size() == 0)
    		return NULL;

    	vector<TreeNode*> st;
        for (int i = 0; i < nums.size(); ++i)
        {
        	TreeNode *cur = new TreeNode(nums[i]);
        	while (!st.empty() && st.back()->val < nums[i])
        	{
        		cur->left = st.back();
        		st.pop_back();
        	}

        	if (!st.empty())
        		st.back()->right = cur;

        	st.push_back(cur);
        }
        return st.front();
    }
};
