
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

        return dfs(root,k);
    }

    int dfs(TreeNode *cur,int &k)
    {
        if (cur == NULL)
            return 0;
        
        if (cur->left)
        {
            int v = dfs(cur->left,k);
            if (k <= 0)
                return v;
        }
        
        --k;
        if (k == 0)
            return cur->val;

        return dfs(cur->right,k);
    }
};
