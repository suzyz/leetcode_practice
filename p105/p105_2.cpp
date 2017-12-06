// DFS. O(N)

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int p = 0, i = 0;

        return build_tree(p,i,NULL,preorder,inorder);
    }

    TreeNode* build_tree(int &p,int &i,TreeNode *stop,vector<int>& preorder, vector<int>& inorder)
    {
    	if (i < inorder.size() && (stop == NULL || inorder[i] != stop->val))
        {
            TreeNode *root = new TreeNode(preorder[p]);
            ++p;
            root->left = build_tree(p,i,root,preorder,inorder);
            ++i;
            root->right = build_tree(p,i,stop,preorder,inorder);

            return root;
        }
    	else
            return NULL;
    }
};
