// using an array to record the size of each subtree. Too slow. Not necessary.

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
    int kthSmallest(TreeNode* root, int k) {
        unordered_map<TreeNode*, int> sum;

        sum[NULL] = 0;
        dfs(root,sum);
        return search(root,k,sum);
    }

    void dfs(TreeNode *cur,unordered_map<TreeNode*, int> &sum)
    {
    	if (cur == NULL)
    		return;

    	if (cur->left)
			dfs(cur->left,sum);
		if (cur->right)
			dfs(cur->right,sum);

    	sum[cur] = 1 + sum[cur->left] + sum[cur->right];
    }

    int search(TreeNode *cur,int k,unordered_map<TreeNode*, int> &sum)
    {
    	if (sum[cur->left] >= k)
    		return search(cur->left,k,sum);

    	if (sum[cur->left]+1 == k)
    		return cur->val;
    	
    	return search(cur->right,k-sum[cur->left]-1,sum);
    }
};
