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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> average;
        if (root == NULL)
        	return average;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
        	int size = q.size();
        	double sum = 0;

        	for (int i = 0; i < size; ++i)
        	{
        		TreeNode *cur = q.front();
        		q.pop();

        		sum += cur->val;

        		if (cur->left != NULL)
        			q.push(cur->left);
        		if (cur->right != NULL)
        			q.push(cur->right);
        	}

        	average.push_back(sum/size);
        }

        return average;
    }
};
