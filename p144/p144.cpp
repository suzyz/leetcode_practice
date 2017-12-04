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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        vector<int> res;

        if (root == NULL)
        	return res;

        st.push(root);
        while (!st.empty())
        {
        	TreeNode *cur = st.top();
        	res.push_back(cur->val);

        	st.pop();
        	if (cur->right != NULL)
        		st.push(cur->right);

        	if (cur->left != NULL)
        		st.push(cur->left);
        }

        return res;
    }
};
