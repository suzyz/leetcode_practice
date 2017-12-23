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
	vector<TreeLinkNode *> last_node;
    void connect(TreeLinkNode *root) {
        dfs(root,0);
    }

    void dfs(TreeLinkNode *cur,int level)
    {
    	if (cur == NULL)
    		return;

    	if (last_node.size() <= level)
    	{
    		last_node.push_back(cur);
    	}
    	else
    	{
    		last_node[level]->next = cur;
    		last_node[level] = cur;
    	}

    	dfs(cur->left,level + 1);
    	dfs(cur->right,level + 1);
    }
};
