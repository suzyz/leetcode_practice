// O(N).
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
    int k = 0;
    vector<TreeNode*> ans;
	unordered_map<string, int> idx;
    unordered_map<int, int> freq;
	
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);

	    return ans;
    }

    int dfs(TreeNode* cur) {
    	if (cur == NULL)
    		return 0;

    	string s = to_string(cur->val) + "," + to_string(dfs(cur->left))
                 + "," + to_string(dfs(cur->right));

        if (!idx.count(s)) {
            ++k;
            idx[s] = k;
        }

        int i = idx[s];

        if (freq[i] == 1)
            ans.push_back(cur);

        ++freq[i];

        return i;
    }
};