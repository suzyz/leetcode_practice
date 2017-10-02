 // struct TreeNode {
 //    int val;
 //     TreeNode *left;
 //    TreeNode *right;
 //    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 // };
 
class Solution {
public:
	TreeNode *LCA;

	int dfs(TreeNode *root,TreeNode *p,TreeNode *q)
	{
		if (root == NULL)
			return 0;
		int count = 0;
		if (p == root)
			++ count;
		if (q == root)
			++ count;

		count += dfs(root->left,p,q);
		if (count == 2)
		{
			if (!LCA)
				LCA = root;
			return 2;
		}
		
		count += dfs(root->right,p,q);
		if (count == 2 && !LCA)
			LCA = root;
		return count;
	}

    TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode *p,TreeNode *q) {
    	LCA = NULL;
        dfs(root,p,q);
        return LCA;
    }
};
