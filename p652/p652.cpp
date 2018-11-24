// O(N^3). brutal..
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
	unordered_map<int, vector<TreeNode*>> nodes;
	unordered_map<TreeNode*, int> count;
	
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        dfs(root);

        vector<TreeNode*> ans;

        for (unordered_map<int, vector<TreeNode*>>::iterator it = nodes.begin();
        	it != nodes.end(); ++it)
        	if (it->second.size() > 1) {

        		vector<TreeNode*> cur = it->second;
	        	int n = cur.size();
	        	vector<int> vis(n);

	        	for (int i = 0; i < n-1; ++i)
	        		if (!vis[i]) {
		        		bool flag = false;
		        		for (int j = i+1; j < n; ++j)
		        			if (!vis[j] && check(cur[i], cur[j]))
		        					vis[j] = flag = true;

		        		if (flag)
		        			ans.push_back(cur[i]);
		        	}
	        }

	    return ans;
    }

    int dfs(TreeNode* cur) {
    	if (cur == NULL)
    		return 0;

    	count[cur] = 1 + dfs(cur->left) + dfs(cur->right);
    	nodes[count[cur]].push_back(cur);
    	return count[cur];
    }

    bool check(TreeNode* a, TreeNode* b) {
    	if (a == NULL && b == NULL)
    		return true;

    	if (a == NULL || b == NULL)
    		return false;

    	if (a->val != b->val || count[a->left] != count[b->left]
    		|| count[a->right] != count[b->right])
    		return false;

    	if (!check(a->left, b->left) || !check(a->right, b->right))
    		return false;

    	return true;
    }
};