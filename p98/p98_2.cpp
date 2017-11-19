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
        stack<TreeNode *> st;
        TreeNode *pre = NULL;
        while (root != NULL || !st.empty())
        {
            while (root != NULL)
            {
                st.push(root);
                root = root->left;
            }
            TreeNode *cur = st.top();
            st.pop();

            if (pre != NULL && cur->val <= pre->val)
                return false;

            pre = cur;
            root = cur->right;
        }
        return true;
    }
};
