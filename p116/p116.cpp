/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        vector<TreeLinkNode *> last_node;
        dfs(root,0,last_node);
    }

    void dfs(TreeLinkNode *cur,int level,vector<TreeLinkNode *> &last_node)
    {
    	if (cur == NULL)
    		return;

    	if (level >= last_node.size())
    		last_node.push_back(cur);
    	else
    	{
    		last_node[level]->next = cur;
    		last_node[level] = cur;
    	}

    	dfs(cur->left,level+1,last_node);
    	dfs(cur->right,level+1,last_node);
    }
};
