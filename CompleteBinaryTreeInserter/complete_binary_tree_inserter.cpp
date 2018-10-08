/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
	int levels = 0, curLevelNodes = 0;
	TreeNode *treeRoot;

    CBTInserter(TreeNode* root) {
        treeRoot = root;

        while (root != NULL) {
        	++levels;

        	root = root->left;
        }

        dfs(treeRoot, 0);
    }

    void dfs(TreeNode *p, int l) {
    	if (p == NULL)
    		return;

    	if (l == levels-1) {
    		++curLevelNodes;
    		return;
    	}

    	dfs(p->left, l+1);
    	dfs(p->right, l+1);
    }
    
    int insert(int v) {
        if (curLevelNodes == (1<<(levels-1))) {
        	TreeNode *p = treeRoot;

        	while (p->left != NULL) {
        		p = p->left;
        	}

        	p->left = new TreeNode(v);
        	++levels;
        	curLevelNodes = 1;

        	return p->val;
        }

        int parentIdx = curLevelNodes/2;

        return insert2(treeRoot, 0, parentIdx, v);
    }

    int insert2(TreeNode *root, int l, int parentIdx, int v) {
    	if (l > levels-2)
    		return -1;
    	
    	if (l == levels-2) {
    		if (root->left == NULL)
    			root->left = new TreeNode(v);
    		else
    			root->right = new TreeNode(v);

    		++curLevelNodes;

    		return root->val;
    	}

    	int h = levels-3-l;
    	int leftSum = (1<<h);

    	if (parentIdx < leftSum)
    		return insert2(root->left, l+1, parentIdx, v);
    	else
    		return insert2(root->right, l+1, parentIdx - leftSum, v);
    }
    
    TreeNode* get_root() {
        return treeRoot;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */