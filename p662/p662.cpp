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
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> l,r;
        dfs(root,0,0,false,l,r);

        int res = 0;
        for (int i = 0; i < l.size(); ++i)
        	res = max(res,r[i]-l[i]+1);
        return res;
    }

    void dfs(TreeNode *cur,int level,int fa,bool is_right_child,vector<int> &l,vector<int> &r)
    {
    	if (cur == NULL)
    		return;

    	int now = (fa<<1) + is_right_child;
    	if (level >= l.size())
    	{
    		l.push_back(now);
    		r.push_back(now);
    	}
    	else
    	{
    		l[level] = min(l[level],now);
    		r[level] = max(r[level],now);
    	}

    	dfs(cur->left,level+1,now,false,l,r);
    	dfs(cur->right,level+1,now,true,l,r);
    }
};
