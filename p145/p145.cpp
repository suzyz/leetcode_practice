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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode *,bool>> st;
        vector<int> res;

        if (root == NULL)
        	return res;

        st.push(make_pair(root,false));
        pair<TreeNode *,bool> cur;

        while (!st.empty())
        {
        	cur = st.top();

        	if (cur.second)
        	{
        		res.push_back(cur.first->val);
        		st.pop();
        	}
        	else
        	{
        		st.top().second = true;

        		if (cur.first->right != NULL)
        			st.push(make_pair(cur.first->right,false));
        		if (cur.first->left != NULL)
        			st.push(make_pair(cur.first->left,false));
        	}
        }

        return res;
    }
};
