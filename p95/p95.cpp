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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return vector<TreeNode*>();
        return generate_bst(1,n);
    }

    vector<TreeNode*> generate_bst(int st,int en)
    {
        vector<TreeNode*> res;
        if (st > en)
        {
            res.push_back(NULL);
            return res;
        }

        // if (st == en)
        // {
        //     res.push_back(new TreeNode(st));
        //     return res;
        // }

        for (int i = st; i <= en; ++i)
        {
            vector<TreeNode *> left = generate_bst(st,i-1);
            vector<TreeNode *> right = generate_bst(i+1,en);

            for (int j = 0; j < left.size(); ++j)
                for (int k = 0; k < right.size(); ++k)
                {
                    TreeNode *p = new TreeNode(i);
                    p->left = left[j];
                    p->right = right[k];
                    res.push_back(p);
                }
        }

        return res;
    }
};
