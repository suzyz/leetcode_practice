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
        int n = preorder.size();

        return build_tree(0,0,n-1,preorder,inorder);
    }

    TreeNode* build_tree(int st1,int st2,int en2,vector<int>& preorder, vector<int>& inorder)
    {
    	if (st2 > en2)
    		return NULL;
    	
    	TreeNode *root = new TreeNode(preorder[st1]);
    	if (st2 == en2)
    		return root;
    	
    	for (int i = st2; i <= en2; ++i)
    		if (inorder[i] == preorder[st1])
    		{
    			root->left = build_tree(st1+1,st2,i-1,preorder,inorder);
    			root->right = build_tree(st1+1+i-st2,i+1,en2,preorder,inorder);
    			return root;
    		}
    	
    	return root;
    }
};
