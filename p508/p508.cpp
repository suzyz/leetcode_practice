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
	unordered_map<int,int> freq;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);

        int max_freq = 0;
        vector<int> res;

        for (unordered_map<int,int>::iterator it = freq.begin(); it != freq.end(); ++it)
        	if (it->second > max_freq)
        	{
        		max_freq = it->second;
        		res.clear();
        		res.push_back(it->first);
        	}
        	else
        	if (it->second == max_freq)
        		res.push_back(it->first);

        return res;
    }

    int dfs(TreeNode *cur)
    {
    	if (cur == NULL)
    		return 0;

    	int sum = cur->val + dfs(cur->left) + dfs(cur->right);
    	++freq[sum];

    	return sum;
    }
};
