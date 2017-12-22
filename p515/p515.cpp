// Iterative DFS.

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> maxv;
        vector<pair<TreeNode *,int>> st;

        if (root != NULL)
        	st.push_back(make_pair(root,0));

        while (st.size()>0)
        {
        	TreeNode *cur = st.back().first;
        	int level = st.back().second;
        	st.pop_back();

        	if (maxv.size() <= level)
        		maxv.push_back(cur->val);
        	else
        		maxv[level] = max(maxv[level],cur->val);

        	if (cur->left != NULL)
        		st.push_back(make_pair(cur->left,level+1));
        	if (cur->right != NULL)
        		st.push_back(make_pair(cur->right,level+1));
        }

        return maxv;
    }
};
