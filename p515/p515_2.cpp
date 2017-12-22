// BFS.

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
        queue<TreeNode *> q;

        if (root != NULL)
        	q.push(root);

        while (!q.empty())
        {
        	int size = q.size(), cur_level_max = INT_MIN;
            while (size > 0)
            {
                --size;
                TreeNode *cur = q.front();
                q.pop();

                cur_level_max = max(cur_level_max,cur->val);

                if (cur->left != NULL)
                    q.push(cur->left);
                if (cur->right != NULL)
                    q.push(cur->right);
            }

            maxv.push_back(cur_level_max);
        }

        return maxv;
    }
};
